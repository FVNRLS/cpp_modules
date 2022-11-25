/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:19:42 by rmazurit          #+#    #+#             */
/*   Updated: 2022/11/25 13:19:42 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "HumanB.hpp"

HumanB::HumanB(std::string name) {
	_weapon = NULL;
	this->_name = name;
	std::cout << "Human " << "\033[1;33m" << _name << "\033[0m" << " was created" << std::endl;
}

HumanB::~HumanB() {
	std::cout << "Human " << "\033[1;33m" << _name << "\033[0m" << " was destroyed" << std::endl;
}

void HumanB::setWeapon(Weapon &weapon) {
	this->_weapon = &weapon;
}

void	HumanB::attack() {
	if (_weapon == NULL)
		std::cout << "\033[1;33m" << _name << "\033[0m" << " attacks with his teeth" << std::endl;
	else
		std::cout << "\033[1;33m" << _name << "\033[0m" << " attacks with their " << _weapon->getType() << std::endl;
}


