#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <list>
#include <iostream>
#include <algorithm>

class Span
{
public:
    Span();
    ~Span();
    Span(const Span& other);
    Span& operator=(const Span& other);
    Span(unsigned int n);
    void addNumber(int num);
    void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
    int shortestSpan();
    int longestSpan();
    void print();
private:
    std::vector<int> vec;
    unsigned int i;
};

class MaxElementsReached : public std::exception
{
public:
    const char *what() const throw();
};

class NotEnoughNums : public std::exception
{
public:
    const char *what() const throw();
};

#endif