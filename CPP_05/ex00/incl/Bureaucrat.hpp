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

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat {

private:
	std::string const	_name;
	int 				_grade;

public:
	Bureaucrat();
	Bureaucrat(std::string &name);
	Bureaucrat(const Bureaucrat &src);
	~Bureaucrat();

	Bureaucrat	&operator=(const Bureaucrat &src);

	void	increment_grade(int	num);
	void 	decrement_grade(int num);

	void	get_name() const;
	void 	get_grade() const;

};

#endif
