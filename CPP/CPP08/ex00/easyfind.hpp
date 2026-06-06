#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
std::string easyfind(T& type, int i)
{

    std::string tmp;
    typename T::iterator it;

    if (std::find(type.begin(), type.end(), i) != type.end())
        return tmp = "Target Found !";
    return tmp = "Target not found :(";
}


#endif