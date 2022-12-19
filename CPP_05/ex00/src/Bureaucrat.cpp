/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 19:04:51 by rmazurit          #+#    #+#             */
/*   Updated: 2022/12/18 19:04:51 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Bureaucrat"), _grade (1) {
	std::cout << _name << " was created" << std::endl;
}

Bureaucrat::Bureaucrat(int grade) : _name("Bureaucrat") {
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		_grade = grade;
	std::cout << _name << " was created" << std::endl;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat " << _name << " was destroyed" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) {
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	*this = src;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &src) {
	if (this == &src)
		return (*this);
	this->_grade = src._grade;
	return (*this);
}

const char *Bureaucrat::GradeTooLowException::txt_except() const throw() {
	return (" is too low");
}

const char *Bureaucrat::GradeTooHighException::txt_except() const throw() {
	return (" is too high");
}

void	Bureaucrat::increment_grade(int num) {
	if ((_grade + num) > 150)
		throw GradeTooLowException();
	else if ((_grade + num) < 1)
		throw GradeTooHighException();
	else {
		_grade += (int)num;
		std::cout << _name << " was incremented by " << num << std::endl;
	}
}

void 	Bureaucrat::decrement_grade(int num) {
	if ((_grade - num) > 150)
		throw GradeTooLowException();
	else if ((_grade - num) < 1)
		throw GradeTooHighException();
	else {
		_grade -= (int)num;
		std::cout << _name << " was decremented by " << num << std::endl;
	}
}

std::string Bureaucrat::get_name() const {
	return (_name);
}

int	Bureaucrat::get_grade() const {
	return (_grade);
}

std::ostream	&operator<<(std::ostream &o, Bureaucrat *a)
{
	o << "Name: " << a->get_name() << ", grade: " << a->get_grade() << std::endl;
	return (o);
}