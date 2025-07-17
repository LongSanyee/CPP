/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rammisse <rammisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 12:41:40 by rammisse          #+#    #+#             */
/*   Updated: 2025/07/16 10:47:11 by rammisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp"

void HumanA::attack()
{
    std::cout << name << " attacks with their " << weaponA.getType() << std::endl;
}


HumanA::HumanA(std::string nm, Weapon &club) : weaponA(club)
{
    name = nm;
}