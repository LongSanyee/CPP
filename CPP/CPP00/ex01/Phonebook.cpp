#include "Phonebook.hpp"

int isnotnum(int c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}

void PhoneBook::add(int index)
{
    std::string str;
    int i = 0;

    while (i < 5)
    {
        if (i == 0)
            std::cout << "Firstname: ";
        else if (i == 1)
            std::cout << "Lastname: ";
        else if (i == 2)
            std::cout << "Nickname: ";
        else if (i == 3)
            std::cout << "Phonenumber: ";
        else if (i == 4)
            std::cout << "Darkestsecret: ";
        std::getline(std::cin, str);
        if (std::cin.eof())
            exit(0);
        if ((i == 3 && !isnotnum(str[0])) || (str.empty()))
            continue;
        if (i == 0)
            this->contacts[index].setfname(str);
        else if (i == 1)
            this->contacts[index].setlname(str);
        else if (i == 2)
            this->contacts[index].setnickname(str);
        else if (i == 3)
            this->contacts[index].setphonenumber(str);
        else if (i == 4)
            this->contacts[index].setdarkest(str);
        i++;
    }
}

std::string truncate(std::string str)
{
    if (str.length() > 9)
        return (str.substr(0, 8) + ".");
    else
        return (str);
}

void PhoneBook::search()
{
    int i = 0;
    int result = 0;
    std::string str;

    std::cout << std::setw(10) << "INDEX|";
    std::cout << std::setw(10) << "First Name|";
    std::cout << std::setw(10) << "Last Name|";
    std::cout << std::setw(10) << "NickName";
    std::cout << std::endl;
    while (i < 8)
    {
        if (!contacts[i].getfname().empty())
        {
            std::cout << std::setw(10) << i << "|";
            std::cout << std::setw(10) << truncate(contacts[i].getfname()) << "|";
            std::cout << std::setw(10) << truncate(contacts[i].getlname()) << "|";
            std::cout << std::setw(10) << truncate(contacts[i].getnick());
            std::cout << std::endl;
        }
        i++;
    }
    i = 0;
    while (1)
    {
        std::cout << "Enter The Index for The Contact :";
        std::getline(std::cin, str);
        if (std::cin.eof())
            exit(0);
        if (str.length() > 2 || !isnotnum(str[0]))
        {
            std::cout << "Invalid Index!" << std::endl;
            return ;
        }
        else
        {
            result = str[0] - '0';
            std::cout << result << "\n";
            i = 0;
            while (i < 8)
            {
                if (result == i && !contacts[i].getfname().empty())
                {
                    std::cout << "FirstName: " << contacts[i].getfname() << std::endl;
                    std::cout << "LastName: " << contacts[i].getlname() << std::endl;
                    std::cout << "NickName: " << contacts[i].getnick() << std::endl;
                    std::cout << "Number: " << contacts[i].getnum() << std::endl;
                    std::cout << "DarkestSecret: " << contacts[i].getdarkest() << std::endl;
                    return ;
                }
                else
                {
                    std::cout << "Invalid Index !" << std::endl;
                    return ;
                }
                i++;
            }
        }
    }
}
