#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void func(T &c)
{
    c += 1;
}

template <typename T>
void print(T &c)
{
    std::cout << c;
}

template <typename T, typename T1>
void iter(T *arr, const size_t size , T1 func)
{
    if (!arr || !func)
        return ;
    for (size_t i = 0;i < size; i++)
    {
        func(arr[i]);
    }
}

#endif