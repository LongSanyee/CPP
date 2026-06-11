#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <vector>
#include <sstream>
#include <iostream>

class RPN
{
public:
    RPN();
    ~RPN();
    RPN(const RPN& copy);
    RPN &operator=(const RPN& other);
    RPN(char *str);
    std::vector<std::string> split(std::string t, char c);
private:
    std::stack<int> arr;
};



#endif