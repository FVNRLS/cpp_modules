/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:54:59 by rmazurit          #+#    #+#             */
/*   Updated: 2022/12/28 17:54:59 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Span.hpp"

#define MAX 10000

int	main () {
	srand(time(NULL));
	int rand_num;

	std::cout << "\033[33m****** CONSTRUCTOR *******\033[0m" << std::endl;
	Span	span(MAX);

	std::cout << std::endl << "\033[33m****** TESTING ADD NUMBER *******\033[0m" << std::endl;
	try {
		for (int i = 0; i < MAX; i++) {
			rand_num = rand() % 201 - 100;

			span.add_number(rand_num);
			std::cout << "Adding number	" << rand_num << std::endl;
		}
//		span.add_number(rand_num); //uncomment to overflow the container
	}
	catch (const std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl << "\033[33m****** TESTING SHORTEST SPAN *******\033[0m" << std::endl;
	try {
		int shortest_span = span.shortest_span();
		std::cout << "The shortest span is " << shortest_span << std::endl;
	}
	catch (const std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl << "\033[33m****** TESTING LONGEST SPAN *******\033[0m" << std::endl;
	try {
		int longest_span = span.longest_span();
		std::cout << "The longest span is " << longest_span << std::endl;
	}
	catch (const std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl << "\033[33m****** DESTRUCTOR *******\033[0m" << std::endl;

	return (0);
}
