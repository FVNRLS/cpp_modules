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
	std::cout << "Default span of size " << _n << " was created" << std::endl;
}

Span::Span(unsigned int n) : _n(n) {
	std::cout << "Parameterised span of size " << _n << " was created" << std::endl;
}

Span::Span(const Span &src) {
	*this = src;
}

Span::~Span() {
	std::cout << "Span of size " << _n << " was destroyed" << std::endl;
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
		throw std::out_of_range ("can't add more items - maximum limit of items was reached");
}

int	Span::shortest_span() {
	std::vector<int>	_copy = _vector;
	int 				shortest_span = INT_MAX;
	int 				span;

	if (_n > 1 && !_vector.empty()) {
		sort(_copy.begin(), _copy.end());
		for (int i = 0; i < _copy.size() - 1; i++) {
			span = abs(_copy[i] - _copy[i + 1]);
			if (span < shortest_span)
				shortest_span = span;
		}
		return (shortest_span);
	}
	throw std::out_of_range ("vector is empty");
}

//todo: check again
int	Span::longest_span() {
	std::vector<int>	_copy = _vector;
	int 				longest_span = INT_MIN;
	int 				span;

	if (_n > 1 && !_vector.empty()) {
		sort(_copy.begin(), _copy.end()); //todo: wrong!
		for (int i = 0; i < _copy.size() - 1; i++) {
			span = abs(_copy[i] - _copy[i + 1]);
			if (span > longest_span)
				longest_span = span;
		}
		return (longest_span);
	}
	throw std::out_of_range ("vector is empty");
}