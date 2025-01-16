#ifndef CLIENT_H
#define CLIENT_H

#include <sys/types.h>
#include <sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include<iostream>

const std::string ERROR_OF_CONNECTION = "Error of connection\n";

namespace client {void connection(const std::string &msg);}


#endif