/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:18:39 by rmazurit          #+#    #+#             */
/*   Updated: 2022/11/25 13:18:39 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _weapon(weapon){
	this->_name = name;
	std::cout << "Human " << "\033[1;32m" << _name << "\033[0m" << " was created with " << _weapon.getType() << std::endl;
}

HumanA::~HumanA() {
	std::cout << "Human " << "\033[1;32m" << _name << "\033[0m" << " was destroyed" << std::endl;
	return ;
}

void	HumanA::attack() {
	std::cout << "\033[1;32m" << _name << "\033[0m" << " attacks with their " << _weapon.getType()  << std::endl;
}
