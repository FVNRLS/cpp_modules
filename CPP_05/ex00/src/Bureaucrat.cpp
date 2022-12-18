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

Bureaucrat::Bureaucrat() : _name("Default"), _grade (150) {
	std::cout << "Bureaucrat " << _name << " was created" << std::endl;
}

Bureaucrat::Bureaucrat(std::string &name) : _name(name), _grade (150) {
	std::cout << "Bureaucrat " << _name << " was created" << std::endl;
}

