#include "BitcoinExchange.hpp"


int main(int ac, char **av)
{
    if (ac != 2)
        return std::cout << "Error: could not open file" << std::endl, 1;
    try
    {
        BitcoinExchange var(av[1]);
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

}