/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rammisse <rammisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 16:05:29 by rammisse          #+#    #+#             */
/*   Updated: 2025/07/22 16:55:51 by rammisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <cstdlib>
#include <string>
#include <cctype>

class Contact
{
private:
    std::string fname;
    std::string lname;
    std::string nickname;
    std::string phonenumber;
    std::string darkestsecret;
public:
    void setfname(std::string Name);
    void setlname(std::string Namel);
    void setnickname(std::string Namen);
    void setphonenumber(std::string num);
    void setdarkest(std::string Dark);
    std::string getfname(void);
    std::string getlname(void);
    std::string getnick(void);
    std::string getnum(void);
    std::string getdarkest(void);
};



#endif