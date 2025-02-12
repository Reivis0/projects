#ifndef DATAPROCESSING_H
#define DATAPROCESSING_H

#include <iostream>
#include "buffer.h"
#include "server.h"

class DataProcessing
{
    Buffer &buffer;
public:
    DataProcessing (Buffer &buffer) : buffer(buffer){};
    void outputAndSend (Server &server);
};

#endif