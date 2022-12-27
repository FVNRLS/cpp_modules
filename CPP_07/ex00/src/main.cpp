/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 19:45:58 by rmazurit          #+#    #+#             */
/*   Updated: 2022/12/26 19:45:58 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/whatever.hpp"

int main() {


	std::cout << std::endl << "\033[33m****** TESTING INTEGER SWAP *******\033[0m" << std::endl;
	int x_int = 5;
	int y_int = 3;

	std::cout << "Init values:" << std::endl << "x:	" << x_int << std::endl << "y:	" << y_int << std::endl << std::endl;
	swap(x_int, y_int);
	std::cout << "Swapped values:" << std::endl << "x:	" << x_int << std::endl << "y:	" << y_int << std::endl;

	std::cout << std::endl << "\033[33m****** TESTING CHAR SWAP *******\033[0m" << std::endl;
	char x_ch = 'a';
	char y_ch = 'z';

	std::cout << "Init values:" << std::endl << "x:	" << x_ch << std::endl << "y:	" << y_ch << std::endl << std::endl;
	swap<char>(x_ch, y_ch);
	std::cout << "Swapped values:" << std::endl << "x:	" << x_ch << std::endl << "y:	" << y_ch << std::endl;


	std::cout << std::endl << "\033[33m****** TESTING MAX *******\033[0m" << std::endl;
	std::cout << "Init values:" << std::endl << "x:	" << x_int << std::endl << "y:	" << y_int << std::endl << std::endl;
	std::cout << "Max value:	" << max(x_int, y_int) << std::endl;

	std::cout << std::endl << "\033[33m****** TESTING MIN *******\033[0m" << std::endl;
	std::cout << "Init values:" << std::endl << "x:	" << x_int << std::endl << "y:	" << y_int << std::endl << std::endl;
	std::cout << "Min value:	" << min(x_int, y_int) << std::endl;

	return (0);
}