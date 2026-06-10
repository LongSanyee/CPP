#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP


#include <cstdlib>
#include <vector>
#include <map>
#include <iostream>
#include <fstream>

class BitcoinExchange
{
public:
    BitcoinExchange();
    ~BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &copy);
    BitcoinExchange& operator=(const BitcoinExchange &copy);
    BitcoinExchange(std::string file);
    class FileErrorException : public std::exception
    {
        const char * what() const throw()
        {
            return "Error: could not open file";
        }
    };
    int isvalidformat(std::string format);
    void ParseDB();
    int isleapyear(int y);
    int isfullmonth(int month);
private:
    std::map<std::string, double> map;
};


#endif