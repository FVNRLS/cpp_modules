/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 19:02:58 by rmazurit          #+#    #+#             */
/*   Updated: 2022/12/16 19:02:58 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("Wrong animal") {
	std::cout << _type << " was created" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src) {
	std::cout << _type << " copy constructor called" << std::endl;
	*this = src;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "Wrong animal was destroyed" << std::endl;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &src) {
	this->_type = src._type;
	return (*this);
}

void WrongAnimal::make_sound() const {
	std::cout << _type << ": Some wrong animal sound..." << std::endl;
}
