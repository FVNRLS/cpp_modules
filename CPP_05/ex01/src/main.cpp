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

#include "../incl/Form.hpp"

#define GRADE		5
#define SIGN_GRADE	1
#define EXEC_GRADE	1

int main() {
	int ret;

	ret = 0;
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

	std::cout << "\033[33m****** TESTING CONSTRUCTION FORM *******\033[0m" << std::endl;
	Form	*form;

	form = NULL;
	try {
		form = new Form(SIGN_GRADE, EXEC_GRADE);
		std::cout << form << std::endl;
	}
	catch (Form::GradeTooHighException &exception) {
		std::cerr << "Bureaucrat instantiation failed: init grade" << exception.txt_except() << std::endl;
		delete bureaucrat;
		return (1);
	}
	catch (Form::GradeTooLowException &exception) {
		std::cerr << "Bureaucrat instantiation failed: init grade" << exception.txt_except() << std::endl;
		delete bureaucrat;
		return (1);
	}

	//DESTRUCTION
	std::cout << "\033[33m****** DESTRUCTION *******\033[0m" << std::endl;
	if (bureaucrat != NULL) {
		delete bureaucrat;
	}
	if (form != NULL) {
		delete form;
	}

	system("leaks ex01");

	return (ret);
}
