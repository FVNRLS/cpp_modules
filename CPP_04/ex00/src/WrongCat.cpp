/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 19:28:53 by rmazurit          #+#    #+#             */
/*   Updated: 2022/12/16 19:28:53 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
	_type = "Wrong cat";
	std::cout << _type << " was created" << std::endl;
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal() {
	std::cout << _type << " copy constructor called" << std::endl;
	*this = src;
}

WrongCat::~WrongCat() {
	std::cout << _type << " was destroyed" << std::endl;
}

WrongCat	&WrongCat::operator=(const WrongCat &src) {
	this->_type = src._type;
	return (*this);
}

void	WrongCat::make_sound() const {
	std::cout << "Some wrong animal sound..." << std::endl;
}
