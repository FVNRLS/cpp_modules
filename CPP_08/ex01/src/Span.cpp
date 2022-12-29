/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:54:21 by rmazurit          #+#    #+#             */
/*   Updated: 2022/12/28 17:54:21 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Span.hpp"


Span::Span() : _n(0) {
	std::cout << "Default container of size " << _n << " was created" << std::endl;
}

Span::Span(unsigned int n) : _n(n) {
	std::cout << "Parameterised container of size " << _n << " was created" << std::endl;
}

Span::Span(const Span &src) {
	*this = src;
}

Span::~Span() {
	std::cout << "Container of size " << _n << " was destroyed" << std::endl;
}

Span	&Span::operator=(const Span &src) {
	if (this == &src)
		return (*this);
	_n = src._n;
	return (*this);
}

void	Span::add_number(int num) {
	if (_vector.size() < _n)
		_vector.push_back(num);
	else
		throw std::out_of_range ("can't add more items - maximum limit of items reached");
}

int	Span::shortest_span() {
	std::vector<int>	copy = _vector;
	int 				shortest_span = INT_MAX;
	int 				span;

	if (_n > 1 && !_vector.empty()) {
		sort(copy.begin(), copy.end());
		for (size_t i = 0; i < copy.size() - 1; i++) {
			span = abs(copy[i] - copy[i + 1]);
			if (span < shortest_span)
				shortest_span = span;
		}
		return (shortest_span);
	}
	throw std::out_of_range ("container is empty");
}

int	Span::longest_span() {
	std::vector<int>	copy = _vector;
	int 				longest_span = 0;
	int 				span;

	if (_n > 1 && !_vector.empty()) {
		sort(copy.begin(), copy.end());
		span = abs(copy.front() - copy.back());
		if (span > longest_span)
				longest_span = span;
		return (longest_span);
	}
	throw std::out_of_range ("container is empty");
}