#include "PmergeMe.hpp"


int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cout << "No argument ! " << std::endl;
        return 1;
    }
    try
    {
       PmergeMe sort(av, ac);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}