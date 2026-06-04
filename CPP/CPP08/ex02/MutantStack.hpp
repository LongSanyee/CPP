#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
#include <stack>


template <typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack()
	{

	}
	~MutantStack()
	{

	}
	MutantStack(const MutantStack& other) : std::stack<T>(other)
	{
		(void)other;
	}
    
	MutantStack& operator=(const MutantStack& other)
	{
		(void)other;
	}

	typedef typename std::stack<T>::container_type::iterator iterator;
	iterator begin()
	{
		return this->c.begin();
	}
	iterator end()
	{
		return this->c.end();
	}
};



#endif