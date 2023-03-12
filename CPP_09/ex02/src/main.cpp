/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 17:51:07 by rmazurit          #+#    #+#             */
/*   Updated: 2023/03/12 17:51:07 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int argc, char **argv) {
	if (argc < 2) {
		std::cout << "Error: Invalid number of arguments" << std::endl;
		return EXIT_FAILURE;
	}
	PmergeMe sorter(argv);
	if (sorter.compare_containers() == EXIT_FAILURE)
		return EXIT_FAILURE;
	return EXIT_SUCCESS;
}