/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:54:46 by rmazurit          #+#    #+#             */
/*   Updated: 2022/12/28 17:54:46 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <random>

class Span {

private:
	std::vector<int>	_vector;
	unsigned int		_n;

public:
	Span();
	Span(unsigned int n);
	Span(const Span &src);
	~Span();

	Span &operator=(const Span &src);

	void	add_number(int num);
	void	add_number(unsigned int range, time_t seed);
	int 	shortest_span();
	int 	longest_span();
};