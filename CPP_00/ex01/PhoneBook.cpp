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
	phonebook_empty = true;
}

PhoneBook::~PhoneBook() {
}

//TODO: test with multiple data!
void	PhoneBook::add() {
	Contact	contact;

	if (this->index == NUM_CONTACTS)
		this->index = 0;
	this->contacts[this->index].set_contact(this->index);
	this->index++;
	phonebook_empty = false;
}

void	PhoneBook::search() const {

	int		i;
	bool 	index_undefined;

	index_undefined = true;
	while (index_undefined) {
		i = this->get_index();
		if (i == -1) {
			std::cout << "|Index     |First Name|Last Name |Nickname  |"
					  << std::endl;
			this->display_all_contacts();
			index_undefined = false;
		}
		else if (i >= 0 && i < NUM_CONTACTS) {
			std::cout << "|Index     |First Name|Last Name |Nickname  |"
					  << std::endl;
			display_contact(this->contacts[i]);
			index_undefined = false;
		}
	}
}

int	PhoneBook::get_index() const {
	std::string	input;
	int 		i;

	i = -1;

	while (i == -1) {
		std::cout << "Enter Contact Index:		";
		std::getline(std::cin, input);
		try {
			i = std::stoi(input);
		}
		catch (const std::invalid_argument &arg) {
			if (input.length() == 0)
				return (-1);
			std::cout << "Error. Invalid argument " << std::endl;
			continue ;
		}
		catch (const std::out_of_range &arg) {
			std::cout << "Error. Invalid argument " << std::endl;
			continue ;
		}
		if (i >= input.length() || this->phonebook_empty) {
			std::cout << "Error. Invalid argument " << std::endl;
			i = -1;
		}
	}
	return (i);
}

void	PhoneBook::display_all_contacts() const {
	for (int i = 0; i < this->index; i++) {
		display_contact(this->contacts[i]);
	}
}

void	PhoneBook::display_contact(const Contact &contact) const {
//	std::cout << std::endl;
	std::cout << "|";
	this->print_info(contact.get_id());
	this->print_info(contact.get_name());
	this->print_info(contact.get_surname());
	this->print_info(contact.get_nickname());
	std::cout << std::endl;
}

void 	PhoneBook::print_info(const std::string &str) const {
	size_t	len;

	len = str.length();
	if (len <= MAX_STR_LEN) {
		for (; len < MAX_STR_LEN; len++)
			std::cout << " ";
		std::cout << str.substr(0, len);
	}
	else
		std::cout << str.substr(0, MAX_STR_LEN - 1) << ".";
	std::cout << "|";
}

