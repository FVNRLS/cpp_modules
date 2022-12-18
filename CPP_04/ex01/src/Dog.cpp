/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:07:40 by rmazurit          #+#    #+#             */
/*   Updated: 2022/12/16 17:07:40 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Dog.hpp"

Dog::Dog() : Animal() {
	_type = "Dog";
	std::cout << _type << " was created" << std::endl;
	_brain = new Brain();
}

Dog::Dog(const Dog &src) : Animal(src) {
	std::cout << _type << " copy constructor called" << std::endl;
	*this = src;
}

Dog::~Dog() {
	delete(_brain);
	std::cout << _type << " was destroyed" << std::endl;
}

Dog	&Dog::operator=(const Dog &src) {
	std::cout << "Dog assignation operator called" << std::endl;
	if (this == &src)
		return (*this);
	_type = src._type;
	_brain = new Brain();
	*_brain = *src._brain;
	get_brain_addr(src);
	return (*this);
}

void	Dog::make_sound() const {
	std::cout << _type << ": Woof..." << std::endl;
}

void	Dog::get_ideas() const {
	for (int i = 0; i < NUM_IDEAS; i++)
		std::cout << "\tIdea " << (i + 1) << " of the dog is: " << _brain->get_idea(i) << std::endl << std::endl;;
}

void	Dog::set_idea(int i, const std::string &idea) {
	_brain->set_idea(i, idea);
}

void	Dog::get_brain_addr(const Dog &src) const {
	std::cout << std::endl;
	std::cout << "Memory address of the source dog brain:	" << &src._brain << std::endl;
	std::cout << "Memory address of the copied dog brain:	" << &_brain << std::endl;
}