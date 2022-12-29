/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 12:31:45 by rmazurit          #+#    #+#             */
/*   Updated: 2022/12/29 12:31:45 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>
#include <list>
#include <random>

template <typename T>

class MutantStack : public std::stack<T> {

public:
	typedef typename std::stack<T>::container_type::iterator iterator; //define a type alias for the iterator type of the container
	typedef typename std::stack<T>::container_type::const_iterator const_iterator; //define a type alias for the const iterator type of the container

	MutantStack() {
		std::cout << "MutantStack was created" << std::endl << std::endl;
	}

	MutantStack(const MutantStack &src) {
		*this = src;
	}

	~MutantStack() {
		std::cout << std::endl << "MutantStack was destroyed" << std::endl;
	}

	MutantStack	&operator=(const MutantStack &src) {
		if (this == &src)
			return (*this);
		return (*this);
	}

	iterator begin() {
		return (std::stack<T>::c.begin());
	}

	iterator end() {
		return (std::stack<T>::c.end());
	}

	const_iterator begin() const {
		return (std::stack<T>::c.begin());
	}

	const_iterator end() const{
		return (std::stack<T>::c.end());
	}
};
