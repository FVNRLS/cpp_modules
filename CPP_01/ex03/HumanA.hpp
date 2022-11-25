/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:17:35 by rmazurit          #+#    #+#             */
/*   Updated: 2022/11/25 13:17:35 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"
# include <string>
# include <iostream>

class	HumanA {

private:
	std::string _name;
	Weapon 		&_weapon;

public:
	HumanA(std::string name, Weapon &weapon);
	~HumanA();

	void	attack();
};

#endif
