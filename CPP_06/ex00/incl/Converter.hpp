/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 16:08:01 by rmazurit          #+#    #+#             */
/*   Updated: 2022/12/24 16:08:01 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <limits>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cfloat>

#define CHAR 			1
#define INT 			2
#define FLOAT 			3
#define DOUBLE 			4
#define NAN_INF 		5
#define ERROR 			6

class Converter {

private:
	const std::string	_input;
	int					_type;
	unsigned char		_char;
	int 				_int;
	float 				_float;
	double 				_double;

	int		identify_type();
	bool 	check_char() const;
	bool	check_int() const;
	bool 	check_float() const;
	bool	check_double() const;
	bool 	check_nan_inf() const;

	void 	convert();
	void 	convert_to_char();
	void 	convert_to_int();
	void 	convert_to_float();
	void 	convert_to_double();
	void 	print_nan_inf();

	void 	print_conversion() const;

public:
	Converter();
	Converter(const std::string &input);
	Converter(const Converter &src);
	~Converter();

	Converter &operator=(const Converter &src);
};

std::ostream &operator<<(std::ostream &o, Converter &src);
