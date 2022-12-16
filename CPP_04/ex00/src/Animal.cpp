/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:02:42 by rmazurit          #+#    #+#             */
/*   Updated: 2022/12/16 17:02:42 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Animal.hpp"

Animal::Animal() : _type("Default animal") {
	std::cout << _type << " was created" << std::endl;
}

Animal::Animal(const Animal &src) {
	std::cout << _type << " copy constructor called" << std::endl;
	*this = src;
}

Animal::~Animal() {
	std::cout << _type << " was destroyed" << std::endl;
}

Animal &Animal::operator=(const Animal &src)
{
	std::cout << "Animal assignation operator called" << std::endl;
	if (this == &src)
		return *this;
	_type = src._type;
	return (*this);
}

void 	Animal::make_sound()const {
	std::cout << "Default animal: default sound..." << std::endl;
}

std::string	Animal::get_type() const {
	return (_type);
}