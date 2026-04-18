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

template <typename T>
Array<T>::Array()
{
    length = 1;
    arr = new T[length]();
}

template <typename T>
Array<T>::~Array()
{
    delete[] arr;
}

template <typename T>
Array<T>::Array(const Array& other) : length(other.length)
{
    arr = new T[length];

    int i = 0;
    while (i < length)
    {
        arr[i] = other.arr[i];
        i++;
    }
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other)
{
    if (this != &other)
    {
        delete[] arr;
        length = other.length;
        arr = new T[length];
        int i = 0;
        while (i < length)
        {
            arr[i] = other.arr[i];
            i++;
        }
    }
    return *this;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
    length = n;
    arr = new T[n]();
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const
{
    if (index >= length)
        throw std::exception();
    return arr[index];
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
    if (index >= length)
        throw std::exception();
    return arr[index];
}

template <typename T>
size_t Array<T>::size()
{
    return length;
}

#endif