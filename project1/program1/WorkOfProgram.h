#ifndef WORKOFPROGRAM_H
#define WORKOFPROGRAM_H


#include "Strings.h"
#include"Buffer.h"
#include<thread>
#include<exception>
#include"Client.h"


void putInTheBuffer(Buffer &buffer);
void extractFromTheBuffer(Buffer& buffer);
int mainWork();

#endif