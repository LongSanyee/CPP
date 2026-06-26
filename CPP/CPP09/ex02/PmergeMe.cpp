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

std::vector<size_t> jacobsthal(int size)
{
    std::vector<size_t> seq;
    seq.push_back(0);
    seq.push_back(1);
    while (seq.size() < size)
    {
        size_t next = seq[seq.size() - 1] + 2 * seq[seq.size() - 2];
        seq.push_back(next);
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
    for (size_t i = 0; i < t.size(); i += 2)
    {
        if (t[i].back() > t[i + 1].back())
        {
            std::vector<int> combined = t[i + 1];
            combined.insert(combined.end(), t[i].begin(), t[i].end());
            nextlevel.push_back(combined);
        }
        else
        {
            std::vector<int> combined = t[i];
            combined.insert(combined.end(), t[i + 1].begin(), t[i + 1].end());
            nextlevel.push_back(combined);
        }
    }
    Sortvec(nextlevel);
    std::vector<std::vector<int>> mainchain;
    std::vector<std::vector<int>> pend;
    for (size_t i = 0; i < nextlevel.size(); i++)
    {
        size_t half = nextlevel[i].size() / 2;
        std::vector<int> winner(nextlevel[i].begin(), nextlevel[i].begin() + half);
        std::vector<int> loser(nextlevel[i].begin() + half, nextlevel[i].end());
        if (i == 0)
        {
            mainchain.push_back(loser);
            mainchain.push_back(winner);
        }
        else
        {
            pend.push_back(loser);
            mainchain.push_back(winner);
        }
    }
    if (isodd)
        pend.push_back(straggler);
    std::vector<size_t> jacob = jacobsthal(pend.size() - 1);
    std::vector<std::vector<int>> fakechain = mainchain;
    for (size_t i = 0; i < jacob.size(); i++)
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
