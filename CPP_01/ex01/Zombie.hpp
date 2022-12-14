/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:15:25 by rmazurit          #+#    #+#             */
/*   Updated: 2022/11/27 14:16:32 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class	Zombie {

private:
	std::string	_name;

public:
	Zombie();
	~Zombie();

	void 	set_name(std::string &name);
	void	announce();
};

Zombie	*zombieHorde(int N, std::string name);

#endif
