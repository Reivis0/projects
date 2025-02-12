#ifndef CLIENT_H
#define CLIENT_H

#include <sys/socket.h>
#include <arpa/inet.h>
#include<netinet/in.h>
#include<unistd.h>
#include<cstring>
#include<iostream>

class Client
{
std::string serverIP_;
    int serverPort_;
    int socket_;
    static const int BUFFER_SIZE = 1024;

public:
    Client(const std::string& serverIP, int serverPort): serverIP_(serverIP), serverPort_(serverPort) {} ;
    void run(void (*handler) (std::string));

private:
    bool connectToServer();
    void receiveData(void (*handler)(std::string));
};

#endif