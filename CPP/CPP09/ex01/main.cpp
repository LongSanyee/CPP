#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
        return 1;
    
    try{

        RPN v(av[1]);
    }
    catch(...)
    {
        std::cout << "error" << std::endl;
    }
}