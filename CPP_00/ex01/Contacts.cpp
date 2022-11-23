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

void	Contact::set_contact(int id) {
	set_id(id);
	set_name();
	if (!std::cin.eof())
		set_surname();
	if (!std::cin.eof())
		set_nickname();
	if (!std::cin.eof())
		set_phone();
	if (!std::cin.eof())
		set_darkest_secret();
}

//SETTERS
void	Contact::set_id(int id) {
	std::stringstream tmp;

	tmp << id + 1;
	this->_id = tmp.str();
}

void	Contact::set_name() {
	_name.clear();
	while (_name.length() == 0) {
		std::cout << "Enter your Name:		";
		std::getline(std::cin, _name);
		if (std::cin.eof())
			return ;
		if (_name.length() == 0)
			std::cout << "Field Can't Be Empty!" << std::endl;
	}
}

void	Contact::set_surname() {
	_surname.clear();
	while (_surname.length() == 0) {
		std::cout << "Enter your Family Name:		";
		std::getline(std::cin, _surname);
		if (std::cin.eof())
			return ;
		if (_surname.length() == 0)
			std::cout << "Field Can't Be Empty!" << std::endl;
	}
}

void 	Contact::set_nickname() {
	_nickname.clear();
	while (_nickname.length() == 0) {
		std::cout << "Enter your Nickname:		";
		std::getline(std::cin, _nickname);
		if (std::cin.eof())
			return ;
		if (_nickname.length() == 0)
			std::cout << "Field Can't Be Empty!" << std::endl;
	}
}

void	Contact::set_phone() {
	_phone.clear();
	while (_phone.length() == 0) {
		std::cout << "Enter your Phone:		";
		std::getline(std::cin, _phone);
		if (std::cin.eof())
			return ;
		if (_phone.length() == 0)
			std::cout << "Field Can't Be Empty!" << std::endl;
	}
}

void	Contact::set_darkest_secret() {
	_darkest_secret.clear();
	while (_darkest_secret.length() == 0) {
		std::cout << "Enter your Darkest Secret:	";
		std::getline(std::cin, _darkest_secret);
		if (std::cin.eof())
			return ;
		if (_darkest_secret.length() == 0)
			std::cout << "Field Can't Be Empty!" << std::endl;
	}
}

//GETTERS
std::string Contact::get_id() const {
	return (_id);
}

std::string	Contact::get_name() const {
	return (_name);
}

std::string	Contact::get_surname() const {
	return (_surname);
}

std::string Contact::get_nickname() const {
	return (_nickname);
}

std::string	Contact::get_phone() const {
	return (_phone);
}

std::string Contact::get_darkest_secret() const {
	return (_darkest_secret);
}