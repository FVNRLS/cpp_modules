/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 14:46:15 by rmazurit          #+#    #+#             */
/*   Updated: 2022/11/20 14:46:15 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main() {

	PhoneBook	phonebook;
	std::string	line;


	phonebook.set_is_empty_flag(true);
	phonebook.set_is_closed_flag(false);
	while (phonebook.get_is_closed_flag() == false) {
		std::cout << "PHONEBOOK: ";
		std::getline(std::cin, line);
		if (std::cin.eof())
			break ;
		if (line == "ADD")
			phonebook.add();
		else if (line == "SEARCH")
			phonebook.search();
		else if (line == "EXIT")
			phonebook.set_is_closed_flag(true);
	}
	return (0);
}



