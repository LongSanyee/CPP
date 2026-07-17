#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP


#include <cstdlib>
#include <sstream>
#include <string>
#include <map>
#include <iostream>
#include <iomanip>
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
        const char * what() const throw();
    };
    int isvalidformat(std::string &format);
    void ParseDB();
    int isleapyear(int y);
    int isfullmonth(int month);
    void InputValidator(std::ifstream &file);
private:
    std::map<std::string, double> map;
};


#endif