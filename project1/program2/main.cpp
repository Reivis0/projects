#include "WorkOfProgram.h"

int main()
{
	try {mainWork();}
	catch(std::exception &ex)
	{
		std::cout<<ex.what()<<std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}