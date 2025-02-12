#include "dataProcessing.h"

void DataProcessing::outputAndSend(Server &server)
{
    while(true)
    {
        std::string data = buffer.readOnNotified();
        std::cout<<data<<std::endl;
       server.send(std::move(data));
    }
}