/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:32:46 by rmazurit          #+#    #+#             */
/*   Updated: 2022/12/27 15:32:46 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/iter.hpp"

void	increment(int &num) {
	num += 1;
}

void	to_upper(char &c) {
	c = std::toupper(c);
}

//template printer function - just for better visualisation
template <typename T>

void print_tab(T *tab) {
	for (int i = 0; i < 5; i++) {
		if (i < 4)
			std::cout << tab[i] << ", ";
		else
			std::cout << tab[i];
	}
	std::cout << " }" << std::endl;
}

int main() {
	std::cout << std::endl << "\033[33m****** TESTING WITH ARRAY OF INTEGERS *******\033[0m" << std::endl;
	int tab[5] = {1, 2, 3, 4, 5};

	std::cout << "Init values:	{ ";
	print_tab(tab);
	iter(tab, 5, increment);
	std::cout << "After iter:	{ ";
	print_tab(tab);

	std::cout << std::endl << "\033[33m****** TESTING WITH ARRAY OF CHARS *******\033[0m" << std::endl;
	char char_tab[5] = {'a', 'b', 'c', 'D', '!'};

	std::cout << "Init values:	{ ";
	print_tab(char_tab);
	iter(char_tab, 5, to_upper);
	std::cout << "After iter:	{ ";
	print_tab(char_tab);

	return (0);
}