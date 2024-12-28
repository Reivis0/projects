#include "Buffer.h"

void Buffer::setEndStatus() {	end_status = true; }

bool Buffer::getEmpty()const { return empty; }

bool Buffer::getEndStatus()const { return end_status; }

void Buffer::push(const Strings& str)
{
	qu_.push(str);
	empty = false;
}

Strings Buffer::pop()
{
	if (qu_.empty()) throw std::runtime_error(ERROR_OF_EMPTY_BUFFER);
	Strings str = qu_.front();
	qu_.pop();
	if (qu_.empty()) empty = true;
	return str;
}
