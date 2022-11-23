/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 14:47:27 by rmazurit          #+#    #+#             */
/*   Updated: 2022/11/20 14:47:27 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contacts.hpp"

# define NUM_CONTACTS	8
# define MAX_STR_LEN	10

class	PhoneBook {

private:
	Contact	_contacts[NUM_CONTACTS];
	int		_index;
	int 	_items;

public:
	PhoneBook();
	~PhoneBook();

	void			add();
	void			search();
	int				get_index() const;
	static void 	print_info(const std::string &str) ;
	static void		display_contact(const Contact &contact) ;
	void			display_all_contacts() const;
};

#endif
