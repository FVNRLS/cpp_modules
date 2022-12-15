/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:17:45 by rmazurit          #+#    #+#             */
/*   Updated: 2022/12/15 15:17:45 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	_hit_points = 100;
	_energy_points = 50;
	_damage = 20;
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	_name = name;
	_hit_points = 100;
	_energy_points = 50;
	_damage = 20;
	std::cout << "ScavTrap constructor with name " << _name << " called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy) {
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap() {
	if (_name.length() == 0)
		std::cout << "default ScavTrap was destroyed" << std::endl;
	else
		std::cout << "ScavTrap " << _name << " was destroyed" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &src)
{
	std::cout << "ScavTrap Assignation operator called" << std::endl;
	_name = src._name;
	_hit_points = src._hit_points;
	_energy_points = src._energy_points;
	_damage = src._damage;
	return *this;
}

void	ScavTrap::attack(const std::string &target) {
	if (_energy_points == 0) {
		std::cout << "ScavTrap " << _name << " unable to attack " << target << ", - no energy points left" << std::endl;
		return;
	}
	else if (_hit_points == 0) {
		std::cout << "ScavTrap " << _name << " unable to attack " << target << " - not enough hit points" << std::endl;
		return;
	}
	std::cout << "ScavTrap " << _name << " attacks " << target << " causing " << _damage << " points of damage" << std::endl;
	_energy_points--;
}

void 	ScavTrap::guard_gate() {
	std::cout << "ScavTrap " << _name << " is in gate-keeper mode" << std::endl;
}

void	ScavTrap::get_info() {
	std::cout << "-----------------------------------------------------------" << std::endl;
	std::cout << "ScavTrap " << _name << ": hit points: " << _hit_points << " | energy points: " << _energy_points << std::endl;
	std::cout << "----------------------------------------------------------" << std::endl;
}
