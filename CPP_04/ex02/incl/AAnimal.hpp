/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
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

class AAnimal {

protected:
	std::string	_type;

public:
	AAnimal();
	AAnimal(const AAnimal &src);
	virtual ~AAnimal();

	AAnimal	&operator=(const AAnimal &src);

	virtual void	make_sound() const = 0;
	std::string		get_type() const;
};

#endif
