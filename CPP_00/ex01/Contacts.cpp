/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 14:40:50 by rmazurit          #+#    #+#             */
/*   Updated: 2022/11/20 14:40:50 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contacts.hpp"

Contact::Contact() {
	return ;
}

Contact::~Contact() {
	return ;
}

void	Contact::set_contact(int id) {

	set_id(id);
	set_name();
	set_surname();
	set_nickname();
	set_phone();
	set_darkest_secret();
}

//SETTERS
void	Contact::set_id(int id) {
	this->_id = std::to_string(id);
}

void	Contact::set_name() {
	while (this->_name.length() == 0) {
		std::cout << "Enter your Name:			";
		std::getline(std::cin, this->_name);
		if (this->_name.length() == 0)
			std::cout << "Field Can't Be Empty!" << std::endl;
	}
}

void	Contact::set_surname() {
	while (this->_surname.length() == 0) {
		std::cout << "Enter your Family Name:		";
		std::getline(std::cin, this->_surname);
		if (this->_surname.length() == 0)
			std::cout << "Field Can't Be Empty!" << std::endl;
	}
}

void	Contact::set_nickname() {
	while (this->_nickname.length() == 0) {
		std::cout << "Enter your Nickname:		";
		std::getline(std::cin, this->_nickname);
		if (this->_nickname.length() == 0)
			std::cout << "Field Can't Be Empty!" << std::endl;
	}
}

void	Contact::set_phone() {
	while (this->_phone.length() == 0) {
		std::cout << "Enter your Phone:			";
		std::getline(std::cin, this->_phone);
		if (this->_phone.length() == 0)
			std::cout << "Field Can't Be Empty!" << std::endl;
	}
}

void	Contact::set_darkest_secret() {
	while (this->_darkest_secret.length() == 0) {
		std::cout << "Enter your Darkest Secret:	";
		std::getline(std::cin, this->_darkest_secret);
		if (this->_darkest_secret.length() == 0)
			std::cout << "Field Can't Be Empty!" << std::endl;
	}
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