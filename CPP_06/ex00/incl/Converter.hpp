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

class Converter {

private:
	const std::string	_input;
	int					_type;
	char				_char;
	int 				_int;
	float 				_float;
	double 				_double;

public:
	Converter();
	Converter(std::string input);
	Converter(const Converter &src);
	~Converter();

	Converter &operator=(const Converter &src);

	int		identify_type();
	void 	convert();
	char 	convert_to_char();
	int 	convert_to_int();
	float 	convert_to_float();
	double 	convert_to_double();
};

std::ostream &operator<<(std::ostream &o, Converter &src);
