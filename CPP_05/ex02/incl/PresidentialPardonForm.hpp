/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:54:03 by rmazurit          #+#    #+#             */
/*   Updated: 2022/12/23 14:54:03 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Bureaucrat;

#define	PRES_SIGN_GRADE	25
#define	PRES_EXEC_GRADE	5

class PresidentialPardonForm : public AForm {

private:
	const std::string	_target;
	bool				_is_signed;

public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string &target);
	PresidentialPardonForm(PresidentialPardonForm &src);
	~PresidentialPardonForm();

	PresidentialPardonForm &operator=(const PresidentialPardonForm &src);

	void		be_signed(Bureaucrat &bureaucrat);
	void 		execute(Bureaucrat const &executor) const;

	std::string	get_target();
};

std::ostream	&operator<<(std::ostream &o, PresidentialPardonForm *a);
