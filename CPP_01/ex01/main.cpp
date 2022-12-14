/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:15:05 by rmazurit          #+#    #+#             */
/*   Updated: 2022/11/25 13:15:05 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
	Zombie 		*horde;
	const int	N = 5;

	horde = zombieHorde(N, "Gosha");

	for (int i = 0; i < N; i++)
		horde[i].announce();
	delete [] horde;
	return (0);
}
