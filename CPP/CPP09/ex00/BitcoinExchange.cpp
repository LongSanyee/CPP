#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{

}

BitcoinExchange::~BitcoinExchange()
{

}

const char * BitcoinExchange::FileErrorException::what() const throw()
{
    return "Error: could not open file";
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
    if (this != &copy)
        this->map = copy.map;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &copy)
{
    if (this != &copy)
        this->map = copy.map;
    return *this;
}

int BitcoinExchange::isleapyear(int y)
{
    if ((y % 4 == 0 && y % 100 != 0) || (y % 4 == 0 && y % 100 == 0 && y % 400 == 0))
        return 1;
    return 0;
}

int BitcoinExchange::isfullmonth(int month)
{
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        return 1;
    return 0;
}

int BitcoinExchange::isvalidformat(std::string &format)
{
    if (format.size() != 10 || format[4] != '-' || format[7] != '-')
        return 0;
    for (int i = 0; i < 10; i++)
    {
        if (i == 4 || i == 7)
            continue;
        if (!isdigit(format[i]))
            return 0;
    }
    long y = std::strtol(format.substr(0, 4).c_str(), NULL, 10);
    long m = std::strtol(format.substr(5, 2).c_str(), NULL, 10);
    long d = std::strtol(format.substr(8, 2).c_str(), NULL, 10);
    if (m > 12 || m < 1 || d < 1)
        return 0;
    if (isfullmonth(m))
    {
        if (d > 31)
            return 0;
    }
    else if (!isfullmonth(m) && m != 2)
    {
        if (d > 30)
            return 0;
    }
    if (m == 2)
    {
        if (d > (isleapyear(y) ? 29 : 28))
            return 0;
    }
    return 1;
}

void BitcoinExchange::InputValidator(std::ifstream &file)
{
    std::string line;
    std::string date;
    std::string value;
    bool i = 0;
    while (std::getline(file, line))
    {
        if (i == 0){
            i = 1;
            if (line != "date | value")
                throw std::invalid_argument("No Header in file !");
            continue;
        }
        size_t pos = 0;
        if ((pos = line.find("|")) != std::string::npos)
        {
            if ((line[pos - 1] && line[pos - 1] != ' ') || (line[pos + 1] && line[pos + 1] != ' '))
            {
                std::cout << "Error: bad input => " << line << std::endl;
                continue;
            }
            date = line.substr(0, pos - 1);
            value = line.substr(pos + 1, line.size() - 1 - pos + 1);
        }
        else
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        if (!isvalidformat(date))
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        std::stringstream t(value);
        double num;
        t >> num;
        if (t.fail() || !t.eof() || isspace(value[1]))
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        if (num < 0 || num > 1000)
        {
            if (num < 0)
            {
                std::cout << "Error: not a positive number." << std::endl;
                continue;
            }
            else
            {
                std::cout << "Error: too large a number." << std::endl;
                continue;
            }
        }
        std::map<std::string, double>::iterator it = map.upper_bound(date);
        if (it == map.begin())
        {
            std::cout << "Error: No match for date in database" << std::endl;
            continue;
        }
        --it;
        double f = it->second;
        double res = num * f;
        std::cout << date << " => " << num << " = " << res << std::endl;
    }
}

BitcoinExchange::BitcoinExchange(std::string file)
{
    std::ifstream input(file.c_str());
    if (!input.is_open())
        throw BitcoinExchange::FileErrorException();
    this->ParseDB();
    this->InputValidator(input);
}

void BitcoinExchange::ParseDB()
{
    std::ifstream read("data.csv");
    if (!read.is_open())
        throw BitcoinExchange::FileErrorException();
    std::string line;
    std::string date;
    std::string value;
    bool i = 0;
    while (std::getline(read, line))
    {
        if (i == 0){
            i = 1;
            continue;
        }
        size_t pos = 0;
        if ((pos = line.find(",")) != std::string::npos)
        {
            date = line.substr(0, pos);
            value = line.substr(pos + 1, line.size() - 1 - pos + 1);
        }
        double num = std::strtod(value.c_str(), NULL);
        map[date] = num;
    }
}
