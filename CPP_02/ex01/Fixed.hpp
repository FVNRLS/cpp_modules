/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:41:12 by rmazurit          #+#    #+#             */
/*   Updated: 2022/11/28 17:41:12 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {

private:
	int					_fp_value;
	static const int	_fract_bits;

public:
	Fixed();
	Fixed(const Fixed &src);
	Fixed(const int num);
	Fixed(const float num);
	~Fixed();

	Fixed &operator=(const Fixed &src);

	int		getRawBits() const;
	void	setRawBits(int const raw);

	float	toFloat() const;
	int		toInt() const;

};

std::ostream	&operator<<(std::ostream &o, Fixed const &fixed);

#endif