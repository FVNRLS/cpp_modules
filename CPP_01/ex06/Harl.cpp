/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 13:35:06 by rmazurit          #+#    #+#             */
/*   Updated: 2022/11/26 13:35:06 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {
	return ;
}

Harl::~Harl() {
	return ;
}

void	Harl::debug() {
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger." << std::endl;
	std::cout << "I really do!" << std::endl;
	std::cout << std::endl;
}

void	Harl::info() {
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
	std::cout << "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
	std::cout << std::endl;
}

void	Harl::warning() {
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I've been coming for years whereas you started working here since last month." << std::endl;
	std::cout << std::endl;
}

void	Harl::error() {
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
	std::cout << std::endl;
}

void	Harl::wrong_func() {
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}

void	Harl::create_complains_list() {
	_funcs[0] = &Harl::debug;
	_funcs[1] = &Harl::info;
	_funcs[2] = &Harl::warning;
	_funcs[3] = &Harl::error;

	_complains[0] = "DEBUG";
	_complains[1] = "INFO";
	_complains[2] = "WARNING";
	_complains[3] = "ERROR";
}

void    Harl::complain(std::string level) {
	int	i;
	create_complains_list();

	i = 0;
	while (i < NUM_FUNCTIONS) {
		if (level == _complains[i])
			break ;
		i++;
	}

	switch (i)
	{
		case 4:
			wrong_func();
			break;
		case 0:
			(this->*_funcs[i])();
			i++;
		case 1:
			(this->*_funcs[i])();
			i++;
		case 2:
			(this->*_funcs[i])();
			i++;
		case 3:
			(this->*_funcs[i])();
	}
}
