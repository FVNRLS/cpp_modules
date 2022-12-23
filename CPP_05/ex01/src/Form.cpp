/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:01:02 by rmazurit          #+#    #+#             */
/*   Updated: 2022/12/19 17:01:02 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Form.hpp"

Form::Form() : _name("Default form"), _sign_grade(1), _exec_grade(1), _is_signed(false) {
	std::cout << _name << " was created" << std::endl;
}

Form::Form(int sign_grade, int exec_grade): _name("New form"), _sign_grade(sign_grade), _exec_grade(exec_grade), _is_signed(false) {
	if (sign_grade > 150 || exec_grade > 150)
		throw(Form::GradeTooLowException());
	else if( sign_grade < 1 || exec_grade < 1)
		throw(Form::GradeTooHighException());
	std::cout << _name << " was created" << std::endl;
}

Form::Form(const Form &src) : _name("Copied form"), _sign_grade(src._sign_grade), _exec_grade(src._exec_grade), _is_signed(false) {
	std::cout << "Form copy constructor called" << std::endl;
	*this = src;
}

Form::~Form() {
	std::cout << _name << " was destroyed" << std::endl;
}

Form	&Form::operator=(const Form &src) {
	std::cout << "Form assignment operator called" << std::endl;
	if (this == &src)
		return (*this);
	_is_signed = src._is_signed;
	return (*this);
}

void	Form::be_signed(Bureaucrat &bureaucrat) {
	if (_is_signed) {
		std::cerr << bureaucrat.get_name() << " couldn’t sign " << _name
		<< " because the form was already signed" << std::endl;
		return;
	}
	else if (bureaucrat.get_grade() > _sign_grade) {
		throw(Form::GradeTooLowException());
	}
	_is_signed = true;
}

std::string Form::get_name() const {
	return (_name);
}

int	Form::get_sign_grade() const {
	return (_sign_grade);
}

int	Form::get_exec_grade() const {
	return (_exec_grade);
}

const char *Form::GradeTooLowException::txt_except() const throw() {
	return ("grade is too low");
}

const char *Form::GradeTooHighException::txt_except() const throw() {
	return ("grade is too high");
}

std::ostream	&operator<<(std::ostream &o, Form *a) {
	o << "Name: " << a->get_name() << ", Sign grade: " << a->get_sign_grade() << ", Exec grade: "
	<< a->get_exec_grade() << std::endl;
	return (o);
}


