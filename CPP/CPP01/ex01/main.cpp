/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rammisse <rammisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 10:49:11 by rammisse          #+#    #+#             */
/*   Updated: 2025/07/17 14:49:22 by rammisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie *horde = zombieHorde(50, "Reda");

    int i = 0;
    while (i < 50)
    {
        horde[i].announce();
        i++;
    }
    delete[] horde;
}
