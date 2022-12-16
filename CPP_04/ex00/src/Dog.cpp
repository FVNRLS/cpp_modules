/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:07:40 by rmazurit          #+#    #+#             */
/*   Updated: 2022/12/16 17:07:40 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Dog.hpp"

Dog::Dog() : Animal() {
	_type = "Dog";
	std::cout << _type << " was created" << std::endl;
}

Dog::Dog(const Dog &src) : Animal() {
	std::cout << _type << " copy constructor called" << std::endl;
	*this = src;
}

Dog::~Dog() {
	std::cout << _type << " was destroyed" << std::endl;
}

Dog	&Dog::operator=(const Dog &src) {
	if (this == &src)
		return *this;
	_type = src._type;
	return (*this);
}

void	Dog::make_sound() const {
	std::cout << _type << ": Woof..." << std::endl;
}
