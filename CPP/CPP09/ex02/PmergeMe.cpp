#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{

}

PmergeMe::~PmergeMe()
{

}

PmergeMe::PmergeMe(const PmergeMe &other)
{

}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{

}

int valid(char *c)
{
    int i = 0;
    while (c[i])
    {
        if (!isdigit(c[i]))
            return 0;
        i++;
    }
    return 1;
}

std::vector<int> jacobsthal(int size)
{
    std::vector<int> seq;
    int prev = 0; 
    int curr = 1; 
    int next = 0;
    while (next < size)
    {
        next = curr + 2 * prev;
        if (next > 1)
        {
            if (next > size)
                seq.push_back(size);
            else
                seq.push_back(next);
        }
        prev = curr;
        curr = next;
    }
    return seq;
}

void PmergeMe::Fordalg(std::vector<int> &v)
{
    if (v.size() < 2)
        return ;
    int straggler = 0;
    bool isodd = v.size() % 2 != 0;
    if (isodd)
    {
        straggler = v.back();
        v.pop_back();
    }
    int i = 0;
    std::vector<std::pair<int, int>> pairs;
    std::vector<int> winners;
    while (i < v.size())
    {
        std::pair<int, int> tmp;
        if (v[i] > v[i + 1])
        {
            tmp = std::make_pair(v[i], v[i + 1]);
            pairs.push_back(tmp);
        }
        else
        {
            tmp = std::make_pair(v[i + 1], v[i]);
            pairs.push_back(tmp);
        }
        winners.push_back(tmp.first);
        i += 2;
    }
}

void PmergeMe::Fordalg(std::deque<int> &d)
{

}

PmergeMe::PmergeMe(char **argv)
{
    int i = 1;
    char *endptr;
    while (argv[i])
    {
        if (!valid(argv[i]))
            throw ParseErr();
        std::string tmp = argv[i];
        if (tmp.empty())
            throw ParseErr();
        long num = std::strtol(argv[i], &endptr, 10);
        if (num < 0 || num > __INT_MAX__)
            throw ParseErr();
        vec.push_back(static_cast<int>(num));
        deq.push_back(static_cast<int>(num));
        i++;
    }
}
