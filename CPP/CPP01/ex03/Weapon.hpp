/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rammisse <rammisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 11:48:20 by rammisse          #+#    #+#             */
/*   Updated: 2025/07/16 10:34:56 by rammisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon
{
public:
    const std::string& getType() const;
    void setType(std::string newtype);
    Weapon(std::string newtype);

private:
    std::string type;
};


#endif