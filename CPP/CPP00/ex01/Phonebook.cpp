#include "Phonebook.hpp"

int isnotnum(std::string tmp)
{
    int i;

    i = 0;
    while (tmp[i])
    {
        if (!(tmp[i] >= '0' && tmp[i] <= '9'))
            return (0);
        i++;
    }
    return (1);
}

void PhoneBook::add(PhoneBook& book, int& index)
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
        if ((i == 3 && !isnotnum(str)) || str.empty())
            continue;
        if (i == 0)
            book.contacts[index].setfname(str);
        else if (i == 1)
            book.contacts[index].setlname(str);
        else if (i == 2)
            book.contacts[index].setnickname(str);
        else if (i == 3)
            book.contacts[index].setphonenumber(str);
        else if (i == 4)
            book.contacts[index].setdarkest(str);
        i++;
    }
}

std::string truncate(std::string str)
{
    if (str.length() > 9)
        return str.substr(0, 8) + ".";
    else
        return (str);
}

void PhoneBook::search(PhoneBook& Phone)
{
    int i = 0;
    int result = 0;
    std::string str;

    std::cout << std::setw(10) <<"INDEX|";
    std::cout << std::setw(10) <<"First Name|";
    std::cout << std::setw(10) <<"Last Name|";
    std::cout << std::setw(10) <<"NickName";
    std::cout << std::endl;
    while (i < 8)
    {
        if (!Phone.contacts[i].getfname().empty())
        {
            std::cout << std::setw(10) << i << "|";
            std::cout << std::setw(10) << truncate(Phone.contacts[i].getfname()) << "|";
            std::cout << std::setw(10) << truncate(Phone.contacts[i].getlname()) << "|";
            std::cout << std::setw(10) << truncate(Phone.contacts[i].getnick());
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
        result = std::atoi(str.c_str());
        if (!isnotnum(str) || (result > 7 || result < 0))
        {
            std::cout << "Invalid Index !" << std::endl;
            continue;
        }
        else
        {
            while (i < 8)
            {
                if (result == i)
                {
                    std::cout << "FirstName: " << Phone.contacts[i].getfname() << std::endl;
                    std::cout << "LastName: " << Phone.contacts[i].getlname() << std::endl;
                    std::cout << "NickName: " << Phone.contacts[i].getnick() << std::endl;
                    std::cout << "Number: " << Phone.contacts[i].getnum() << std::endl;
                    std::cout << "DarkestSecret: " << Phone.contacts[i].getdarkest() << std::endl;
                    return ;
                }
                i++;
            }
        }
    }
}
