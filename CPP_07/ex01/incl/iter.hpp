/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:33:28 by rmazurit          #+#    #+#             */
/*   Updated: 2022/12/27 15:33:28 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename T>

void	iter(T *array, int len, void (*func)(T &)) {
	if (!array || !func)
		return;
	for (int i = 0; i < len; i++) {
		func(array[i]);
	}
}