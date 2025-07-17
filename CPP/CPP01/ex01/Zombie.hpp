/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rammisse <rammisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 10:49:22 by rammisse          #+#    #+#             */
/*   Updated: 2025/07/17 14:48:22 by rammisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
public:
    void announce();
    void setname(std::string nm);
    Zombie();
    Zombie(std::string name);
private:
    std::string name;
};

Zombie* zombieHorde( int N, std::string name );

#endif