#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <ctime>
#include <string>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <deque>
#include <set>

class PmergeMe
{
public:
    PmergeMe();
    ~PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe& other);
    PmergeMe(char **argv, int ac);
    class ParseErr : public std::exception
    {
        const char * what() const throw();
    };
    void Fordalg(std::vector<int> &v);
    void printvec();
    void Fordalg(std::deque<int> &t);
private:
    std::vector<int> vec;
    std::deque<int> deq;
    void Sortvec(std::vector<std::vector<int> > &t);
    void Sortdeq(std::deque<std::deque<int> > &t);
};


#endif