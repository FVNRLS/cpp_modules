/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:09:24 by rmazurit          #+#    #+#             */
/*   Updated: 2022/12/15 12:09:24 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap {

private:
	std::string	_name;
	int			_hit_points;
	int			_energy_points;
	int			_damage;

public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &copy);
	~ClapTrap();

	ClapTrap &operator=(const ClapTrap &src);

	void	attack(const std::string &target);
	void	take_damage(unsigned int amount);
	void	be_repaired(unsigned int amount);
	void	get_info();
};

#endif