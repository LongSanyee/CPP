#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{

}

BitcoinExchange::~BitcoinExchange()
{

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
    (void)copy;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &copy)
{
    (void)copy;
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
    std::vector<std::string> arr;
    bool i = 0;
    while (std::getline(file, line))
    {
        if (i == 0){
            i = 1;
            continue;
        }
        arr = split(line, '|');
        if (arr.empty())
            continue;
        if (arr.size() > 2 || arr.size() < 2)
        {
            if (arr.size() > 2)
                std::cout << "Error: bad input => " << arr[2] << std::endl;
            else if (arr.size() == 1)
                std::cout << "Error: bad input => " << arr[0] << std::endl;
            continue;
        }
        size_t last = arr[0].find_last_not_of(" \t\r\n");
        if (last != std::string::npos) 
            arr[0] = arr[0].substr(0, last + 1);
        if (!isvalidformat(arr[0]))
        {
            std::cout << "Error: bad input => " << arr[0] << std::endl;
            continue;
        }
        char *endptr;
        double num = std::strtod(arr[1].c_str(), &endptr);
        if (endptr == arr[1].c_str())
        {
            std::cout << "Error: bad input => " << arr[1] << std::endl;
            continue;
        }
        while (*endptr != '\0' && std::isspace(*endptr))
            endptr++;
        if (num < 0)
        {
            std::cout << "Error: not a positive number." << std::endl;
            continue;
        }
        if ((num > 1000 || num < 0))
        {
            std::cout << "Error: too large a number." << std::endl;
            continue;
        }
        if (*endptr != '\0')
        {
            std::cout << "Error: bad input => " << arr[1] << std::endl;
            continue;
        }
        std::map<std::string, double>::iterator it = map.lower_bound(arr[0]);
        if (it == map.begin())
        {
            std::cout << "Error: No match for date in database" << std::endl;
            continue;
        }
        --it;
        double f = it->second;
        double res = num * f;
        std::cout << arr[0] << " => " << num << " = " << res << std::endl;
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
    std::ifstream read("data.csv");;
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
        if (num < 0 || errno == ERANGE)
        {
            std::cout << "Error: database value overflow" << std::endl;
            throw BitcoinExchange::FileErrorException();
        }
        map[arr[0]] = num;
    }
}

std::vector<std::string> BitcoinExchange::split(std::string t, char c)
{
    std::vector<std::string> arr;
    size_t pos = 0;
    size_t start = 0;

    while ((pos = t.find(c, start)) != std::string::npos)
    {
        if (pos - start > 0)
            arr.push_back(t.substr(start, pos - start));
        start = pos + 1;
    }
    std::string tmp = t.substr(start);
    if (!tmp.empty())
        arr.push_back(t.substr(start));
    return arr;
}