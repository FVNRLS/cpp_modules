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
RPN::RPN() : _operands(), _input() {}

RPN::RPN(const std::string &input) : _operands(), _input(input) {}

RPN::RPN(const RPN &src) { *this = src; }

RPN	&RPN::operator=(const RPN &src) {
	if (this == &src)
		return *this;
	_operands = src._operands;
	_input = src._input;
	return *this;
}

RPN::~RPN() {}


//TOOLS
std::string trim(const std::string &s) {
	if (s.empty())
		return "";
	// Trim spaces from the beginning and end of the string
	size_t front_pos = s.find_first_not_of(" \t\r\n");
	size_t back_pos = s.find_last_not_of(" \t\r\n");

	// String is all whitespace
	if (front_pos == std::string::npos || back_pos == std::string::npos)
		return "";

	return s.substr(front_pos, back_pos - front_pos + 1);
}


//MEMBER FUNCTIONS
int RPN::calculate() {
	char	c;
	long 	op_1;
	long 	op_2;
	long 	res;

	_input = trim(_input);
	if (_input.size() < 2) {
		std::cout << "Error: invalid input" << std::endl;
		return EXIT_FAILURE;
	}

	for (std::string::iterator it = _input.begin(); it != _input.end(); it++) {
		c = *it;
		if (isdigit(c))
			_operands.push((c - '0'));
		else {
			if (c == SPACE)
				continue;
			else if (_operands.size() < 2) {
				std::cout << "Error: invalid input" << std::endl;
				return EXIT_FAILURE;
			}
			op_1 = _operands.top();
			_operands.pop();
			op_2 = _operands.top();
			_operands.pop();
			switch(c) {
				case '+':
					_operands.push(op_2 + op_1);
					break;
				case '-':
					_operands.push(op_2 - op_1);
					break;
				case '*':
					_operands.push(op_2 * op_1);
					break;
				case '/':
					_operands.push(op_2 / op_1);
					break;
				default:
					std::cout << "Error: invalid input" << std::endl;
					return EXIT_FAILURE;
			}
		}
	}
	if (_operands.size() != 1) {
		std::cout << "Error: invalid input" << std::endl;
		return EXIT_FAILURE;
	}
	res = _operands.top();
	if (res < INT_MIN || res > INT_MAX) {
		std::cout << "Error: calculation result out of integer range" << std::endl;
		return EXIT_FAILURE;
	}
	std::cout << res << std::endl;
	return EXIT_SUCCESS;
}

