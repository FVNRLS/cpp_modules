/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 13:22:15 by rmazurit          #+#    #+#             */
/*   Updated: 2022/11/29 13:22:15 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


const int Fixed::_fract_bits = 8;

Fixed::Fixed(): _fp_value(0) {
	return ;
}


Fixed::Fixed(const int input) {
	_fp_value = input << _fract_bits;
}

Fixed::Fixed(const float input) {
	_fp_value = roundf(input * (1 << _fract_bits));
}

Fixed::Fixed(const Fixed &copy) {
	*this = copy;
}

// Deconstructors
Fixed::~Fixed() {
	return ;
}

// Overloaded Operators
Fixed	&Fixed::operator=(const Fixed &src) {
	if (this != &src)
		_fp_value = src.getRawBits();
	return *this;
}

bool	Fixed::operator>(Fixed fixed) const {
	return (this->toFloat() > fixed.toFloat());
}

bool	Fixed::operator<(Fixed fixed) const {
	return (this->toFloat() < fixed.toFloat());
}

bool	Fixed::operator>=(Fixed fixed) const {
	return (this->toFloat() >= fixed.toFloat());
}

bool	Fixed::operator<=(Fixed fixed) const {
	return (this->toFloat() <= fixed.toFloat());
}

bool	Fixed::operator==(Fixed fixed) const {
	return (this->toFloat() == fixed.toFloat());
}

bool	Fixed::operator!=(Fixed fixed) const {
	return (this->toFloat() != fixed.toFloat());
}

float	Fixed::operator+(Fixed fixed) const {
	return (this->toFloat() + fixed.toFloat());
}

float	Fixed::operator-(Fixed fixed) const {
	return (this->toFloat() - fixed.toFloat());
}

float	Fixed::operator*(Fixed fixed) const {
	return (this->toFloat() * fixed.toFloat());
}

float	Fixed::operator/(Fixed fixed) const {
	return (this->toFloat() / fixed.toFloat());
}

//Pre-increment
Fixed	Fixed::operator++() {
	_fp_value++;
	return (*this);
}

//Pre-decrement
Fixed	Fixed::operator--() {
	_fp_value--;
	return (*this);
}

//Post-increment
Fixed	Fixed::operator++(int) {
	Fixed tmp = *this;
	++_fp_value;
	return (tmp);
}

//Post-decrement
Fixed	Fixed::operator--(int) {
	Fixed tmp = *this;
	--_fp_value;
	return (tmp);
}

float	Fixed::toFloat() const {
	return ((float)_fp_value / (float)(1 << _fract_bits));
}

int	Fixed::toInt() const {
	return (this->_fp_value >> this->_fract_bits);
}

Fixed	&Fixed::min(Fixed &first, Fixed &second) {
	if (first.toFloat() <= second.toFloat())
		return (first);
	else
		return (second);
}

const Fixed	&Fixed::min(const Fixed &first, const Fixed &second) {
	if (first.toFloat() <= second.toFloat())
		return (first);
	else
		return (second);
}

Fixed	&Fixed::max(Fixed &first, Fixed &second) {
	if (first.toFloat() >= second.toFloat())
		return (first);
	else
		return (second);
}

const Fixed	&Fixed::max(const Fixed &first, const Fixed &second) {
	if (first.toFloat() >= second.toFloat())
		return (first);
	else
		return (second);
}

// Getter
int	Fixed::getRawBits() const {
	return (this->_fp_value);
}

// Setter
void	Fixed::setRawBits(int const raw) {
	this->_fp_value = raw;
}

std::ostream	&operator<<(std::ostream &o, Fixed const &fixed) {
	o << fixed.toFloat();
	return (o);
}