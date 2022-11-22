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
	this->items = 0;
	is_empty = true;
}

PhoneBook::~PhoneBook() {
}

void	PhoneBook::add() {
	Contact	contact;

	if (this->index == NUM_CONTACTS)
		this->index = 0;
	if (this->contacts[this->index].set_contact(this->index) == 1) {
		this->is_closed = true;
		return ;
	}
	this->index++;
	if (this->items < NUM_CONTACTS)
		this->items++;
	is_empty = false;
}

void	PhoneBook::search()  {
	int		i;

	if (this->is_empty) {
		std::cout << "The phonebook is empty" << std::endl;
		return ;
	}
	this->display_all_contacts();
	i = this->get_index();
	if (i == -2) {
		this->is_closed = true;
		return ;
	}
	else if (i == -1) {
		return ;
	}
	else if (i < NUM_CONTACTS) {
		std::cout << "Name:		" << this->contacts[i].get_name() << std::endl;
		std::cout << "Family Name:	" << this->contacts[i].get_surname() << std::endl;
		std::cout << "Nickname:	" << this->contacts[i].get_nickname() << std::endl;
		std::cout << "Phone:		" << this->contacts[i].get_phone() << std::endl;
		std::cout << "Darkest Secret:	" << this->contacts[i].get_darkest_secret() << std::endl;
		return ;
	}
}

int	PhoneBook::get_index() const {
	std::string	input;
	int 	i;

	std::cout << "Enter Contact Index:	";
	std::getline(std::cin, input);
	if (std::cin.eof())
		return (-2);
	i = std::atoi(input.c_str());
	if (i <= 0 || i > this->items || this->is_empty) {
		std::cout << "Contact not found " << std::endl;
		return (-1);
	}
	else
		return (i - 1);
}

void	PhoneBook::display_all_contacts() const {
	std::cout << "|Index     |First Name|Last Name |Nickname  |" << std::endl;
	for (int i = 0; i < this->items; i++) {
		display_contact(this->contacts[i]);
	}
}

void	PhoneBook::display_contact(const Contact &contact) const {
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

