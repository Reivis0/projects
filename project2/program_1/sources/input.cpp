#include "input.h"

bool Input::isCorrect(const std::string &str) 
{
	return !str.empty()&& !(str.length()>64) && std::all_of(str.begin(), str.end(), isalpha);
}

 void Input::InputProcess()
{
	while(true)
	{
		std::string input;
		std::getline(std::cin, input);
		if(isCorrect(input))
		{
			std::string processedInput = countOfElements(std::move(input));
			buffer.writeAndNotify(std::move(processedInput));
		}
	}
}

std::string Input::countOfElements(std::string str)
{
	std::unordered_map<char, int> elementsCount;
	for(const char el: str)
		elementsCount[el]++;

	std::string res;
	for(const std::pair<char, int> el:elementsCount)
		res+=el.first+std::to_string(el.second);
	return res;
}

