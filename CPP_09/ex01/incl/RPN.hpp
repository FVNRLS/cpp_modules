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
#include <stack>
#include <string>
#include <cstdlib>
#include <climits>

#define SPACE	' '

class RPN {

private:
	std::stack<long>	_operands;
	std::string 		_input;

public:
	RPN();
	RPN(const std::string &input);
	RPN(const RPN &src);
	RPN &operator=(const RPN &src);
	~RPN();

	int calculate();
};