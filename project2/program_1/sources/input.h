#ifndef INPUT_H
#define INPUT_H

#include <iostream>
#include <string>
#include<algorithm>
#include<unordered_map>
#include"buffer.h"

class Input
{
	Buffer &buffer;
public:
	Input(Buffer &buffer) : buffer(buffer) {};
	void InputProcess();
private:
	bool isCorrect(const std::string &str);
	std::string countOfElements(std::string str);
};

#endif
