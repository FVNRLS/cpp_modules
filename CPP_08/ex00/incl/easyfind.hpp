/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 12:49:53 by rmazurit          #+#    #+#             */
/*   Updated: 2022/12/28 12:49:53 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>

template <typename T>

int easyfind(T container, int value) {
	typename T::iterator it;

	for (it = container.begin(); it != container.end(); ++it) {
		if (*it == value)
			return std::distance(container.begin(), it);
	}
	return (-1);
}



