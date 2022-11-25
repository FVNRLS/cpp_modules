/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:14:09 by rmazurit          #+#    #+#             */
/*   Updated: 2022/11/25 13:14:09 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>
#include <iostream>

class	Weapon {

private:
	std::string	_type;

public:
	Weapon(const std::string &type);
	~Weapon();

	std::string getType() const;
	void		setType(const std::string &type);

};

#endif
