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

void PmergeMe::Sortvec(std::vector<std::vector<int>> &t)
{
    if (t.size() < 2)
        return ;
    bool isodd = t.size() % 2 != 0;
    std::vector<int> straggler;
    std::vector<std::vector<int>> nextlevel;
    if (isodd)
    {
        straggler = t.back();
        t.pop_back();
    }
    for (size_t i = 0; i < t.size(); i+= 2)
    {
        
    }
}

void PmergeMe::Fordalg(std::vector<int> &v)
{
    if (v.size() < 2)
        return ;
    std::vector<std::vector<int>> arr;
    for (size_t i = 0; i < v.size(); i++)
    {
        arr.push_back({v[i]});
    }
    Sortvec(arr);
    v.clear();
    for (size_t i = 0; i < arr.size(); i++)
    {
        v.push_back(arr[i].front());
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
