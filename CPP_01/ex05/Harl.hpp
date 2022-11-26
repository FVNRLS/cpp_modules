/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 13:32:23 by rmazurit          #+#    #+#             */
/*   Updated: 2022/11/26 13:32:23 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <string>
#include <fstream>

class Harl {

private:
	std::string	_level;

public:
	Harl();
	~Harl();

	void	debug();
	void	info();
	void	warning();
	void	error();
	void    complain(std::string level);
};


#endif
