/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 19:04:12 by rmazurit          #+#    #+#             */
/*   Updated: 2022/12/18 19:04:12 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ShrubberyCreationForm.hpp"
#include "../incl/RobotomyRequestForm.hpp"
#include "../incl/PresidentialPardonForm.hpp"

#define GRADE	5

int main() {
	//TESTING CONSTRUCTION
	std::cout << "\033[33m****** TESTING CONSTRUCTION BUREAUCRAT *******\033[0m" << std::endl;
	Bureaucrat *bureaucrat;

	bureaucrat = NULL;
	try {
		bureaucrat = new Bureaucrat(GRADE);
		std::cout << bureaucrat << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &exception) {
		std::cerr << "Bureaucrat instantiation failed: init grade " << GRADE << exception.txt_except() << std::endl;
		return (1);
	}
	catch (Bureaucrat::GradeTooLowException &exception) {
		std::cerr << "Bureaucrat instantiation failed: init grade " << GRADE << exception.txt_except() << std::endl;
		return (1);
	}

	//CONSTRUCTING FORMS
	std::string	shrubbery_name = "tree";
	ShrubberyCreationForm shrubbery(shrubbery_name);
	std::cout << &shrubbery;

	std::cout << std::endl;

	std::string	robot_name = "future_robot";
	RobotomyRequestForm	robot(robot_name);
	std::cout << &robot;

	std::cout << std::endl;

	std::string	pres_name = "president";
	PresidentialPardonForm president(pres_name);
	std::cout << &president;

	//SHRUBBERY
	std::cout << std::endl << "\033[33m****** TESTING SHRUBBERY *******\033[0m" << std::endl;
	try {
		bureaucrat->sign_form(shrubbery);
	}
	catch (ShrubberyCreationForm::GradeTooLowException &exception) {
		std::cerr << bureaucrat->get_name() << " couldn’t sign ShrubberyCreationForm, because his "
				  << exception.txt_except() << std::endl;
	}
//	try {
//		bureaucrat->sign_form(shrubbery);
//	}
//	catch (ShrubberyCreationForm::GradeTooLowException &exception) {
//		std::cerr << bureaucrat->get_name() << " couldn’t sign ShrubberyCreationForm, because his "
//				  << exception.txt_except() << std::endl;
//	}
	try {
		bureaucrat->execute_form(shrubbery);
	}
	catch (ShrubberyCreationForm::GradeTooLowException &exception) {
		std::cerr << bureaucrat->get_name() << " couldn’t execute ShrubberyCreationForm, because his "
				  << exception.txt_except() << std::endl;
	}

	//ROBOTOMY
	std::cout << std::endl << "\033[33m****** TESTING ROBOTOMY *******\033[0m" << std::endl;
	try {
		bureaucrat->sign_form(robot);
	}
	catch (RobotomyRequestForm::GradeTooLowException &exception) {
		std::cerr << bureaucrat->get_name() << " couldn’t sign RobotomyRequestForm, because his "
				  << exception.txt_except() << std::endl;
	}
	try {
		bureaucrat->execute_form(robot);
	}
	catch (RobotomyRequestForm::GradeTooLowException &exception) {
		std::cerr << "Robotomy failed for " << bureaucrat->get_name() << ", because his "
				  << exception.txt_except() << std::endl;
	}

	//PRESIDENT
	std::cout << std::endl << "\033[33m****** TESTING PRESIDENTIAL PARDON *******\033[0m" << std::endl;
	try {
		bureaucrat->sign_form(president);
	}
	catch (PresidentialPardonForm::GradeTooLowException &exception) {
		std::cerr << bureaucrat->get_name() << " couldn’t sign PresidentialPardonForm, because his "
				  << exception.txt_except() << std::endl;
	}
	try {
		bureaucrat->execute_form(president);
	}
	catch (PresidentialPardonForm::GradeTooLowException &exception) {
		std::cerr << bureaucrat->get_name() << " couldn’t execute PresidentialPardonForm, because his "
				  << exception.txt_except() << std::endl;
	}

	std::cout << std::endl;

	//DESTRUCTION
	std::cout << "\033[33m****** DESTRUCTION *******\033[0m" << std::endl;
	if (bureaucrat != NULL) {
		delete bureaucrat;
	}

//	system("leaks ex02");
	return (0);
}
