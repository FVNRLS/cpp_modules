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
	Contact		_contacts[NUM_CONTACTS];
	bool		_is_empty;
	bool 		_is_closed;

public:
	PhoneBook();
	~PhoneBook();

	int		index;
	int 	items;

	void	add();
	void	search();
	bool	get_is_empty_flag() const;
	bool	get_is_closed_flag() const;
	void	set_is_empty_flag(bool flag);
	void	set_is_closed_flag(bool flag);
	int		get_index() const;
	void 	print_info(const std::string &str) const;
	void	display_contact(const Contact &contact) const;
	void	display_all_contacts() const;
};

#endif
