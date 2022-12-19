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

#include "../incl/Bureaucrat.hpp"

#define GRADE			1
#define INCR_NUM		100
#define DECR_NUM		250

int main() {
	int ret;

	ret = 0;

	//TESTING CONSTRUCTION
	std::cout << "\033[33m****** TESTING CONSTRUCTION *******\033[0m" << std::endl;
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

	//TESTING INCREMENTAL
	std::cout << "\033[33m****** TESTING INCREMENTAL *******\033[0m" << std::endl;
	try {
		bureaucrat->increment_grade(INCR_NUM);
		std::cout << bureaucrat << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &exception) {
		std::cerr << "Bureaucrat incremental failed: result grade " << INCR_NUM << exception.txt_except() << std::endl;
		ret = 1;
	}
	catch (Bureaucrat::GradeTooLowException &exception) {
		std::cerr << "Bureaucrat incremental failed: result grade " << INCR_NUM << exception.txt_except() << std::endl;
		ret = 1;
	}

	//TESTING DECREMENTAL
	std::cout << "\033[33m****** TESTING DECREMENTAL *******\033[0m" << std::endl;
	try {
		bureaucrat->decrement_grade(DECR_NUM);
		std::cout << bureaucrat << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &exception) {
		std::cerr << "Bureaucrat decremental failed: result grade " << DECR_NUM << exception.txt_except() << std::endl;
		ret = 1;
	}
	catch (Bureaucrat::GradeTooLowException &exception) {
		std::cerr << "Bureaucrat decremental failed: result grade " << DECR_NUM << exception.txt_except() << std::endl;
		ret = 1;
	}

	//DESTRUCTION
	if (bureaucrat != NULL) {
		std::cout << "\033[33m****** DESTRUCTION *******\033[0m" << std::endl;
		delete bureaucrat;
	}

//	system("leaks ex00");

	return (ret);
}
