#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <queue>

class PmergeMe
{
public:
    PmergeMe();
    ~PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe& other);
    PmergeMe(char **argv);

    class ParseErr : public std::exception
    {
        const char * what() const throw()
        {
            return "Error: Parse Error !";
        }
    };
    void Fordalg(std::vector<int> &v);
    void Fordalg(std::deque<int> &t);
private:
    std::vector<int> vec;
    std::deque<int> deq;
    void Sortvec(std::vector<std::vector<int> > &t);
    void Sortdeq(std::deque<std::deque<int> > &t);
};


#endif