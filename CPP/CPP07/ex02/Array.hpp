#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
public:
    Array();
    ~Array();
    Array(const Array& other);
    Array& operator=(const Array& other);
    Array(unsigned int n);
    const T& operator[](unsigned int index) const;
    T& operator[](unsigned int index);
    size_t size();
    
private:
    T *arr;
    size_t length;
};


#endif