/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 14:11:45 by rmazurit          #+#    #+#             */
/*   Updated: 2022/12/28 14:11:45 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/easyfind.hpp"

int main() {
	std::vector<int> v;

	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	unsigned int pos = easyfind(v, 3);
	if (pos == v.size())
		std::cout << "Item not found" << std::endl;
	else
		std::cout << "Item found at position " << pos << std::endl;

	return 0;
}
