#ifndef STRINGS_H
#define STRINGS_H

#define MAX_SIZE_OF_STR 64

#include <iostream>
#include <string>
#include<algorithm>
#include<numeric>

class Strings
{
public:
	friend std::istream& operator >> (std::istream& input, Strings& str);
	friend std::ostream& operator << (std::ostream& output, const Strings& str);
	void transformation();
	int sum_of_elements()const;

private:
	std::string str_;
};

#endif 
