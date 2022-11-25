/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:16:29 by rmazurit          #+#    #+#             */
/*   Updated: 2022/11/25 13:16:29 by rmazurit         ###   ########.fr       */
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
	Zombie(std::string &name);
	~Zombie();

	void	announce();
};

Zombie 	*newZombie(std::string name);
void 	randomChump(std::string name);

#endif
