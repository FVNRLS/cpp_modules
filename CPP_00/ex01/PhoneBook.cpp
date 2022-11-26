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

PhoneBook::PhoneBook() : _contacts(), _index(0), _items(0) {
	return ;
}

PhoneBook::~PhoneBook() {
	return ;
}

//MAIN FUNCTIONS
void	PhoneBook::add() {
	Contact	contact;

	if (_index == NUM_CONTACTS)
		_index = 0;
	_contacts[_index].set_contact(_index);
	_index++;
	if (_items < NUM_CONTACTS)
		_items++;
}

void	PhoneBook::search()  {
	int		i;

	if (_items == 0) {
		std::cout << "The phonebook is empty" << std::endl;
		return ;
	}
	this->display_all_contacts();
	i = this->get_index();
	if (i < 0)
		return ;
	else if (i < NUM_CONTACTS) {
		std::cout << "Name:		" << _contacts[i].get_name() << std::endl;
		std::cout << "Family Name:	" << _contacts[i].get_surname() << std::endl;
		std::cout << "Nickname:	" << _contacts[i].get_nickname() << std::endl;
		std::cout << "Phone:		" << _contacts[i].get_phone() << std::endl;
		std::cout << "Darkest Secret:	" << _contacts[i].get_darkest_secret() << std::endl;
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
	if (i <= 0 || i > _items) {
		std::cout << "Contact not found " << std::endl;
		return (-1);
	}
	else
		return (i - 1);
}

void	PhoneBook::display_all_contacts() const {
	std::cout << "|Index     |First Name|Last Name |Nickname  |" << std::endl;
	for (int i = 0; i < _items; i++) {
		display_contact(_contacts[i]);
	}
}

void	PhoneBook::display_contact(const Contact &contact) {
	std::cout << "|";
	print_info(contact.get_id());
	print_info(contact.get_name());
	print_info(contact.get_surname());
	print_info(contact.get_nickname());
	std::cout << std::endl;
}

void 	PhoneBook::print_info(const std::string &str) {
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

