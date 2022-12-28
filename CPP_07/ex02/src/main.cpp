/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:22:32 by rmazurit          #+#    #+#             */
/*   Updated: 2022/12/27 16:22:32 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Array.hpp"

//void print_array(array)

#define NUM	10

int main() {

	std::cout << std::endl << "\033[31m****** TESTING WITH INTEGERS *******\033[0m" << std::endl;
	{
		std::cout << std::endl << "\033[33m****** TESTING DEFAULT CONSTRUCTOR *******\033[0m" << std::endl;
		Array<int> def_array;

		std::cout << std::endl << "\033[33m****** TESTING PARAMETERISED CONSTRUCTOR *******\033[0m" << std::endl;
		Array<int> array(10);
		for (int i = 0; i < NUM; i++) {
			array[i] = i;
			std::cout << array[i] << " ";
		}
		std::cout << std::endl;

		std::cout << std::endl << "\033[33m****** TESTING COPY CONSTRUCTOR *******\033[0m" << std::endl;
		Array<int> copy(array);

		std::cout << std::endl << "Copied values:" << std::endl;
		for (int i = 0; i < NUM; i++) {
			std::cout << copy[i] << " ";
		}
		std::cout << std::endl;

		std::cout << std::endl << "Changed values:" << std::endl;
		for (int i = 0; i < NUM; i++) {
			copy[i]++;
			std::cout << copy[i] << " ";
		}

		std::cout << std::endl;
		std::cout << std::endl << "\033[33m****** TESTING DESTRUCTOR*******\033[0m" << std::endl << std::endl;
	}

	std::cout << std::endl << "\033[31m****** TESTING WITH CHARS *******\033[0m" << std::endl;
	{
		std::cout << std::endl << "\033[33m****** TESTING DEFAULT CONSTRUCTOR *******\033[0m" << std::endl;
		Array<char> def_array;

		std::cout << std::endl << "\033[33m****** TESTING PARAMETERISED CONSTRUCTOR *******\033[0m" << std::endl;
		Array<char> array(10);
		for (int i = 0; i < NUM; i++) {
			array[i] = 'a' + i;
			std::cout << array[i] << " ";
		}
		std::cout << std::endl;

		std::cout << std::endl << "\033[33m****** TESTING COPY CONSTRUCTOR *******\033[0m" << std::endl;
		Array<char> copy(array);

		std::cout << std::endl << "Copied values:" << std::endl;
		for (int i = 0; i < NUM; i++) {
			std::cout << copy[i] << " ";
		}
		std::cout << std::endl;

		std::cout << std::endl << "Changed values:" << std::endl;
		for (int i = 0; i < NUM; i++) {
			copy[i]++;
			std::cout << copy[i] << " ";
		}
		std::cout << std::endl << "Trying to access index out of range:" << std::endl;
		try {
			std::cout << copy[NUM + 1] << std::endl;
		}
		catch (const std::exception &e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}

		std::cout << std::endl;
		std::cout << std::endl << "\033[33m****** TESTING DESTRUCTOR*******\033[0m" << std::endl << std::endl;
	}

//	system("leaks ex02");

	return (0);
}
