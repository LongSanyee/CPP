/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rammisse <rammisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 11:47:11 by rammisse          #+#    #+#             */
/*   Updated: 2025/08/02 13:52:00 by rammisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Harl.hpp"

void Harl::complain(std::string level)
{
    int i = 0;
    std::string lvl[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*funcptr[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

    while (i < 4)
    {
        if (level == lvl[i])
        {
            while (i < 4)
            {
                switch (i)
                {
                    case (0):
                        (this->*funcptr[i])();
                        break;
                    case (1):
                        (this->*funcptr[i])();
                        break ;
                    case (2):
                        (this->*funcptr[i])();
                        break ;
                    case (3):
                        (this->*funcptr[i])();
                        break ;
                }
                i++;
            }
        }
        i++;
    }
}

void Harl::debug()
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info()
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning()
{
    std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month." << std::endl;
}

void Harl::error()
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
