﻿#include "WorkOfProgram.h"

int main()
{
	try {mainWork();}
	catch (const std::exception& ex)
	{
		std::cerr << ex.what() << std::endl;
		return EXIT_FAILURE;
	}
	
	return EXIT_SUCCESS;
}








