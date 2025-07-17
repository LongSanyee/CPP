/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rammisse <rammisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 10:50:44 by rammisse          #+#    #+#             */
/*   Updated: 2025/07/17 14:48:32 by rammisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name)
{
    int i = 0;
    Zombie *Horde = new Zombie[N];
    while (i < N)
    {
        Horde[i] = Zombie(name);
        i++;
    }
    return (Horde);
}