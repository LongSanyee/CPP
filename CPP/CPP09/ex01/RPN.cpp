#include "RPN.hpp"

RPN::RPN()
{

}

RPN::~RPN()
{

}

RPN::RPN(const RPN& copy)
{
    if (this != &copy)
        this->arr = copy.arr;
}

RPN& RPN::operator=(const RPN& other)
{
    if (this != &other)
        this->arr = other.arr;
    return *this;
}

int isvalid(char c)
{
    if (isdigit(c) || c == '*' || c == '/' || c == '+' || c == '-')
        return 1;
    return 0;
}

int isop(char c)
{
    if (c == '*' || c == '/' || c == '+' || c == '-')
        return 1;
    return 0;
}

void RPN::doop(std::string t)
{
    std::stringstream ss(t);
    std::string s;
    int n;
    int d;
    int res;
    while (ss >> s)
    {
        if (s.size() > 1)
            throw std::invalid_argument("Invalid Arg");
        if (!isvalid(s[0]))
            throw std::invalid_argument("Invalid Arg");
        if (isdigit(s[0]))
            arr.push(s[0] - '0');
        if (isop(s[0]))
        {
            if (arr.size() < 2)
                throw std::invalid_argument("Invalid Operation");
            else
            {
                n = arr.top();
                arr.pop();
                d = arr.top();
                arr.pop();
                switch (s[0])
                {
                    case '*':
                        res = d * n;
                        arr.push(res);
                        break;
                    case '-':
                        res = d - n;
                        arr.push(res);
                        break;
                    case '+':
                        res = d + n;
                        arr.push(res);
                        break;
                    case '/':
                        if (n == 0)
                            throw std::invalid_argument("Division by zero");
                        res = d / n;
                        arr.push(res);
                        break;
                }
            }
        }
    }
    if (arr.size() > 1)
        throw std::invalid_argument("Invalid");
    std::cout << arr.top() << std::endl;
}

RPN::RPN(char *str)
{
    doop(str);
}