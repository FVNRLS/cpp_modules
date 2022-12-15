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

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	_hit_points = 100;
	_energy_points = 100;
	_damage = 30;
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	_name = name;
	_hit_points = 100;
	_energy_points = 100;
	_damage = 30;
	std::cout << "FragTrap constructor with name " << _name << " called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy) {
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap::~FragTrap() {
	if (_name.length() == 0)
		std::cout << "default FragTrap was destroyed" << std::endl;
	else
		std::cout << "FragTrap " << _name << " was destroyed" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &src)
{
	std::cout << "FragTrap Assignation operator called" << std::endl;
	_name = src._name;
	_hit_points = src._hit_points;
	_energy_points = src._energy_points;
	_damage = src._damage;
	return *this;
}

void	FragTrap::attack(const std::string &target) {
	if (_energy_points == 0) {
		std::cout << "FragTrap " << _name << " unable to attack " << target << ", - no energy points left" << std::endl;
		return;
	}
	else if (_hit_points == 0) {
		std::cout << "FragTrap " << _name << " unable to attack " << target << " - not enough hit points" << std::endl;
		return;
	}
	std::cout << "FragTrap " << _name << " attacks " << target << " causing " << _damage << " points of damage" << std::endl;
	_energy_points--;
}

void 	FragTrap::high_fives_guys() {
	std::cout << "Give high five, guys!" << std::endl;
}

void	FragTrap::get_info() {
	std::cout << "-----------------------------------------------------------" << std::endl;
	std::cout << "FragTrap " << _name << ": hit points: " << _hit_points << " | energy points: " << _energy_points << std::endl;
	std::cout << "----------------------------------------------------------" << std::endl;
}
