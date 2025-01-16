#include "WorkOfProgram.h"

void putInTheBuffer(Buffer& buffer)
{
	while (true)
	{
		Strings str;

		std::cin >> str;
		if (std::cin.eof()) break;
		if (std::cin.fail())
		{
			std::cin.clear();
			continue;
		}
		str.transformation();
		buffer.push(str);
	}
	buffer.setEndStatus();
}

void extractFromTheBuffer(Buffer &buffer)
{
		while (!buffer.getEndStatus() || !buffer.getEmpty())
		{
			while (!buffer.getEmpty())
			{
				Strings str = buffer.pop();
				std::cout << str << std::endl;;

				int sum = str.sum_of_elements();

				client::connection(std::to_string(sum));
			}
		}
		client::connection("-1");
}

int mainWork()
{
		Buffer buffer;
		std::thread th1(putInTheBuffer, std::ref(buffer));
		std::thread th2(extractFromTheBuffer, std::ref(buffer));
		th1.join();
		th2.join();	
}