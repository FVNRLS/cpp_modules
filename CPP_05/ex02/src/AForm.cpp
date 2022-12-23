/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:01:02 by rmazurit          #+#    #+#             */
/*   Updated: 2022/12/19 17:01:02 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/AForm.hpp"

AForm::AForm() : _name("Default form"), _sign_grade(1), _exec_grade(1), _is_signed(false) {
	std::cout << _name << " was created" << std::endl;
}

AForm::AForm(int sign_grade, int exec_grade) : _name("New form"), _sign_grade(sign_grade), _exec_grade(exec_grade), _is_signed(false) {
	if (sign_grade > 150 || exec_grade > 150)
		throw(AForm::GradeTooLowException());
	else if( sign_grade < 1 || exec_grade < 1)
		throw(AForm::GradeTooHighException());
	std::cout << _name << " was created" << std::endl;
}

AForm::AForm(const AForm &src) : _name("Copied form"), _sign_grade(src._sign_grade), _exec_grade(src._exec_grade), _is_signed(false) {
	std::cout << "AForm copy constructor called" << std::endl;
	*this = src;
}

AForm::~AForm() {
	std::cout << _name << " was destroyed" << std::endl;
}

AForm	&AForm::operator=(const AForm &src) {
	std::cout << "AForm assignment operator called" << std::endl;
	if (this == &src)
		return (*this);
	_is_signed = src._is_signed;
	return (*this);
}

void	AForm::be_signed(Bureaucrat &bureaucrat) {
	if (_is_signed) {
		std::cerr << bureaucrat.get_name() << " couldn’t sign " << _name
				  << " because the form was already signed" << std::endl;
		return;
	}
	else if (bureaucrat.get_grade() > _sign_grade) {
		throw(AForm::GradeTooLowException());
	}
	_is_signed = true;
}

std::string AForm::get_name() const {
	return (_name);
}

int	AForm::get_sign_grade() const {
	return (_sign_grade);
}

int	AForm::get_exec_grade() const {
	return (_exec_grade);
}

const char *AForm::GradeTooLowException::txt_except() const throw() {
	return ("grade is too low");
}

const char *AForm::GradeTooHighException::txt_except() const throw() {
	return ("grade is too high");
}

std::ostream	&operator<<(std::ostream &o, AForm *a) {
	o << "Name: " << a->get_name() << ", Sign grade: " << a->get_sign_grade() << ", Exec grade: "
	<< a->get_exec_grade() << std::endl;
	return (o);
}
