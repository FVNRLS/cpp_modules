/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 20:24:35 by rmazurit          #+#    #+#             */
/*   Updated: 2022/12/15 20:24:35 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap {

private:
	std::string	_name;

public:
	DiamondTrap();
	DiamondTrap(const DiamondTrap &copy);
	DiamondTrap(std::string name);
	virtual ~DiamondTrap();

	DiamondTrap &operator=(const DiamondTrap &src);

	void	attack(const std::string &target);
	void	whoAmI(void);
};

#endif
