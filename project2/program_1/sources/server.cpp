#include "server.h"
#include <thread>

Server::Server( int port)
{
    listener = socket(AF_INET, SOCK_STREAM, 0);
    if (listener < 0)
    {
        perror("socket");
        exit(1);
    }
    
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);

    if (bind(listener, (struct sockaddr *)&addr,sizeof(addr) ) < 0)
    {
       perror("bind");
    }

    listen(listener, 1);
}

void Server::send (std::string str)
{
    ::send(socket_, str.c_str(),str.size(),0);
}

void Server::run()
{
    socket_= accept(listener, NULL, NULL);

    std::thread reconnectionThread([&](){
        char buf[1024];
        while(true)
        {
            if (read(socket_, buf, 1023) <= 0)
            {
                close(socket_);
                socket_ = accept(listener, NULL, NULL);
            }
        }
    });
    reconnectionThread.detach();
}