/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 12:53:59 by rmazurit          #+#    #+#             */
/*   Updated: 2023/03/12 12:53:59 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

//BASIC CLASS SETUP
RPN::RPN() : _data(), _res(), _input() {}

RPN::RPN(const std::string &input) : _data(), _res(), _input(input) {}

RPN::RPN(const RPN &src) { *this = src; }

RPN	&RPN::operator=(const RPN &src) {
	if (this == &src)
		return *this;
	_data = src._data;
	_res = src._res;
	return *this;
}

RPN::~RPN() {}

//MEMBER FUNCTIONS
int RPN::calculate() {
	if (parse_input() == EXIT_FAILURE)
		return EXIT_FAILURE;

	return EXIT_SUCCESS;
}

static bool	is_valid_operator(char c) {
	std::string valid_operators = "-+*/";
	for (std::string::iterator it = valid_operators.begin(); it != valid_operators.end(); it++) {
		if (c == *it)
			return true;
	}
	return false;
}

int RPN::parse_input() {
	for (std::string::iterator it = _input.begin(); it != _input.end(); it++) {
		if (*it )
		_data.push_back(*it);
	}
	return EXIT_SUCCESS;
}
