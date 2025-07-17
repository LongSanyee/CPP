/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rammisse <rammisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 09:24:07 by rammisse          #+#    #+#             */
/*   Updated: 2025/07/15 10:34:57 by rammisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    randomChump("Goat");
    Zombie *zom = newZombie("Fooo");
    zom->announce();
    delete zom;
    return (0);
}