/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:14:26 by rmazurit          #+#    #+#             */
/*   Updated: 2022/11/25 13:14:26 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main() {
	std::cout << std::endl;

	std::string	str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "Memory address string:		" << &str << std::endl;
	std::cout << "Memory address pointer:		" << stringPTR << std::endl;
	std::cout << "Memory address reference:	" << &stringREF << std::endl;

	std::cout << std::endl;

	std::cout << "Value string:			" << str << std::endl;
	std::cout << "Value pointer:			" << *stringPTR << std::endl;
	std::cout << "Value reference:		" << stringREF << std::endl;

	return (0);
}