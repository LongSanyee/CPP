#include "MutantStack.hpp"

int main()
{
    MutantStack<int> mstack;
    MutantStack<std::string> test;

    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    test.push("hello");
    test.push("something");
    MutantStack<std::string> const copy = test;
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    MutantStack<std::string>::const_iterator cit = copy.begin();
    MutantStack<std::string>::const_iterator cite = copy.end();
    ++it;
    --it;
    cit++;
    cit--;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    while (cit != cite)
    {
        std::cout << *cit << std::endl;
        ++cit;
    }
    std::stack<int> s(mstack);
    return 0;

}