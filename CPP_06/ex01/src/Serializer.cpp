/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:46:33 by rmazurit          #+#    #+#             */
/*   Updated: 2022/12/26 16:46:33 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Serializer.hpp"

Serializer::Serializer() {
	std::cout << "Default serializer was created" << std::endl << std::endl;
}

Serializer::Serializer(const Serializer &src) {
	std::cout << "Serializer copy constructor called" << std::endl;
	*this = src;
}

Serializer::~Serializer() {
	std::cout << "Serializer was destroyed" << std::endl;
}

Serializer &Serializer::operator=(const Serializer &src) {
	std::cout << "Serializer assignation operator called" << std::endl;
	if (this == &src)
		return (*this);
	return (*this);
}

uintptr_t	Serializer::serialize(Data *ptr) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data	*Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}