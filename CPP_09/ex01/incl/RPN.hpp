/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 12:54:13 by rmazurit          #+#    #+#             */
/*   Updated: 2023/03/12 12:54:13 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <list>

class RPN {

private:
	std::list<char>	_rpn_data;
	std::list<char>	_norm_data;
	long 			_res;
	std::string 	_input;

	//MEMBER FUNCTIONS
	int 			parse_input();
	int 			normalize_rpn();

public:
	RPN();
	RPN(const std::string &input);
	RPN(const RPN &src);
	RPN &operator=(const RPN &src);
	~RPN();

	int calculate();
};