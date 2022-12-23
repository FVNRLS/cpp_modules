/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:52:18 by rmazurit          #+#    #+#             */
/*   Updated: 2022/12/23 14:52:18 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : _target("default_target"), _is_signed(false) {
	std::cout << "RobotomyRequestForm was created with associated target: " << _target << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string &target) : _target(target), _is_signed(false) {
	std::cout << "RobotomyRequestForm was created with associated target: " << _target << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &src) {
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
	*this = src;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm was destroyed" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src) {
	std::cout << "RobotomyRequestForm assignation operator called" << std::endl;
	(void)src;
	return (*this);
}

void	RobotomyRequestForm::be_signed(Bureaucrat &bureaucrat) {
	if (_is_signed) {
		std::cerr << bureaucrat.get_name() << " couldn’t sign RobotomyRequestForm"
				  << " because the form was already signed" << std::endl;
		return;
	}
	else if (bureaucrat.get_grade() > ROB_SIGN_GRADE) {
		throw(AForm::GradeTooLowException());
	}
	std::cout << bureaucrat.get_name() << " successfully signed the RobotomyRequestForm" << std::endl;
	_is_signed = true;
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	if (!_is_signed) {
		std::cerr << executor.get_name() << " - robotomy failed, "
				  << " because the form was not signed" << std::endl;
		return;
	}
	else if (executor.get_grade() > ROB_EXEC_GRADE)
		throw(AForm::GradeTooLowException());
	std::cout << "Drrrrrrrrrrrrrrrrrrrrrriiiiiiilllllllinggggg..............." << std::endl;
	std::cout << "The target " << _target << " has been robotomized successfully 50% of the time" << std::endl;
}

std::string	RobotomyRequestForm::get_target() {
	return (_target);
}

std::ostream	&operator<<(std::ostream &o, RobotomyRequestForm *a) {
	o << "Name: RobotomyRequestForm, Target: " << a->get_target() <<  ", Sign grade: " << ROB_SIGN_GRADE
		<< ", Exec grade: " << ROB_EXEC_GRADE << std::endl;
	return (o);
}