/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rammisse <rammisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 10:54:20 by rammisse          #+#    #+#             */
/*   Updated: 2025/07/28 09:49:03 by rammisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <cctype>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include "Contact.hpp"

class PhoneBook
{
private:
    Contact contacts[8];
public:
    void search();
    void add(int index);
};


#endif