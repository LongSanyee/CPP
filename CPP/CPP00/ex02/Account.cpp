/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rammisse <rammisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 19:44:00 by rammisse          #+#    #+#             */
/*   Updated: 2025/07/11 11:48:29 by rammisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

int	Account::getNbAccounts(void)
{
    return (_nbAccounts);
}

int	Account::getTotalAmount(void)
{
    return (_totalAmount);
}

int	Account::getNbDeposits(void)
{
    return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
    return (_totalNbWithdrawals);
}

int		Account::checkAmount(void) const
{
    return (_amount);
}

bool	Account::makeWithdrawal(int withdrawal)
{
    if (_amount < withdrawal)
        std::cout << "";
    else
        std::cout << "";
}

void	Account::makeDeposit(int deposit)
{
    _totalNbDeposits += deposit;
}

Account::Account(int initial_deposit)
{
    
}
void	Account::displayAccountsInfos(void)
{
    
}

Account::~Account(void)
{
    
}