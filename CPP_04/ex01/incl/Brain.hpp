/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 17:09:39 by rmazurit          #+#    #+#             */
/*   Updated: 2022/12/17 17:09:39 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

#define NUM_IDEAS	4

class Brain {

private:
	std::string	_ideas[100];

public:
	Brain();
	Brain(const Brain &src);
	~Brain();

	Brain	&operator=(const Brain &src);

	std::string	get_idea(int i) const;
	void		set_idea(int i, std::string const &idea);
};

#endif
