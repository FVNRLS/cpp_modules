/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 17:12:00 by rmazurit          #+#    #+#             */
/*   Updated: 2022/12/17 17:12:00 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Brain.hpp"

Brain::Brain() {
	std::cout << "Brain was created" << std::endl;
}

Brain::Brain(const Brain &src) {
	std::cout << "Brain copy constructor called" << std::endl;
	*this = src;
}

Brain::~Brain() {
	std::cout << "Brain was destroyed" << std::endl;
}

Brain	&Brain::operator=(const Brain &src) {
	std::cout << "Brain assignation operator called" << std::endl;
	if (this == &src)
		return (*this);
	for (int i = 0; i < NUM_IDEAS; i++) {
		set_idea(i, src._ideas[i]);
	}
	return (*this);
}

std::string	Brain::get_idea(int i) const {
	return (_ideas[i]);
}

void	Brain::set_idea(int i, std::string const &idea) {
	_ideas[i] = idea;
}
