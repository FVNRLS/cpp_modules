/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 14:48:07 by rmazurit          #+#    #+#             */
/*   Updated: 2022/11/20 14:48:07 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : contacts() {
	this->index = 0;
}

PhoneBook::~PhoneBook(){
}

void	PhoneBook::display_contact(const Contact &contact) const{
	std::cout << std::endl;
	std::cout << "|Index     |First Name|Last Name |Nickname  |\n";

	std::cout << contact.get_id();
	std::cout << contact.get_name();
	std::cout << contact.get_surname();
	std::cout << contact.get_nickname();
	std::cout << std::endl;
}

void	PhoneBook::display_all_contacts() const {
	for (int i = 0; i < 8; this->index) {
		display_contact(this->contacts[i]);
	}

}

void	PhoneBook::add(){

}

void	PhoneBook::search(){

}

