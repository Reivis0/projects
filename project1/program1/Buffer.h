#ifndef BUFFER_H
#define BUFFER_H

#include<queue>
#include"Strings.h"

const std::string ERROR_OF_EMPTY_BUFFER = "Buffer is empty";

class Buffer
{
public:
	Buffer() : empty(true), end_status(false) {};
	void setEndStatus();
	bool getEmpty()const;
	bool getEndStatus()const;
	void push(const Strings& str);
	Strings pop();

private:
	std::queue<Strings> qu_;
	bool empty;
	bool end_status;
};

#endif
