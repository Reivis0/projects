#ifndef BUFFER_H
#define BUFFER_H
#include <mutex>
#include <condition_variable>
#include<string>

class Buffer : private std::mutex, private std::condition_variable
{
    bool newData;
    std::string buffer;

public:
    Buffer() : newData(false) {}
    void writeAndNotify(std::string data);
    std::string readOnNotified();
};

#endif