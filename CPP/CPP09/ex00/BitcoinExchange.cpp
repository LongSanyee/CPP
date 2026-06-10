#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{

}

BitcoinExchange::~BitcoinExchange()
{

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{

}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &copy)
{

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

int BitcoinExchange::isvalidformat(std::string format)
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
    long y = std::stol(format.substr(0, 4));
    long m = std::stol(format.substr(5, 2));
    long d = std::stol(format.substr(8, 2));
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

BitcoinExchange::BitcoinExchange(std::string file)
{
    std::fstream read(file);;
    if (!read.is_open())
        throw BitcoinExchange::FileErrorException();
    this->ParseDB();
}

void BitcoinExchange::ParseDB()
{
    std::fstream read("data.csv");;
    if (!read.is_open())
        throw BitcoinExchange::FileErrorException();
    std::string line;
    std::vector<std::string> arr;
    bool i = 0;
    while (std::getline(read, line))
    {
        if (i == 0){
            i = 1;
            continue;
        }
        arr = split(line, ',');
        if (arr.size() > 2 || arr.size() < 2)
        {
            std::cout << "Error: bad database" << std::endl;
            throw BitcoinExchange::FileErrorException();
        }
        if (!isvalidformat(arr[0]))
            throw BitcoinExchange::FileErrorException();
        char *endptr;
        double num = std::strtod(arr[1].c_str(), &endptr);
        if (*endptr != '\0')
            throw BitcoinExchange::FileErrorException();
        map[arr[0]] = num;
    }
}

std::vector<std::string> split(std::string t, char c)
{
    std::vector<std::string> arr;
    size_t pos = 0;
    size_t start = 0;

    while ((pos = t.find(c, start)) != std::string::npos)
    {
        arr.push_back(t.substr(start, pos - start));
        start = pos + 1;
    }
    arr.push_back(t.substr(start));
    return arr;
}