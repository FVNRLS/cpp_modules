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

Bureaucrat::Bureaucrat() : _name("Default bureaucrat"), _grade (1) {
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
	std::cout << _name << " was destroyed" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) {
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	*this = src;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &src) {
	std::cout << "Bureaucrat assignment operator called" << std::endl;
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

void	Bureaucrat::increment_grade() {
	if ((_grade - 1) < 1)
		throw GradeTooHighException();
	else {
		_grade -= 1;
		std::cout << _name << " was incremented" << std::endl;
	}
}

void 	Bureaucrat::decrement_grade() {
	if ((_grade + 1) > 150)
		throw GradeTooLowException();
	else {
		_grade += 1;
		std::cout << _name << " was decremented" << std::endl;
	}
}

std::string Bureaucrat::get_name() const {
	return (_name);
}

int	Bureaucrat::get_grade() const {
	return (_grade);
}

std::ostream	&operator<<(std::ostream &o, Bureaucrat *a) {
	o << "Name: " << a->get_name() << ", grade: " << a->get_grade() << std::endl;
	return (o);
}
