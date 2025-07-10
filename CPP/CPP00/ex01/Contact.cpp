/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rammisse <rammisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 16:07:20 by rammisse          #+#    #+#             */
/*   Updated: 2025/07/10 19:37:04 by rammisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::setfname(std::string Name)
{
    fname = Name;
}

void Contact::setlname(std::string Namel)
{
    lname = Namel;
}

void Contact::setnickname(std::string Namen)
{
    nickname = Namen;
}

void Contact::setphonenumber(std::string num)
{
    phonenumber = num;
}

void Contact::setdarkest(std::string Dark)
{
    darkestsecret = Dark;
}

std::string Contact::getfname(void)
{
    return (fname);
}

std::string Contact::getlname(void)
{
    return (lname);
}

std::string Contact::getnick(void)
{
    return (nickname);
}

std::string Contact::getnum(void)
{
    return (phonenumber);
}

std::string Contact::getdarkest(void)
{
    return (darkestsecret);
}
