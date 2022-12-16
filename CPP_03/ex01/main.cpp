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

#include "ScavTrap.hpp"

int	main() {
	std::cout << "\033[1;31m******** TESTING CLAPTRAP ********\033[0m" << std::endl;
	ClapTrap	gosha("Gosha");
	gosha.get_info();
	gosha.attack("Vasja");
	gosha.take_damage(9);
	gosha.get_info();

	std::cout << std::endl;

	std::cout << "\033[1;31m******** TESTING SCAVTRAP ********\033[0m" << std::endl;
	ScavTrap	serena("Serena");
	serena.get_info();
	serena.guard_gate();
	for (int i = 0; i < 5; i++) {
		serena.attack("others");
	}
	serena.get_info();

	std::cout << std::endl << "\033[1;31m******** TESTING SCAVTRAP derived functions ********\033[0m" << std::endl;
	serena.be_repaired(50);
	serena.get_info();
	serena.take_damage(150);
	serena.get_info();
	serena.take_damage(150);

	std::cout << std::endl;

	return (0);
}
