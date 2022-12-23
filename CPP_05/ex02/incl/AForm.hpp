/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:02:44 by rmazurit          #+#    #+#             */
/*   Updated: 2022/12/19 17:02:44 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {

private:
	const std::string	_name;
	const int			_sign_grade;
	const int			_exec_grade;
	bool 				_is_signed;

public:
	AForm();
	AForm(int sign_grade, int exec_grade);
	AForm(const AForm &src);
	virtual ~AForm();

	AForm		&operator=(const AForm &src);

	virtual void	be_signed(Bureaucrat &bureaucrat);
	virtual void 	execute(Bureaucrat const &executor) const = 0;

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

std::ostream &operator<<(std::ostream &o, AForm *a);
