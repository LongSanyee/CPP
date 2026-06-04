#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <iostream>
#include <fstream>

class BitcoinExchange
{
public:
    std::ifstream file;
    std::map<std::string, int> data;
    BitcoinExchange(std::string f);
    int Parsedata();
};



#endif