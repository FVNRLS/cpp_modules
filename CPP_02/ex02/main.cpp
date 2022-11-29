/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 13:23:00 by rmazurit          #+#    #+#             */
/*   Updated: 2022/11/29 13:23:00 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main( void ) {

	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

//	std::cout << Fixed::min( a, b ) << std::endl;
//	if (b != a)
//		std::cout << std::endl << b << " is not equal " << a << std::endl;
//	a = b;
//	if (a == b)
//		std::cout << std::endl << b << " is equal " << a << std::endl;

//	float x = 3.33;
//	float y  = 10 / 3;
//
//	if (x == y)
//		std::cout << "true!" << std::endl;

	return 0;
}