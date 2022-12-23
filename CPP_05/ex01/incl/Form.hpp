/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:02:44 by rmazurit          #+#    #+#             */
/*   Updated: 2022/12/19 17:02:44 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "iostream"
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

private:
	const std::string	_name;
	const int			_sign_grade;
	const int			_exec_grade;
	bool 				_is_signed;

public:
	Form();
	Form(int sign_grade, int exec_grade);
	Form(const Form &src);
	~Form();

	Form		&operator=(const Form &src);

	void		be_signed(Bureaucrat &bureaucrat);

	std::string get_name() const;
	int 		get_sign_grade() const;
	int 		get_exec_grade() const;

	class GradeTooLowException : public std::exception {
	public:
		virtual const char *txt_except() const throw();
	};

	class GradeTooHighException : public std::exception {
	public:
		virtual const char *txt_except() const throw();
	};
};

std::ostream &operator<<(std::ostream &o, Form *a);
