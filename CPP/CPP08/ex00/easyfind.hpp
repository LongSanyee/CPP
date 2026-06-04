#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
int easyfind(T& type, int i)
{

    typename T::iterator it;

    if (std::find(type.begin(), type.end(), i) != type.end())
        return 0;
    return 1;
}


#endif