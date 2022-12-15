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
	std::cout << "		******** TESTING CLAPTRAP ********" << std::endl;
	ClapTrap	gosha("Gosha");
	gosha.get_info();
	gosha.attack("Vasja");
	gosha.take_damage(9);
	gosha.get_info();

	std::cout << std::endl;

	std::cout << "		******** TESTING SCAVTRAP ********" << std::endl;
	ScavTrap	serena("Serena");
	serena.get_info();
	serena.guard_gate();
	for (int i = 0; i < 5; i++) {
		serena.attack("others");
	}
	serena.get_info();

	std::cout << std::endl << "		******** TESTING SCAVTRAP derived functions ********" << std::endl;
	serena.be_repaired(50); //function was not redefined, so i accesses the base-class object and doesn't affect the child
	serena.get_info();
	gosha.get_info();

	return (0);
}
