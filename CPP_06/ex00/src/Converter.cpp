/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 16:07:44 by rmazurit          #+#    #+#             */
/*   Updated: 2022/12/24 16:07:44 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Converter.hpp"

Converter::Converter() : _input("No input") {
	std::cout << "Converter was created with input: " << _input << std::endl;
}

Converter::Converter(std::string input) : _input(input) {
	std::cout << "Converter was created with input: " << _input << std::endl;
}

Converter::Converter(const Converter &src) {
	std::cout << "Converter copy constructor called" << std::endl;
	*this = src;
}

Converter::~Converter() {
	std::cout << "Converter was destroyed" << std::endl;
}

Converter &Converter::operator=(const Converter &src) {
	if (this == &src)
		return (*this);
	_type = src._type;
	_char = src._char;
	_int = src._int;
	_float = src._float;
	_double = src._double;
	return (*this);
}

int		Converter::identify_type() {

}
