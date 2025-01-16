#include "WorkOfProgram.h"

void isCorrectValue(const int value)
{
	if (value / 100 > 0 && value % 32 == 0) std::cout << value << std::endl;
	else throw(std::out_of_range(ERROR_OF_VALUE)); 
}

void mainWork()
{
	server::connection();
}