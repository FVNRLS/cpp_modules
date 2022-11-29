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

int	main(int argc, char **argv) {
	Harl		harl;
	std::string msg;

	if (argc < 2 || argc > 3)
	{
		harl.complain("WRONG_MESSAGE");
		return (1);
	}
	msg = argv[1];
	harl.complain(msg);
	return (0);
}
