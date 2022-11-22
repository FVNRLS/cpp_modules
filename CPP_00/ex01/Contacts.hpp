/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contacts.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 14:40:40 by rmazurit          #+#    #+#             */
/*   Updated: 2022/11/20 14:40:40 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACTS_HPP
# define CONTACTS_HPP

# include <iostream>
# include <sstream>
# include <string>

class	Contact{

private:
	std::string	_id;
	std::string	_name;
	std::string	_surname;
	std::string	_nickname;
	std::string	_phone;
	std::string	_darkest_secret;

public:
	Contact();
	~Contact();

	std::string get_id() const;
	std::string get_name() const;
	std::string get_surname() const;
	std::string get_nickname() const;
	std::string get_phone() const;
	std::string	get_darkest_secret() const;

	int 		set_contact(int id);
	void		set_id(int id);
	int 		set_name();
	int 		set_surname();
	int 		set_nickname();
	int 		set_phone();
	int 		set_darkest_secret();

};

#endif
