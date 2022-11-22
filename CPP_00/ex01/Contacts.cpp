/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 14:40:50 by rmazurit          #+#    #+#             */
/*   Updated: 2022/11/22 17:16:18 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include "Contacts.hpp"

Contact::Contact() {
	return ;
}

Contact::~Contact() {
	return ;
}

int	Contact::set_contact(int id) {
	set_id(id);
	if (set_name() == 1)
		return (1);
	if (set_surname() == 1)
		return (1);
	if (set_nickname() == 1)
		return (1);
	if (set_phone() == 1)
		return (1);
	if (set_darkest_secret() == 1)
		return (1);
	return (0);
}

//SETTERS
void	Contact::set_id(int id) {
	std::stringstream tmp;

	tmp << id + 1;
	this->_id = tmp.str();
}

int	Contact::set_name() {
	this->_name.clear();
	while (this->_name.length() == 0) {
		std::cout << "Enter your Name:		";
		std::getline(std::cin, this->_name);
		if (std::cin.eof())
			return (1);
		if (this->_name.length() == 0)
			std::cout << "Field Can't Be Empty!" << std::endl;
	}
	return (0);
}

int	Contact::set_surname() {
	this->_surname.clear();
	while (this->_surname.length() == 0) {
		std::cout << "Enter your Family Name:		";
		std::getline(std::cin, this->_surname);
		if (std::cin.eof())
			return (1);
		if (this->_surname.length() == 0)
			std::cout << "Field Can't Be Empty!" << std::endl;
	}
	return (0);
}

int	Contact::set_nickname() {
	this->_nickname.clear();
	while (this->_nickname.length() == 0) {
		std::cout << "Enter your Nickname:		";
		std::getline(std::cin, this->_nickname);
		if (std::cin.eof())
			return (1);
		if (this->_nickname.length() == 0)
			std::cout << "Field Can't Be Empty!" << std::endl;
	}
	return (0);
}

int	Contact::set_phone() {
	this->_phone.clear();
	while (this->_phone.length() == 0) {
		std::cout << "Enter your Phone:		";
		std::getline(std::cin, this->_phone);
		if (std::cin.eof())
			return (1);
		if (this->_phone.length() == 0)
			std::cout << "Field Can't Be Empty!" << std::endl;
	}
	return (0);
}

int	Contact::set_darkest_secret() {
	this->_darkest_secret.clear();
	while (this->_darkest_secret.length() == 0) {
		std::cout << "Enter your Darkest Secret:	";
		std::getline(std::cin, this->_darkest_secret);
		if (std::cin.eof())
			return (1);
		if (this->_darkest_secret.length() == 0)
			std::cout << "Field Can't Be Empty!" << std::endl;
	}
	return (0);
}

//GETTERS
std::string Contact::get_id() const {
	return (this->_id);
}

std::string	Contact::get_name() const {
	return (this->_name);
}

std::string	Contact::get_surname() const {
	return (this->_surname);
}

std::string Contact::get_nickname() const {
	return (this->_nickname);
}

std::string	Contact::get_phone() const {
	return (this->_phone);
}

std::string Contact::get_darkest_secret() const {
	return (this->_darkest_secret);
}