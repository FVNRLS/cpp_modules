/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:15:16 by rmazurit          #+#    #+#             */
/*   Updated: 2022/11/25 13:15:16 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {
	std::cout << "new zombie was created" << std::endl;
}

Zombie::~Zombie() {
	std::cout << "zombie " << _name << " was destroyed" << std::endl;
}

void	Zombie::announce() {
	std::cout << _name << ": Moar brainz!..." << std::endl;
}

void 	Zombie::set_name(std::string &name) {
	_name = name;
}
