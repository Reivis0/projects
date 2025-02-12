#include "outputData.h"

void OutputData:: processAndOutput(std::string str)
{
    std::vector<std::pair<char,int>> processing;
    std::pair<char,int> element;

    for(int i =0; i<str.length();)
    {
        if(std::isalpha(str[i])) {element.first=str[i]; ++i;}

        if(std::isdigit(str[i]))
        {
            std::string number;
            while(std::isdigit(str[i])&& i<str.length())
            {
                number+=str[i];
                ++i;
            }
            element.second=std::stoi(number);
        }
        
        processing.push_back(element);
    }

    std::sort(processing.begin(), processing.end(), 
        [](std::pair<char,int> first,std::pair<char,int> second)
        {return first.second<second.second;});
    
    for(const std::pair<char,int> el : processing)
        std::cout<<el.first;
    std::cout<<std::endl;
}