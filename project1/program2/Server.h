#ifndef SERVER_H
#define SERVER_H

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include<unistd.h>
#include<iostream>
#include"WorkOfProgram.h"

const std::string ERROR_OF_CONNECTION = "Error of connection\n";

namespace server {void connection();}

#endif