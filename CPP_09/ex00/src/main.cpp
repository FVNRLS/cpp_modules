/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:01:55 by rmazurit          #+#    #+#             */
/*   Updated: 2023/03/09 17:01:55 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
	std::string	file_path;

	if (argc != 2)
		std::cout << "Error: Invalid number of arguments" << std::endl;
	file_path = argv[1];

	BitcoinExchanger	btc_exc(file_path);
	if (btc_exc.exchange() == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
