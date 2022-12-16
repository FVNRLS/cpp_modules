/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:08:26 by rmazurit          #+#    #+#             */
/*   Updated: 2022/12/16 17:08:26 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Cat.hpp"

Cat::Cat() : Animal() {
	_type = "Cat";
	std::cout << _type << " was created" << std::endl;
}

Cat::Cat(const Cat &src) : Animal() {
	std::cout << _type << " copy constructor called" << std::endl;
	*this = src;
}

Cat::~Cat() {
	std::cout << _type << " was destroyed" << std::endl;
}

Cat	&Cat::operator=(const Cat &src) {
	this->_type = src._type;
	return (*this);
}

void Cat::make_sound() const {
	std::cout << _type << ": Meeeeeaaaaow..." << std::endl;
}
