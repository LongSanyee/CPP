/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rammisse <rammisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 12:40:36 by rammisse          #+#    #+#             */
/*   Updated: 2025/07/29 20:23:36 by rammisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

std::string HumanB::getWeapon()
{
    return (weapon->getType());
}

void HumanB::attack()
{
    std::cout << name << " attacks with their " << getWeapon() << std::endl;
}

HumanB::HumanB(std::string nm)
{
    name = nm;
}

void HumanB::setWeapon(Weapon &club)
{
    weapon = &club;
}

