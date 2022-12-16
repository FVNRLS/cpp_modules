/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 19:28:33 by rmazurit          #+#    #+#             */
/*   Updated: 2022/12/16 19:28:33 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal {

public:
	WrongCat();
	WrongCat(const WrongCat &src);
	~WrongCat();

	WrongCat &operator=(const WrongCat &src);

	void	make_sound() const;
};

#endif
