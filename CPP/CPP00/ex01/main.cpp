#include "Phonebook.hpp"

int main()
{
    PhoneBook book; 
    int index;
    std::string str;

    index = 0;
    while (1)
    {
        std::cout << "Input Your Desired COMMAND:" << std::endl;
        std::cout << "-ADD" << std::endl;
        std::cout << "-SEARCH" << std::endl;
        std::cout << "-EXIT" << std::endl;
        std::cout << "$<";
        std::getline(std::cin, str);
        if (std::cin.eof())
            break;
        if (str == "EXIT")
            break ;
        else if (str == "ADD")
        {
            book.add(book, index);
            index++;
        }
        if (index == 8)
            index = 0;
        if (str == "SEARCH")
            book.search(book);
    }
}
