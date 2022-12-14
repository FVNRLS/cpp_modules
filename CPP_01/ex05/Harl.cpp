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
	std::cout << "debugging..." << std::endl;
	std::cout << std::endl;
}

void	Harl::info() {
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "printing some info..." << std::endl;
	std::cout << std::endl;
}

void	Harl::warning() {
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "printing a warning message..." << std::endl;
	std::cout << std::endl;
}

void	Harl::error() {
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "printing a error message..." << std::endl;
	std::cout << std::endl;
}

void	Harl::wrong_func(std::string &level) {
	std::cout << "a complain " << level << " doesn't exist..." << std::endl;
	std::cout << std::endl;
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
	create_complains_list();
	for (int i = 0; i < NUM_FUNCTIONS; ++i) {
		if (_complains[i] == level) {
			(this->*_funcs[i])();
			return ;
		}
	}
	wrong_func(level);
}
