/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:19:04 by rmazurit          #+#    #+#             */
/*   Updated: 2022/12/15 15:19:04 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main() {
	std::cout << "\033[1;31m******** TESTING DIAMONDTRAP ********\033[0m" << std::endl;
	DiamondTrap diamond;
	DiamondTrap ruby("Ruby");
	DiamondTrap diamond_brother(diamond);

	std::cout << std::endl;

	diamond.whoAmI();
	diamond.attack("a target");
	ruby.whoAmI();
	ruby.attack("a target");
	diamond_brother.whoAmI();

	std::cout << std::endl;


	return (0);
}
