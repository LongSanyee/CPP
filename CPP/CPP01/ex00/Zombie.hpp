/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rammisse <rammisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 09:24:14 by rammisse          #+#    #+#             */
/*   Updated: 2025/07/15 10:20:38 by rammisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
public:
    void announce(void);
    Zombie(std::string nm);
    ~Zombie();

private:
    std::string name;
};

void randomChump(std::string name);
Zombie* newZombie(std::string name);

#endif 