/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 19:55:01 by rmazurit          #+#    #+#             */
/*   Updated: 2022/12/23 19:55:01 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Intern.hpp"

Intern::Intern() {
	std::cout << "Intern was created" << std::endl;
}

Intern::Intern(const Intern &src) {
	std::cout << "Intern copy constructor called" << std::endl;
	*this = src;
}

Intern::~Intern() {
	std::cout << "Intern was destroyed" << std::endl;
}

Intern &Intern::operator=(const Intern &src) {
	std::cout << "Intern assignation operator called" << std::endl;
	(void)src;
	return (*this);
}

static ShrubberyCreationForm	*create_shrubbery_form(std::string &target) {
	ShrubberyCreationForm	*shrub;

	shrub = new ShrubberyCreationForm(target);
	if (!shrub) {
		std::cout << "Fatal error. Memory allocation failed" << std::endl;
		return (NULL);
	}
	return (shrub);
}

static RobotomyRequestForm	*create_robot_form(std::string &target) {
	RobotomyRequestForm	*rob;

	rob = new RobotomyRequestForm(target);
	if (!rob) {
		std::cout << "Fatal error. Memory allocation failed" << std::endl;
		return (NULL);
	}
	return (rob);
}

static PresidentialPardonForm	*create_presidential_form(std::string &target) {
	PresidentialPardonForm	*pres;

	pres = new PresidentialPardonForm(target);
	if (!pres) {
		std::cout << "Fatal error. Memory allocation failed" << std::endl;
		return (NULL);
	}
	return (pres);
}

AForm	*Intern::makeForm(std::string &name, std::string &target) {

	AForm *(*forms[3])(std::string target) = {	reinterpret_cast<AForm *(*)(std::string)>(&create_shrubbery_form),
											 	reinterpret_cast<AForm *(*)(std::string)>(&create_robot_form),
											 	reinterpret_cast<AForm *(*)(std::string)>(&create_presidential_form)};

	std::string form_names[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};

	for (int i = 0; i < 3; i++)
	{
		if (name == form_names[i]) {
			std::cout << "Intern successfully created " << name << std::endl;
			return (forms[i](target));
		}
	}
	std::cout << "No form matches the specified name " << std::endl;
	return (NULL);
}
