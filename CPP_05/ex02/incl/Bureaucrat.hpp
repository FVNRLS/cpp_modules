/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 19:03:48 by rmazurit          #+#    #+#             */
/*   Updated: 2022/12/18 19:03:48 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat {

private:
	std::string const	_name;
	int 				_grade;

public:
	Bureaucrat();
	Bureaucrat(int grade);
	Bureaucrat(const Bureaucrat &src);
	~Bureaucrat();

	Bureaucrat	&operator=(const Bureaucrat &src);

	void		increment_grade();
	void 		decrement_grade();
	void		sign_form(AForm &form);
	void		execute_form(AForm const &form);

	std::string get_name() const;
	int 		get_grade() const;

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *txt_except() const throw();
	};

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *txt_except() const throw();
	};
};

std::ostream	&operator<<(std::ostream &o, Bureaucrat *a);
