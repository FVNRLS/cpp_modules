/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 13:23:45 by rmazurit          #+#    #+#             */
/*   Updated: 2022/11/29 13:23:45 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <cmath>

class Fixed {

private:
	int					_fp_value;
	static const int	_fract_bits;

public:
	Fixed();
	Fixed(const int input);
	Fixed(const float input);
	Fixed(const Fixed &copy);
	~Fixed();

	Fixed &operator=(const Fixed &src);

	bool operator>(Fixed fixed)const;
	bool operator<(Fixed fixed)const;
	bool operator>=(Fixed fixed)const;
	bool operator<=(Fixed fixed)const;
	bool operator==(Fixed fixed)const;
	bool operator!=(Fixed fixed)const;

	float operator+(Fixed fixed)const;
	float operator-(Fixed fixed)const;
	float operator*(Fixed fixed)const;
	float operator/(Fixed fixed)const;

	Fixed operator++();
	Fixed operator--();
	Fixed operator++(int);
	Fixed operator--(int);

	int		getRawBits()const;
	void	setRawBits(int const raw);

	float	toFloat() const;
	int		toInt() const;

	static Fixed &min(Fixed &first, Fixed &second);
	static const Fixed &min(Fixed const &first, Fixed const &second);
	static Fixed &max(Fixed &first, Fixed &second);
	static const Fixed &max(Fixed const &first, const Fixed &second);
};

std::ostream	&operator<<(std::ostream &o, Fixed const &fixed);
