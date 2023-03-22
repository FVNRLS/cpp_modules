/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 12:53:43 by rmazurit          #+#    #+#             */
/*   Updated: 2023/03/12 12:53:43 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv) {
	std::string	input;
	if (argc != 2) {
		std::cout << "Error: Invalid number of arguments" << std::endl;
		return EXIT_FAILURE;
	}
	input = argv[1];
	if (input.empty()) {
		std::cout << "Error: invalid input" << std::endl;
		return EXIT_FAILURE;
	}
	RPN	rpn(input);
	if (rpn.calculate() == EXIT_FAILURE)
		return EXIT_FAILURE;
	return EXIT_SUCCESS;
}