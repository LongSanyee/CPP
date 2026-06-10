#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <iostream>

class RPN
{
public:
    RPN();
    ~RPN();
    RPN(const RPN& copy);
    RPN &operator=(const RPN& other);
private:
    std::stack<int> arr;
};



#endif