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

PhoneBook::PhoneBook() : _contacts() {
	this->index = 0;
	this->items = 0;
}

PhoneBook::~PhoneBook() {
	return;
}

//GETTERS
bool	PhoneBook::get_is_empty_flag() const {
	return (this->_is_empty);
}

bool	PhoneBook::get_is_closed_flag() const {
	return (this->_is_closed);
}

//SETTERS
void	PhoneBook::set_is_empty_flag(bool flag) {
	this->_is_empty = flag;
}

void	PhoneBook::set_is_closed_flag(bool flag) {
	this->_is_closed = flag;
}

//MAIN FUNCTIONS
void	PhoneBook::add() {
	Contact	contact;

	if (this->index == NUM_CONTACTS)
		this->index = 0;
	if (this->_contacts[this->index].set_contact(this->index) == 1) {
		set_is_closed_flag(true);
		return ;
	}
	this->index++;
	if (this->items < NUM_CONTACTS)
		this->items++;
	set_is_empty_flag(false);
}

void	PhoneBook::search()  {
	int		i;

	if (this->get_is_empty_flag() == true) {
		std::cout << "The phonebook is empty" << std::endl;
		return ;
	}
	this->display_all_contacts();
	i = this->get_index();
	if (i == -2) {
		set_is_closed_flag(true);
		return ;
	}
	else if (i == -1) {
		return ;
	}
	else if (i < NUM_CONTACTS) {
		std::cout << "Name:		" << this->_contacts[i].get_name() << std::endl;
		std::cout << "Family Name:	" << this->_contacts[i].get_surname() << std::endl;
		std::cout << "Nickname:	" << this->_contacts[i].get_nickname() << std::endl;
		std::cout << "Phone:		" << this->_contacts[i].get_phone() << std::endl;
		std::cout << "Darkest Secret:	" << this->_contacts[i].get_darkest_secret() << std::endl;
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
	if (i <= 0 || i > this->items || get_is_empty_flag() == true) {
		std::cout << "Contact not found " << std::endl;
		return (-1);
	}
	else
		return (i - 1);
}

void	PhoneBook::display_all_contacts() const {
	std::cout << "|Index     |First Name|Last Name |Nickname  |" << std::endl;
	for (int i = 0; i < this->items; i++) {
		display_contact(this->_contacts[i]);
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

