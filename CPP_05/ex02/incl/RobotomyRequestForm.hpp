/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:52:34 by rmazurit          #+#    #+#             */
/*   Updated: 2022/12/23 14:52:34 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Bureaucrat;

#define	ROB_SIGN_GRADE	72
#define	ROB_EXEC_GRADE	45

class RobotomyRequestForm : public AForm {

private:
	const std::string	_target;
	bool				_is_signed;

public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string &target);
	RobotomyRequestForm(RobotomyRequestForm &src);
	~RobotomyRequestForm();

	RobotomyRequestForm &operator=(const RobotomyRequestForm &src);

	void		be_signed(Bureaucrat &bureaucrat);
	void 		execute(Bureaucrat const &executor) const;

	std::string	get_target();
};

std::ostream	&operator<<(std::ostream &o, RobotomyRequestForm *a);
