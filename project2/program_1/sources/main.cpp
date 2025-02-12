#include "input.h"
#include "buffer.h"
#include "dataProcessing.h"
#include "server.h"
#include <thread>

int main()
{
    Buffer buffer;

    Server server(52000);
    server.run();

    Input handler (buffer);
    DataProcessing bp(buffer);

    std::thread write (&Input::InputProcess, handler);
    std::thread read(&DataProcessing::outputAndSend, bp,std::ref(server));

    write.join();
    read.join();

    return 0;
}