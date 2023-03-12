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
RPN::RPN() : _rpn_data(), _norm_data(), _res(), _input() {}

RPN::RPN(const std::string &input) : _rpn_data(), _norm_data(), _res(), _input(input) {}

RPN::RPN(const RPN &src) { *this = src; }

RPN	&RPN::operator=(const RPN &src) {
	if (this == &src)
		return *this;
	_rpn_data = src._rpn_data;
	_norm_data = src._norm_data;
	_res = src._res;
	_input = src._input;
	return *this;
}

RPN::~RPN() {}

//TOOLS
static bool	is_valid_operator(char c) {
	std::string valid_operators = "-+*/ ";
	for (std::string::iterator it = valid_operators.begin(); it != valid_operators.end(); it++) {
		if (c == *it)
			return true;
	}
	return false;
}

//MEMBER FUNCTIONS
//TODO: find out if res should be float/double or only int?
int RPN::calculate() {
	std::list<char>::iterator	it;
	char 						curr_operator;
	int 						num;


	if (parse_input() == EXIT_FAILURE)
		return EXIT_FAILURE;
	if (normalize_rpn() == EXIT_FAILURE) {
		std::cerr << "Error" << std::endl;
		return EXIT_FAILURE;
	}
	if (!_norm_data.empty()) {
		_res = _norm_data.front() - '0';
		for (it = _norm_data.begin()++; it != _norm_data.end(); it++) {
			if (is_valid_operator(*it))
				curr_operator = *it;
			else {
				num = *it - '0';
				if (curr_operator == '*')
					_res *= num;
				else if (curr_operator == '/')
					_res /= num;
				else if (curr_operator == '+')
					_res += num;
				else if (curr_operator == '-')
					_res -= num;
			}
			if (_res > INT32_MAX || _res < INT32_MIN) {
				std::cerr << "Error" << std::endl;
				return EXIT_FAILURE;
			}
		}
	}
	std::cout << "RESULT	" << _res << std::endl;
	return EXIT_SUCCESS;
}

int RPN::parse_input() {
	for (std::string::iterator it = _input.begin(); it != _input.end(); it++) {
		if ((*it >= '0' && *it <= '9') || is_valid_operator(*it)) {
			if (*it != ' ')
				_rpn_data.push_back(*it);
		}
		else {
			std::cerr << "Error" << std::endl;
			return EXIT_FAILURE;
		}
	}
	return EXIT_SUCCESS;
}

int	RPN::normalize_rpn() {
	char						current_operator;
	char 						num;
	std::list<char>::iterator 	num_it;
	std::list<char>::iterator  	op_it;
	std::list<char>::iterator  	next;

	if (is_valid_operator(*_rpn_data.begin()) || !is_valid_operator(_rpn_data.back()))
		return EXIT_FAILURE;

	for (num_it = _rpn_data.begin(); num_it != _rpn_data.end(); num_it++) {
		for (op_it = num_it; op_it != _rpn_data.end(); op_it++) {
			if (is_valid_operator(*op_it)) {
				current_operator = *op_it;
				break;
			}
		}
		if (!is_valid_operator(*op_it))
			return EXIT_FAILURE;
		if (is_valid_operator(*num_it)) {
			next = num_it;
			next++;
			if (next != _rpn_data.end() && is_valid_operator(*next))
				return EXIT_FAILURE;
			continue;
		}
		else
			num = *num_it;
		if (current_operator == '-' || current_operator == '+') {
			if (std::distance(num_it, op_it) > 1)
				return EXIT_FAILURE;
		}
		_norm_data.push_back(current_operator);
		_norm_data.push_back(num);
	}
	_norm_data.erase(_norm_data.begin());

	for (std::list<char>::iterator it = _norm_data.begin(); it != _norm_data.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	return EXIT_SUCCESS;
}
