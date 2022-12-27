/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:22:08 by rmazurit          #+#    #+#             */
/*   Updated: 2022/12/27 16:22:08 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>

template<typename T>
class	Array {

private:
	T*				_array;
	unsigned int	_len;
public:

	Array () : _len(0) {
		_array = new T[_len];
		if (!_array) {
			std::cout << "Fatal error: memory allocation failed" << std::endl;
			return;
		}
		std::cout << "Default array of size 0 was created" << std::endl;
	};

	Array(unsigned int len) : _len(len) {
		_array = new T[_len];
		if (!_array) {
			std::cout << "Fatal error: memory allocation failed" << std::endl;
			return;
		}
		std::cout << "Array of size " << size() << " was created" << std::endl;
	}

	Array(const Array &src) : _len(src._len) {
		std::cout << "Copy constructor called" << std::endl;
		_array = NULL;
		*this = src;
	}

	~Array() {
		if (_len > 0)
			delete [] _array;
		std::cout << "Array of size " << _len << " was destroyed" << std::endl;
	}

	//creating a deep copy of array
	Array &operator=(const Array &src) {
		std::cout << "Assignment operator called" << std::endl;
		if (this == &src)
			return (*this);
		if (_array != NULL) {
			delete [] _array;
			_array = NULL;
		}
		_len = src._len;
		if (_len > 0) {
			_array = new T[_len];
			if (!_array) {
				std::cout << "Fatal error: memory allocation failed" << std::endl;
				_array = NULL;
				return (*this);
			}
			for (unsigned int i = 0; i < _len; i++)
				_array[i] = src._array[i];
		}
		return (*this);
	}

	T	&operator[](unsigned int i) {
		if (i > _len || _array == NULL)
			throw std::out_of_range ("Index out of range");
		return (_array[i]);
	}

	unsigned int	size() const {
		return (_len);
	}
};
