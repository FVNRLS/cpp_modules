/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:08:26 by rmazurit          #+#    #+#             */
/*   Updated: 2022/12/16 17:08:26 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Cat.hpp"

Cat::Cat() : Animal() {
	_type = "Cat";
	std::cout << _type << " was created" << std::endl;
	_brain = new Brain();
	if (!_brain) {
		perror("allocation failed");
		exit(1);
	}
}

Cat::Cat(const Cat &src) : Animal(src) {
	std::cout << _type << " copy constructor called" << std::endl;
	*this = src;
}

Cat::~Cat() {
	delete(_brain);
	std::cout << _type << " was destroyed" << std::endl;
}

Cat	&Cat::operator=(const Cat &src) {
	std::cout << "Cat assignation operator called" << std::endl;
	if (this == &src)
		return *this;
	_type = src._type;
	_brain = new Brain();
	if (!_brain) {
		perror("allocation failed");
		exit(1);
	}
	*_brain = *src._brain;
	return *this;
}

void Cat::make_sound() const {
	std::cout << _type << ": Meeeeeaaaaow..." << std::endl;
}

void	Cat::get_ideas() const {
	for (int i = 0; i < NUM_IDEAS; i++)
		std::cout << "\tIdea " << (i + 1) << " of the cat is: " << _brain->get_idea(i) << std::endl;
}

void	Cat::set_idea(int i, const std::string &idea) {
	this->_brain->set_idea(i, idea);
}
