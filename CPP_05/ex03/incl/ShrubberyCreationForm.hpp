/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:50:37 by rmazurit          #+#    #+#             */
/*   Updated: 2022/12/23 14:50:37 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Bureaucrat;

#define	SHRUB_SIGN_GRADE	145
#define	SHRUB_EXEC_GRADE	137

class ShrubberyCreationForm : public AForm {

private:
	const std::string	_target;
	bool				_is_signed;

public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string &target);
	ShrubberyCreationForm(ShrubberyCreationForm &src);
	~ShrubberyCreationForm();

	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);

	void		be_signed(Bureaucrat &bureaucrat);
	void 		execute(Bureaucrat const &executor) const;

	std::string	get_target();
};

std::ostream	&operator<<(std::ostream &o, ShrubberyCreationForm *a);
