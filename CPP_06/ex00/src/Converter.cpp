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
	std::cout << "Converter was constructed with input: " << _input << std::endl << std::endl;
}

Converter::Converter(const std::string &input) : _input(input) {
	std::cout << "Converter was constructed with input: " << _input << std::endl << std::endl;
	convert();
}

Converter::Converter(const Converter &src) {
	std::cout << "Converter copy constructor called" << std::endl;
	*this = src;
}

Converter::~Converter() {
	std::cout << std::endl << "Converter was destroyed" << std::endl;
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

static bool	check_sign_pos(const std::string &input) {
	int minus_pos;
	int plus_pos;

	minus_pos = input.find('-');
	plus_pos = input.find('+');
	if ((minus_pos != 0 && minus_pos != -1) || (plus_pos != 0 && plus_pos != -1))
		return (false);
	return (true);
}

int	Converter::identify_type() {

	if (check_sign_pos(_input) == false)
		return (ERROR);
	else if (_input.find_first_of("+-") != _input.find_last_of("+-"))
		return (ERROR);
	else if (check_char() == true)
			return (CHAR);
	else if (check_int() == true)
		return (INT);
	else if (check_float() == true)
		return (FLOAT);
	else if (check_double() == true)
		return (DOUBLE);
	else if (check_nan_inf() == true)
		return (NAN_INF);
	else
		return (ERROR);
}

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
		else if (_input.find('.') > _input.length())
			return (false);
		else if (isdigit(_input[_input.find_first_of('.') + 1]) == 0)
			return (false);
		else if (_input.find_first_of('f') != _input.find_last_of('f'))
			return (false);
		input = _input.substr(0, _input.length() - 1).c_str();
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
		else if (_input.find_first_of('.') != _input.find_last_of('.'))
			return (false);
		else if (_input.find('.') > _input.length())
			return (false);
		else if (isdigit(_input[_input.find_first_of('.') + 1]) == 0)
			return (false);
		input = _input.c_str();
		num = strtold(input, NULL);
		if (num < -DBL_MAX || num > DBL_MAX)
			return (false);
		return (true);
	}
	return (false);
}

bool	Converter::check_nan_inf() const {
	std::string infs[6] = {"nan", "nanf", "+inf", "-inf", "+inff", "-inff"};

	for (int i = 0; i < 6; i++) {
		if (_input == infs[i])
			return (true);
	}
	return (false);
}

void	Converter::convert_to_char() {
	_char = static_cast<unsigned char>(_input[0]);
	_int = static_cast<int>(_char);
	_float = static_cast<float>(_char);
	_double = static_cast<double>(_char);
}

void	Converter::convert_to_int() {
	_int = static_cast<int>(strtol(_input.c_str(), NULL, 10));
	_char = static_cast<unsigned char>(_int);
	_float = static_cast<float>(_int);
	_double = static_cast<double>(_int);
}

void	Converter::convert_to_float() {
	_float = static_cast<float>(strtof(_input.substr(0, _input.length() - 1).c_str(), NULL));
	_int = static_cast<int>(_float);
	_double = static_cast<double>(_float);
	_char = static_cast<unsigned char>(_int);
}

void	Converter::convert_to_double() {
	_double = static_cast<double>(strtod(_input.c_str(), NULL));
	_int = static_cast<int>(_double);
	_char = static_cast<unsigned char>(_int);
	_float = static_cast<float>(_double);
}

void 	Converter::print_conversion() const {
	if (0 <= _int && _int < 32)
		std::cout << "char: Non displayable" << std::endl;
	else if (_int < 0 || _int > CHAR_MAX)
		std::cout << "char: impossible"<< std::endl;
	else
		std::cout << "char: " << _char << std::endl;

	if (_float < static_cast<float>(INT_MIN) - 1 || _float > static_cast<float>(INT_MAX) + 1
		|| _double < static_cast<double >(INT_MIN) -1 || _double > static_cast<double >(INT_MAX) + 1)
			std::cout << "int: impossible"<< std::endl;
	else
		std::cout << "int: " << _int << std::endl;

	if (_float - static_cast<float>(_int) == 0)
		std::cout << "float: " << _float << ".0f" << std::endl;
	else
		std::cout << "float: " << _float << "f" << std::endl;

	if (_float - static_cast<double>(_int) == 0)
		std::cout << "double: " << _double << ".0" << std::endl;
	else
		std::cout << "double: " << _double << std::endl;
}

void	Converter::print_nan_inf() {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: imbossible" << std::endl;
	if (_input == "nan" || _input == "nanf") {
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (_input == "+inf" || _input == "+inff") {
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else {
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
}

void	Converter::convert() {
	_type = identify_type();
	if (_type == ERROR) {
		std::cout << "Error: invalid input" << std::endl;
		return;
	}
	else if (_type == NAN_INF) {
		print_nan_inf();
		return;
	}
	else if (_type == CHAR)
		convert_to_char();
	else if (_type == INT)
		convert_to_int();
	else if (_type == FLOAT)
		convert_to_float();
	else
		convert_to_double();
	print_conversion();
}
