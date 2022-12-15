/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:04:34 by rmazurit          #+#    #+#             */
/*   Updated: 2022/12/15 12:04:34 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main() {
	ClapTrap	gosha("Gosha");

	gosha.get_info();
	gosha.attack("Vasja");
	gosha.take_damage(9);
	gosha.get_info();

	for (int i = 0; i < 10; i++) {
		gosha.be_repaired(1);
	}
	gosha.get_info();

	gosha.take_damage(100000);
	gosha.get_info();

	gosha.take_damage(1);
	gosha.attack("Vasja");
	gosha.be_repaired(10);
	return (0);
}