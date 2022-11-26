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
	return;
}

Harl::~Harl() {

}

void Harl::debug() {
	std::cout << "debugging..." << std::endl;
}

void Harl::info() {
	std::cout << "printing some info..." << std::endl;
}

void Harl::warning() {
	std::cout << "warning message..." << std::endl;
}

void Harl::error() {
	std::cout << "error message..." << std::endl;
}

void    Harl::complain(std::string level) {
	switch (level == "DEBUG") {

	} ()
}






