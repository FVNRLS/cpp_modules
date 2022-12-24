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

#include "../incl/Intern.hpp"

#define GRADE	5

int main() {
//TESTING CONSTRUCTION
	std::cout << "\033[33m****** TESTING CONSTRUCTION *******\033[0m" << std::endl;

	Bureaucrat	*bureaucrat = NULL;
	AForm		*form = NULL;
	Intern		intern;

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

	std::cout << std::endl << "\033[33m****** MAKING A FORM BY INTERN *******\033[0m" << std::endl;
	std::string	name;
	std::string target;

	name = "ShrubberyCreationForm";
	target = "new_tree";

	form = intern.makeForm(name, target);
	if (!form)
		return (1);

	std::cout << std::endl << "\033[33m****** TESTING SIGNING FORM *******\033[0m" << std::endl;
	try {
		bureaucrat->sign_form(*form);
	}
	catch (AForm::GradeTooLowException &exception) {
		std::cerr << bureaucrat->get_name() << " couldn’t sign " << name << ", because his "
				  << exception.txt_except() << std::endl;
	}

	std::cout << std::endl << "\033[33m****** TESTING EXECUTING FORM *******\033[0m" << std::endl;
	try {
		bureaucrat->execute_form(*form);
	}
	catch (AForm::GradeTooLowException &exception) {
		std::cerr << bureaucrat->get_name() << " couldn’t execute " << name << ", because his "
				  << exception.txt_except() << std::endl;
	}

	//DESTRUCTION
	std::cout << std::endl << "\033[33m****** DESTRUCTION *******\033[0m" << std::endl;
	delete bureaucrat;
	delete form;

//	system("leaks ex03");
	return (0);
}
