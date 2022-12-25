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

Converter::Converter(const std::string &input) : _input(input) {
	std::cout << "Converter was created with input: " << _input << std::endl;
	convert();
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

static bool	check_sign_pos(const std::string input) {
	int minus_pos;
	int plus_pos;


	minus_pos = input.find('-');
	plus_pos = input.find('-');
	std::cout << plus_pos << std::endl;
	return (true);
}

int	Converter::identify_type() {

	check_sign_pos(_input);
	if (_input.find_first_of("+-") != _input.find_last_of("+-")) // catches any multiple or mixed use of the characters
		return (ERROR);
	else if (check_char() == true) {
		return (DISPL_CHAR);
	}
	else if (check_int() == true)
		return (INT);
	else if (check_float() == true)
		return (FLOAT);
	else
		return (ERROR);
}

/*
 * Preliminaries for a CHAR:
 * 1)	should bea alphanum
 * 2) 	should be printable
 * 3) 	Length should be 1
 * */
bool	Converter::check_char() const {
	if (_input.length() == 1 && std::isalpha(_input[0]) && (std::isprint(_input[0]) == 1))
		return (true);
	return (false);
}

bool	Converter::check_int() const {
	long 		num;
	const char	*input;

	if (_input.find_first_not_of("+-0123456789") == std::string::npos) {
		input = _input.c_str();
		num = strtol(input, NULL, 10);
		if (num < INT_MIN || num > INT_MAX)
			return (false);
		return (true);
	}
	return (false);
}

bool	Converter::check_float() const {
	double 		num;
	const char	*input;

	if (_input.find_first_not_of("+-0123456789.f") == std::string::npos) {
		if (_input[0] == '.')
			return (false);
		else if (_input[1] == '.' && (_input[0] == '-' || _input[0] == '+'))
			return (false);
		else if (_input[_input.length() - 1] != 'f')
			return (false);
		else if (_input.find_first_of('.') != _input.find_last_of('.'))
			return (false);
		else if (isdigit(_input[_input.find_first_of('.') + 1]) == 0)
			return (false);
		else if (_input.find_first_of('f') != _input.find_last_of('f'))
			return (false);
		input = _input.substr(0, _input.length() - 1).c_str();
		std::cout << input << std::endl;
		num = strtod(input, NULL);
		if (num < -FLT_MAX || num > FLT_MAX)
			return (false);
		return (true);
	}
	return (false);
}

bool	Converter::check_double() const {
	long double	num;
	const char	*input;

	if (_input.find_first_not_of("+-0123456789.") == std::string::npos) {
		if (_input[0] == '.')
			return (false);
		else if (_input[1] == '.' && (_input[0] == '-' || _input[0] == '+'))
			return (false);
		else if (_input[_input.length() - 1] != 'f')
			return (false);
		else if (_input.find_first_of('.') != _input.find_last_of('.'))
			return (false);
		else if (isdigit(_input[_input.find_first_of('.') + 1]) == 0)
			return (false);
		else if (_input.find_first_of('f') != _input.find_last_of('f'))
			return (false);
		input = _input.substr(0, _input.length() - 1).c_str();
		std::cout << input << std::endl;
		num = strtod(input, NULL);
		if (num < -FLT_MAX || num > FLT_MAX)
			return (false);
		return (true);
	}
	return (false);
}

void	Converter::convert() {
	_type = identify_type();
	std::cout << _type << std::endl;
}
