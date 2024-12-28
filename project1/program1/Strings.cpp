#include "Strings.h"

std::istream& operator>>(std::istream& input, Strings& str)
{
	std::istream::sentry sentry(input);
	if (!sentry)
		return input;

	std::string n_str;
	std::getline(input, n_str);

	if (n_str.length() > 64)
	{
		input.setstate(std::ios::failbit);
		return input;
	}

	for (const char el : n_str)
		if (!isdigit(el))
		{
			input.setstate(std::ios::failbit);
			return input;
		}

	str.str_ = n_str;
	return input;
}
std::ostream& operator<<(std::ostream& output, const Strings& str)
{
	std::ostream::sentry sentry(output);
	if (!sentry)
		return output;
	output << str.str_;
	return output;
};

void Strings::transformation()
{
	std::sort(str_.begin(), str_.end(), [](char el1, char el2) {return el1 > el2; });
	std::string result = "";
	for (const char el : str_)
		((el - '0') % 2 == 0) ? result += "KB" : result += el;
	str_ = result;
}
int Strings::sum_of_elements()const
{
	auto sum = [](int value, char el) { return isdigit(el) ? value + (int)(el - '0') : value; };
	return std::accumulate(str_.begin(), str_.end(), 0, sum);
};
