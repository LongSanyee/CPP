/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rammisse <rammisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 20:53:27 by rammisse          #+#    #+#             */
/*   Updated: 2025/08/02 13:53:01 by rammisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
    Harl karen;
    (void)av;
    
    if (ac != 2)
    {
        std::cout << "Too many args !" << std::endl;
        return (-1);
    }
    karen.complain(av[1]);
    return (0);
}
