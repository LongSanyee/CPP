/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rammisse <rammisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 11:51:14 by rammisse          #+#    #+#             */
/*   Updated: 2025/07/16 10:35:01 by rammisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

const std::string& Weapon::getType() const
{
    return (type);
}

void Weapon::setType(std::string newtype)
{
    type = newtype;
}

Weapon::Weapon(std::string newtype)
{
    setType(newtype);
}