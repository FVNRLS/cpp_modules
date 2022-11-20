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

	while (this->_name.length() == 0){
		std::cout << "Enter your Name:		";
		std::getline(std::cin, this->_name);
		if (this->_name.length() == 0)
			std::cout << "Field Can't Be Empty!" << std::endl;
	}
}

//SETTERS
void	Contact::set_id(int id) {
	this->_id = std::to_string(id);
}




//GETTERS
std::string Contact::get_id(void) const{
	return (this->_id);
}

std::string	Contact::get_name(void) const{
	return (this->_name);
}

std::string	Contact::get_surname(void) const{
	return (this->_surname);
}

std::string Contact::get_nickname(void) const{
	return (this->_nickname);
}

std::string	Contact::get_phone(void) const{
	return (this->_phone);
}

std::string Contact::get_darkest_secret(void) const {
	return (this->_darkest_secret);
}