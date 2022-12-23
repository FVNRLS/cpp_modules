/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:53:52 by rmazurit          #+#    #+#             */
/*   Updated: 2022/12/23 14:53:52 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : _target("default_target"), _is_signed(false) {
	std::cout << "PresidentialPardonForm was created with associated target: " << _target << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string &target) : _target(target), _is_signed(false) {
	std::cout << "PresidentialPardonForm was created with associated target: " << _target << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &src) {
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
	*this = src;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PresidentialPardonForm was destroyed" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src) {
	std::cout << "PresidentialPardonForm assignation operator called" << std::endl;
	(void)src;
	return (*this);
}

void	PresidentialPardonForm::be_signed(Bureaucrat &bureaucrat) {
	if (_is_signed) {
		std::cerr << bureaucrat.get_name() << " couldn’t sign PresidentialPardonForm"
				  << " because the form was already signed" << std::endl;
		return;
	}
	else if (bureaucrat.get_grade() > PRES_SIGN_GRADE) {
		throw(AForm::GradeTooLowException());
	}
	std::cout << bureaucrat.get_name() << " successfully signed the PresidentialPardonForm" << std::endl;
	_is_signed = true;
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const {
	if (!_is_signed) {
		std::cerr << executor.get_name() << " couldn’t execute PresidentialPardonForm"
				  << " because the form was not signed" << std::endl;
		return;
	}
	else if (executor.get_grade() > PRES_EXEC_GRADE)
		throw(AForm::GradeTooLowException());
	std::cout << "The target " << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

std::string	PresidentialPardonForm::get_target() {
	return (_target);
}

std::ostream	&operator<<(std::ostream &o, PresidentialPardonForm *a) {
	o << "Name: PresidentialPardonForm, Target: " << a->get_target() <<  ", Sign grade: " << PRES_SIGN_GRADE
		<< ", Exec grade: " << PRES_EXEC_GRADE << std::endl;
	return (o);
}