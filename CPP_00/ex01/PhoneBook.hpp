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


class	PhoneBook{

private:
	Contact		contacts[NUM_CONTACTS];

public:
	PhoneBook();
	~PhoneBook();

	int		index;

	void	add();
	void	search() const;
	void	display_contact(const Contact &contact) const;
	void	display_all_contacts() const;
};

#endif
