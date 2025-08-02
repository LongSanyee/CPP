
#include <iostream>
#include <string>
#include <fstream>

std::string replace(std::string filename, std::string s1, std::string s2)
{
    std::string fl;
    std::ifstream file;
    std::string real;
    std::string str;
    size_t pos;
    std::string temp;

    file.open(filename);
    if (file.fail())
    {
        std::cout << "Error opening file\n";
        std::string empty = "";
        return (empty);
    }
    while (std::getline(file, temp, '\0'))
    {
        pos = 0;
        while ((pos = temp.find(s1, pos)) != std::string::npos)
        {
            temp.erase(pos, s1.length());
            temp.insert(pos, s2);
            pos += s2.length();
        }
        str += temp;
    }
    return (str);
}


int main(int ac, char **av)
{
	std::string str;
	std::string tmp;
	std::fstream file;

	if (ac != 4)
	{
		std::cout << "Usage: <Filename> <string to replace> <the replaced string> !\n";
		return (0);
	}
	else
	{	
		tmp = av[1];
		tmp += ".replace";
		str = replace(av[1], av[2], av[3]);
        if (str.empty())
            return (0);
		file.open(tmp, std::ios::in | std::ios::out | std::ios::trunc);
        if (!file)
        {
            std::cout << "Error opening file !" << std::endl;
            return (-1);
        }
		file << str;
	}
}