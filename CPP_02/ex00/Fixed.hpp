/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:25:52 by rmazurit          #+#    #+#             */
/*   Updated: 2022/11/28 12:25:52 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Header-protection
#pragma once

// Includes
#include <iostream>

// Classes
class Fixed
{
	private:
		int					_fp_value;
		static const int	_fract_bits;

	public:
		Fixed();
		Fixed(const Fixed &copy);
		~Fixed();

		Fixed &operator=(const Fixed &src);

		int		getRawBits() const;
		void	setRawBits(int const raw);
};
