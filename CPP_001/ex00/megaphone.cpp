/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 11:30:27 by rmazurit          #+#    #+#             */
/*   Updated: 2022/11/20 11:30:27 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(int argc, char **argv) {
	int i;

	if (argc == 1){
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE * " << std::endl;
		return (EXIT_SUCCESS);
	}
	i = 0;
	while (argv[i] != nullptr)
	{
		for (int j = 0; j < (int)strlen(argv[i]); j++)
			std::cout << toupper(argv[i][j]);
		i++;
	}
	std::cout << std::endl;

	return (EXIT_SUCCESS);
}
