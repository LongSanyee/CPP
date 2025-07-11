/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rammisse <rammisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 10:54:20 by rammisse          #+#    #+#             */
/*   Updated: 2025/07/11 13:38:27 by rammisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include "Contact.hpp"

class PhoneBook
{
public:
    Contact contacts[8];
    void search(PhoneBook& Phone);
    void add(PhoneBook& book, int& index);
};


#endif