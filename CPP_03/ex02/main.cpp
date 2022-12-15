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
#include "FragTrap.hpp"

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
	serena.be_repaired(50); //function was not redefined, so it accesses the base-class object and doesn't affect the child
	serena.get_info();

	std::cout << std::endl;

	std::cout << "\033[1;31m******** TESTING FRAGTRAP ********\033[0m" << std::endl;
	FragTrap	frag("Frag");
	frag.get_info();
	frag.high_fives_guys();
	for (int i = 0; i < 5; i++) {
		frag.attack("others");
	}
	frag.get_info();

	std::cout << std::endl << "\033[1;31m******** TESTING FRAGTRAP derived functions ********\033[0m" << std::endl;
	frag.be_repaired(50); //function was not redefined, so it accesses the base-class object and doesn't affect the child
	frag.take_damage(100); //the same as above..
	frag.get_info();

	return (0);
}
