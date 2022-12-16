/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 19:02:27 by rmazurit          #+#    #+#             */
/*   Updated: 2022/12/16 19:02:27 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include "Animal.hpp"

class WrongAnimal {

protected:
	std::string	_type;

public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal &src);
	~WrongAnimal();

	WrongAnimal	&operator=(const WrongAnimal &src);

	void	make_sound() const;
};

#endif
