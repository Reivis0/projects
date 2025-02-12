#ifndef SERVER_H
#define SERVER_H

#include<iostream>
#include <string>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include<exception>
#include<unistd.h>

const std::string ERROR_OF_CONNECTION = "Error of connection\n";

class Server
{ 
public:
    Server (int port);
    void run();
    void send (std::string str);
private:
    int socket_;
    int listener;

};

#endif