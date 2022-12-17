/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:02:25 by rmazurit          #+#    #+#             */
/*   Updated: 2022/12/16 17:02:25 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal {

protected:
	std::string	_type;

public:
	Animal();
	Animal(const Animal &src);
	virtual ~Animal();

	Animal	&operator=(const Animal &src);

	virtual void	make_sound() const;
	std::string		get_type() const;
};

#endif
