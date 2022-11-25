/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:17:05 by rmazurit          #+#    #+#             */
/*   Updated: 2022/11/25 13:17:05 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string &type) {
	setType(type);
	std::cout << "\033[1;31mWeapon\033[0m " << _type << " was created" << std::endl;
}

Weapon::~Weapon() {
	std::cout << "\033[1;31mWeapon\033[0m " << _type << " was destroyed" << std::endl;
}

std::string Weapon::getType() const {
	return (_type);
}

void	Weapon::setType(const std::string &type) {
	_type = type;
}
