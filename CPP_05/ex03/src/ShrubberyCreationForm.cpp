/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:51:17 by rmazurit          #+#    #+#             */
/*   Updated: 2022/12/23 14:51:17 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : _target("default_target"), _is_signed(false) {
	std::cout << "ShrubberyCreationForm was created with associated target file: " << _target << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string &target) : _target(target), _is_signed(false) {
	std::cout << "ShrubberyCreationForm was created with associated target file: " << _target << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &src) {
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
	*this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm was destroyed" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src) {
	std::cout << "ShrubberyCreationForm assignation operator called" << std::endl;
	(void)src;
	return (*this);
}

void	ShrubberyCreationForm::be_signed(Bureaucrat &bureaucrat) {
	if (_is_signed) {
		std::cerr << bureaucrat.get_name() << " couldn’t sign ShrubberyCreationForm"
				  << " because the form was already signed" << std::endl;
		return;
	}
	else if (bureaucrat.get_grade() > SHRUB_SIGN_GRADE) {
		throw(AForm::GradeTooLowException());
	}
	std::cout << bureaucrat.get_name() << " successfully signed the ShrubberyCreationForm" << std::endl;
	_is_signed = true;
}

int	draw_tree(std::string target) {
	std::ofstream	ofs;
	std::string		name;

	name = target.append("_shrubbery");
	ofs.open(name);
	if (ofs.fail()) {
		std::cerr << "Error: file" << name << " couldn't be created" << std::endl;
		return (EXIT_FAILURE);
	}
	ofs << "              v .   ._, |_  .,\n";
	ofs << "           `-._\\/  .  \\ /    |/_\n";
	ofs << "               \\\\  _\\, y | \\//\n";
	ofs << "         _\\_.___\\\\, \\\\/ -.\\||\n";
	ofs << "           `7-,--.`._||  / / ,\n";
	ofs << "           /'     `-. `./ / |/_.'\n";
	ofs << "                     |    |//\n";
	ofs << "                     |_    /\n";
	ofs << "                     |-   |\n";
	ofs << "                     |   =|\n";
	ofs << "                     |    |\n";
	ofs << "--------------------/ ,  . \\--------._\n";
	ofs << std::endl;
	ofs.close();
	return (EXIT_SUCCESS);
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	if (!_is_signed) {
		std::cerr << executor.get_name() << " couldn’t execute ShrubberyCreationForm"
				  << " because the form was not signed" << std::endl;
		return;
	}
	else if (executor.get_grade() > SHRUB_EXEC_GRADE)
		throw(AForm::GradeTooLowException());
	if (draw_tree(_target) == EXIT_SUCCESS)
		std::cout << "ShrubberyCreationForm was successfully executed. Shrubbery tree was drawn" << std::endl;
}

std::string	ShrubberyCreationForm::get_target() {
	return (_target);
}

std::ostream	&operator<<(std::ostream &o, ShrubberyCreationForm *a) {
	o << "Name: ShrubberyCreationForm, Target: " << a->get_target() <<  ", Sign grade: " << SHRUB_SIGN_GRADE
		<< ", Exec grade: " << SHRUB_EXEC_GRADE << std::endl;
	return (o);
}
