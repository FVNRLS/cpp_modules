/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:26:26 by rmazurit          #+#    #+#             */
/*   Updated: 2022/11/28 12:26:26 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fp_value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy) : _fp_value(0) {
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &src) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->_fp_value = src.getRawBits();
	return (*this);
}

int Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return (_fp_value);
}

void	Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	_fp_value = raw;
}

