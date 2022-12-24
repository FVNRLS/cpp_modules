/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 19:55:12 by rmazurit          #+#    #+#             */
/*   Updated: 2022/12/23 19:55:12 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class AForm;
class ShrubberyCreationForm;

class Intern {

public:
	Intern();
	Intern(const Intern &src);
	~Intern();

	Intern &operator=(const Intern &src);

	AForm	*makeForm(std::string &name, std::string &target);
};
