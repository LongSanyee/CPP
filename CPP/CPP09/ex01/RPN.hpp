#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <vector>
#include <sstream>
#include <iostream>
#include <cstdlib>

class RPN
{
public:
    RPN();
    ~RPN();
    RPN(const RPN& copy);
    RPN &operator=(const RPN& other);
    RPN(char *str);
    void doop(std::string t);
private:
    std::stack<int> arr;
};



#endif