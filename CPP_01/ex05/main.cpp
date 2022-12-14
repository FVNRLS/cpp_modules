/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 13:31:43 by rmazurit          #+#    #+#             */
/*   Updated: 2022/11/26 13:31:43 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main() {

	Harl		harl;
	std::string input;

	harl.complain("ERROR");
	harl.complain("WARNING");
	harl.complain("INFO");
	harl.complain("DEBUG");
	harl.complain("WRONG_MESSAGE");
	std::cout << std::endl;

	while (true)
	{
		std::cout << "Enter a message or press ctrl+D to exit:	";
		getline(std::cin, input);
		if (std::cin.eof())
			break ;
		harl.complain(input);
	}
	return (EXIT_SUCCESS);
}
