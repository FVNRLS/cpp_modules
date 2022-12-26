/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 17:40:10 by rmazurit          #+#    #+#             */
/*   Updated: 2022/12/26 17:40:10 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/TypeIdentifier.hpp"

int main () {
	Base 	*base;

	for (int i = 0; i < 10; i++) {
		base = generate();
		identify(base);
		identify(*base);
		std::cout << std::endl;
		delete base;
	}
	return (0);
}