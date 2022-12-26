/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 16:01:25 by rmazurit          #+#    #+#             */
/*   Updated: 2022/12/24 16:01:25 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Converter.hpp"

int main (int argc, char **argv) {

	if (argc != 2) {
		std::cout << "Enter a number to convert" << std::endl;
		return (0);
	}

	std::string input;
	input = argv[1];
	Converter	converter(input);

	return (0);
}
