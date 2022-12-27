/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 19:50:29 by rmazurit          #+#    #+#             */
/*   Updated: 2022/12/26 19:50:29 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "iostream"

template<typename S>

void	swap(S &x, S &y) {
	S temp = x;
	x = y;
	y = temp;
}

template<class X>

const X	&max(const X &x, const X &y) {
	if (x > y)
		return (x);
	else
		return (y);
}

template<typename N>

const N	&min(const N &x, const N &y) {
	if (x < y)
		return (x);
	else
		return (y);
}
