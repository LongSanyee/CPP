/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rammisse <rammisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 12:38:33 by rammisse          #+#    #+#             */
/*   Updated: 2025/07/29 20:23:24 by rammisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanB
{
public:
    void attack();
    HumanB(std::string nm);
    void setWeapon(Weapon &club);
    std::string getWeapon();
private:
    std::string name;
    Weapon *weapon;

};




#endif