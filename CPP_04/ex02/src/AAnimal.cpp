/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:02:42 by rmazurit          #+#    #+#             */
/*   Updated: 2022/12/16 17:02:42 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/AAnimal.hpp"

AAnimal::AAnimal() : _type("Default animal") {
	std::cout << _type << " was created" << std::endl;
}

AAnimal::AAnimal(const AAnimal &src) {
	std::cout << "Default animal copy constructor called" << std::endl;
	*this = src;
}

AAnimal::~AAnimal() {
	std::cout << "Default animal was destroyed" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &src)
{
	std::cout << "AAnimal assignation operator called" << std::endl;
	if (this == &src)
		return *this;
	_type = src._type;
	return (*this);
}

void 	AAnimal::make_sound() const {
	std::cout << "Default animal: default sound..." << std::endl;
}

std::string	AAnimal::get_type() const {
	return (_type);
}
