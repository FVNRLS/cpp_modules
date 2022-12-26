/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:47:36 by rmazurit          #+#    #+#             */
/*   Updated: 2022/12/26 16:47:36 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "iostream"

typedef struct Data {
	std::string	name;
	int			age;
}	Data;

class Serializer {

public:
	Serializer();
	Serializer(const Serializer &src);
	~Serializer();

	Serializer &operator=(const Serializer &src);

	uintptr_t	serialize(Data *ptr);
	Data 		*deserialize(uintptr_t raw);
};