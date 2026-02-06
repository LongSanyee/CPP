#include "Span.hpp"

Span::Span()
{

}

Span::~Span()
{

}

Span::Span(const Span& other)
{
    *this = other;
}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        this->i = other.i;
        this->vec = other.vec;
    }
    return *this;
}

Span::Span(unsigned int n) : i(n)
{

}

const char *MaxElementsReached::what() const throw()
{
    return "Max Elements Reached !";
}

const char *NotEnoughNums::what() const throw()
{
    return "Not Enough Numbers !";
}

void Span::addNumber(int num)
{
    if (vec.size() >= i)
        throw MaxElementsReached();
    vec.push_back(num);
}

int Span::shortestSpan()
{
    if (vec.size() < 2)
        throw NotEnoughNums();
    std::vector<int> copy = vec;
    std::sort(copy.begin(), copy.end());
    int smallest = copy[1] - copy[0];
    int diff = 0;
    for (int i = 1; i < copy.size(); i++)
    {
        diff = copy[i] - copy[i - 1];
        if (diff < smallest)
            smallest = diff;
    }
    return smallest;
}

int Span::longestSpan()
{
    if (vec.size() < 2)
        throw NotEnoughNums();
    int i = 0;
    int smallest = vec[0];
    int biggest = vec[0];
    while (i < vec.size())
    {
        if (vec[i] < smallest)
            smallest = vec[i];
        if (vec[i] > biggest)
            biggest = vec[i];
        i++;
    }
    return biggest - smallest;
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    if (vec.size() + std::distance(begin, end) > i)
        throw MaxElementsReached();
    vec.insert(vec.end(), begin, end);
}

void Span::print()
{
    std::vector<int>::iterator it = vec.begin();
    while (it < vec.end())
    {
        std::cout << *it << std::endl;
        it++;
    }
}