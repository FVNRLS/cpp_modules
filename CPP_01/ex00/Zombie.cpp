/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:16:21 by rmazurit          #+#    #+#             */
/*   Updated: 2022/11/25 13:16:21 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string &name) {
	_name = name;
	std::cout << "zombie " << _name << " was created" << std::endl;
}

Zombie::~Zombie() {
	std::cout << "zombie " << _name << " was destroyed" << std::endl;
}

void	Zombie::announce() {
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}