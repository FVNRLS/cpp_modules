/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:05:55 by rmazurit          #+#    #+#             */
/*   Updated: 2022/12/15 12:05:55 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _hit_points(10), _energy_points(10), _damage(0) {
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hit_points(10), _energy_points(10), _damage(0) {
	std::cout << "ClapTrap constructor with name " << _name << " called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy) {
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = copy;
}

ClapTrap::~ClapTrap() {
	if (_name.length() == 0)
		std::cout << "default ClapTrap was destroyed" << std::endl;
	else
		std::cout << "ClapTrap " << _name << " was destroyed" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &src)
{
	std::cout << "ClapTrap Assignation operator called" << std::endl;
	_name = src._name;
	_hit_points = src._hit_points;
	_energy_points = src._energy_points;
	_damage = src._damage;
	return *this;
}

void	ClapTrap::attack(const std::string &target) {
	if (_energy_points == 0) {
		std::cout << "ClapTrap " << _name << " unable to attack " << target << ", - no energy points left" << std::endl;
		return;
	}
	else if (_hit_points == 0) {
		std::cout << "ClapTrap " << _name << " unable to attack " << target << " - not enough hit points" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << _name << " attacks " << target << " causing " << _damage << " points of damage" << std::endl;
	_energy_points--;
}

void	ClapTrap::take_damage(unsigned int amount) {
	if (_hit_points == 0 && amount > 0) {
		std::cout << "ClapTrap " << _name << " is already dead - no damage can be taken" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _name <<  " takes " << amount << " points of damage" << std::endl;
	_hit_points -= amount;
	if (_hit_points <= 0) {
		std::cout << "ClapTrap " << _name << " dies" << std::endl;
		_hit_points = 0;
	}
}

void	ClapTrap::be_repaired(unsigned int amount) {
	if (_hit_points == 0) {
		std::cout << "ClapTrap " << _name << " unable to repair itself - ClapTrap is dead" << std::endl;
		return;
	}
	else if (_energy_points == 0) {
		std::cout << "ClapTrap " << _name << " unable to repair itself - no energy points left" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << _name << " repairs " << amount << " of hit points" << std::endl;
	this->_hit_points += amount;
	this->_energy_points--;
}

void	ClapTrap::get_info() {
	std::cout << "-----------------------------------------------------------" << std::endl;
	std::cout << _name << ": hit points: " << _hit_points << " | energy points: " << _energy_points << std::endl;
	std::cout << "----------------------------------------------------------" << std::endl;
}

