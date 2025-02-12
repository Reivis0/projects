#include"buffer.h"

void Buffer::writeAndNotify(std::string data)
{
    std::unique_lock<std::mutex> lock(*this);
    buffer = std::move(data);
    newData = true;
    lock.unlock();
    notify_all();
}

std::string Buffer::readOnNotified()
{
    std::unique_lock<std::mutex> lock(*this);
    wait(lock, [this]{ return newData; });
    std::string bufferData = std::move(buffer);
    buffer.clear();
    newData = false;
    lock.unlock();
    return bufferData;
}