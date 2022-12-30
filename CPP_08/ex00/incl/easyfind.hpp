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
#include <algorithm>

template <typename T>

int easyfind(T container, int val) {
	int pos;
	typename T::iterator it;

	it = std::find(container.begin(), container.end(), val);
	pos = std::distance(container.begin(), it);
	return (pos);
}



