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

# define NUM_FUNCTIONS	4

class Harl {

private:
	void		(Harl::*_funcs[NUM_FUNCTIONS])();
	std::string	_complains[NUM_FUNCTIONS];

	void	debug();
	void	info();
	void	warning();
	void	error();
	void	wrong_func();
	void	create_complains_list();

public:
	Harl();
	~Harl();

	void    complain(std::string level);
};

#endif
