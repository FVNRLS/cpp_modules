/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 20:20:08 by rmazurit          #+#    #+#             */
/*   Updated: 2022/11/22 20:20:08 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

Account::Account( int initial_deposit ) {

}

Account::~Account() {
	return ;
}

Account::Account(void) {
	return ;
}

void	Account::makeDeposit( int deposit ) {

}

bool	Account::makeWithdrawal( int withdrawal ) {

}

int		Account::checkAmount( void ) const {

}
void	Account::displayStatus( void ) const {

}

int	Account::getNbAccounts() {
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount() {
	return (Account::_totalAmount);
}

int	Account::getNbDeposits() {
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals() {
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos() {
	Account::_displayTimestamp();
}

//PRIVATE
void	Account::_displayTimestamp( void ) {
	std::time_t	t;
	std::tm		*now;
	char		buf[19];

	t = std::time(0);
	now = std::localtime(&t);
	strftime(buf, 19, "[%Y%m%d_%H%M%S] ", now);
	std::cout << buf;
	return ;
}
