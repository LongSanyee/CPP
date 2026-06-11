#include "RPN.hpp"

RPN::RPN()
{

}

RPN::~RPN()
{

}

// RPN::RPN(const RPN& copy)
// {

// }

// RPN& RPN::operator=(const RPN& other)
// {

// }

int isvalid(char c)
{
    
}

RPN::RPN(char *str)
{
    std::stringstream ss(str);
    std::string s;

    while (ss >> s)
    {
        if (s.size() > 1)
            throw std::invalid_argument("Invalid Number");
        if ()
    }

}