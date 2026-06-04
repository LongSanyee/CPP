#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange(std::string f)
{
    file.open(f);
    if (!file.is_open())
    { 
        std::cout << "File doesnt exist !" << std::endl;
        std::exit(1);
    }
}

int BitcoinExchange::Parsedata()
{
    std::string tmp;
    while (std::getline(file, tmp))
    {
        size_t t =  tmp.find(',', 0);
        if (t == std::string::npos)
        {
            std::cout << "Error in map !" << std::endl;
            return -1;
        }
        if ((tmp[4] != '-' || tmp[7] != '-'))
        {
            std::cout << "Error in map !" << std::endl;
            return -1;
        }
    }
}