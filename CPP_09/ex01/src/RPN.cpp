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

//MEMBER FUNCTIONS
int RPN::calculate() {
	char	c;
	long 	op_1;
	long 	op_2;
	long 	res;

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
	res = _operands.top();
	if (_operands.size() != 1) {
		std::cout << "Error: invalid input" << std::endl;
		return EXIT_FAILURE;
	}
	if (res < INT_MIN || res > INT_MAX) {
		std::cout << "Error: calculation result out of integer range" << std::endl;
		return EXIT_FAILURE;
	}
	std::cout << res << std::endl;
	return EXIT_SUCCESS;
}

