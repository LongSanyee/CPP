#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{

}

PmergeMe::~PmergeMe()
{

}

PmergeMe::PmergeMe(const PmergeMe &other)
{
    if (this != &other)
    {
        this->vec = other.vec;
        this->deq = other.deq;
    }
}   

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    if (this != &other)
    {
        this->vec = other.vec;
        this->deq = other.deq;
    }
    return *this;
}

const char * PmergeMe::ParseErr::what() const throw()
{
    return "Error: Parse Error !";
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

bool cmp(const std::vector<int>& a, const std::vector<int>& b) 
{
    return a.back() < b.back();
}

bool comp(const std::deque<int>& a, const std::deque<int>& b) 
{
    return a.back() < b.back();
}

void PmergeMe::Sortvec(std::vector<std::vector<int> > &t)
{
    if (t.size() < 2)
        return ;
    bool isodd = t.size() % 2 != 0;
    std::vector<int> straggler;
    std::vector<std::vector<int> > nextlevel;
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
    std::vector<std::vector<int> > mainchain;
    std::vector<std::vector<int> > pend;
    for (size_t i = 0; i < nextlevel.size(); i++)
    {
        size_t half = nextlevel[i].size() / 2;
        std::vector<int> loser(nextlevel[i].begin(), nextlevel[i].begin() + half);
        std::vector<int> winner(nextlevel[i].begin() + half, nextlevel[i].end());
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
    if (pend.empty()) 
    {
        t = mainchain;
        return;
    }
    std::vector<size_t> jacob;
    jacob.push_back(0);
    jacob.push_back(1);
    size_t idx = 2;
    while (true)
    {
        jacob.push_back(jacob[idx - 1] + 2 * jacob[idx - 2]);
        if (jacob.back() > pend.size()) 
            break;
        idx++;
    }
    std::vector<size_t> tracker(pend.size());
    for (size_t i = 0; i < pend.size(); i++)
        tracker[i] = i + 2;
    for (size_t i = 3; i < jacob.size(); i++)
    {
        int start = jacob[i] - 2;
        int end = jacob[i - 1] - 1;
        if (start >= static_cast<int>(pend.size()))
            start = pend.size() - 1;
        while (start >= end)
        {
            std::vector<std::vector<int> >::iterator it = mainchain.end();
            if (!(isodd && start == static_cast<int>(pend.size() - 1)))
                it = mainchain.begin() + tracker[start];
            std::vector<std::vector<int> >::iterator insert;
            insert = std::upper_bound(mainchain.begin(), it, pend[start], cmp);
            size_t dist = std::distance(mainchain.begin(), insert);
            mainchain.insert(insert, pend[start]);
            for (size_t k = 0; k < tracker.size(); k++)
            {
                if (tracker[k] >= dist)
                    tracker[k]++;
            }
            start--;
        }
    }
    t = mainchain;
}

void PmergeMe::Sortdeq(std::deque<std::deque<int> > &t)
{
    if (t.size() < 2)
        return ;
    bool isodd = t.size() % 2 != 0;
    std::deque<int> straggler;
    std::deque<std::deque<int> > nextlevel;
    if (isodd)
    {
        straggler = t.back();
        t.pop_back();
    }
    for (size_t i = 0; i < t.size(); i += 2)
    {
        if (t[i].back() > t[i + 1].back())
        {
            std::deque<int> combined = t[i + 1];
            combined.insert(combined.end(), t[i].begin(), t[i].end());
            nextlevel.push_back(combined);
        }
        else
        {
            std::deque<int> combined = t[i];
            combined.insert(combined.end(), t[i + 1].begin(), t[i + 1].end());
            nextlevel.push_back(combined);
        }
    }
    Sortdeq(nextlevel);
    std::deque<std::deque<int> > mainchain;
    std::deque<std::deque<int> > pend;
    for (size_t i = 0; i < nextlevel.size(); i++)
    {
        size_t half = nextlevel[i].size() / 2;
        std::deque<int> loser(nextlevel[i].begin(), nextlevel[i].begin() + half);
        std::deque<int> winner(nextlevel[i].begin() + half, nextlevel[i].end());
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
    if (pend.empty()) 
    {
        t = mainchain;
        return;
    }
    std::deque<size_t> jacob;
    jacob.push_back(0);
    jacob.push_back(1);
    size_t idx = 2;
    while (true)
    {
        jacob.push_back(jacob[idx - 1] + 2 * jacob[idx - 2]);
        if (jacob.back() > pend.size()) 
            break;
        idx++;
    }
    std::deque<size_t> tracker(pend.size());
    for (size_t i = 0; i < pend.size(); i++)
        tracker[i] = i + 2;
    for (size_t i = 3; i < jacob.size(); i++)
    {
        int start = jacob[i] - 2;
        int end = jacob[i - 1] - 1;
        if (start >= static_cast<int>(pend.size()))
            start = pend.size() - 1;
        while (start >= end)
        {
            std::deque<std::deque<int> >::iterator it = mainchain.end();
            if (!(isodd && start == static_cast<int>(pend.size() - 1)))
                it = mainchain.begin() + tracker[start];
            std::deque<std::deque<int> >::iterator insert;
            insert = std::upper_bound(mainchain.begin(), it, pend[start], comp);
            size_t dist = std::distance(mainchain.begin(), insert);
            mainchain.insert(insert, pend[start]);
            for (size_t k = 0; k < tracker.size(); k++)
            {
                if (tracker[k] >= dist) 
                    tracker[k]++;
            }
            start--;
        }
    }
    t = mainchain;
}

void PmergeMe::Fordalg(std::vector<int> &v)
{
    if (v.size() < 2)
        return ;
    std::vector<std::vector<int> > arr;
    for (size_t i = 0; i < v.size(); i++)
    {
        std::vector<int> tmp;
        tmp.push_back(v[i]);
        arr.push_back(tmp);
        tmp.clear();
    }
    Sortvec(arr);
    v.clear();
    for (size_t i = 0; i < arr.size(); i++)
    {
        v.push_back(arr[i].front());
    }
}



void PmergeMe::Fordalg(std::deque<int> &t)
{
    if (t.size() < 2)
        return ;
    std::deque<std::deque<int> > arr;
    for (size_t i = 0; i < t.size(); i++)
    {
        std::deque<int> tmp;
        tmp.push_back(t[i]);
        arr.push_back(tmp);
        tmp.clear();
    }
    Sortdeq(arr);
    t.clear();
    for (size_t i = 0; i < arr.size(); i++)
    {
        t.push_back(arr[i].front());
    }
}

void PmergeMe::printvec()
{
    for (size_t i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

PmergeMe::PmergeMe(char **argv, int ac)
{
    std::set<int> duplicate;
    int i = 1;
    while (argv[i])
    {
        if (!valid(argv[i]))
            throw ParseErr();
        std::string tmp = argv[i];
        if (tmp.empty())
            throw ParseErr();
        long num = std::strtol(argv[i], NULL, 10);
        if (num < 0 || num > __INT_MAX__)
            throw ParseErr();
        if (!duplicate.insert(static_cast<int>(num)).second)
            throw ParseErr();
        i++;
    }
    clock_t start = clock();
    for (int i = 1; i < ac; i++)
    {
        long num = std::strtol(argv[i], NULL, 10);
        vec.push_back(static_cast<int>(num));
    }
    std::cout << "Before : ";
    printvec();
    Fordalg(vec);
    clock_t end = clock();
    double duration_us = (static_cast<double>(end - start) / CLOCKS_PER_SEC) * 1000000;
    std::cout << "After : ";
    printvec();
    std::cout << "Time to process a range of " << vec.size() 
    << " elements with std::vector : " << std::fixed << std::setprecision(5) << duration_us << " us\n";
    start = clock();
    for (int i = 1; i < ac; i++)
    {
        long num = std::strtol(argv[i], NULL, 10);
        deq.push_back(static_cast<int>(num));
    }
    Fordalg(deq);
    end = clock();
    duration_us = (static_cast<double>(end - start) / CLOCKS_PER_SEC) * 1000000;
    std::cout << "Time to process a range of " << vec.size() 
          << " elements with std::deque : " << std::fixed << std::setprecision(5) << duration_us << " us\n";
}
