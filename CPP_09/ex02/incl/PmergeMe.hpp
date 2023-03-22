/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 17:51:47 by rmazurit          #+#    #+#             */
/*   Updated: 2023/03/12 17:51:47 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <sstream>
#include <vector>
#include <deque>
#include <limits>
#include <ctime>
#include <iomanip>
#include <stdlib.h>
#include <limits.h>

#define SPACE	' '
#define TAB		'\t'


class PmergeMe {

private:
	char 				**_args;
	std::vector<long>	_vector;
	std::deque<long>	_deque;
	bool 				_values_sorted;

	//MEMBER FUNCTIONS
	int 				parse_input();
	std::vector<long>	sort_vector();
	std::deque<long> 	sort_deque();
	void 				print_container_values();

public:
	PmergeMe();
	PmergeMe(char **argv);
	PmergeMe(const PmergeMe &src);
	PmergeMe &operator=(const PmergeMe &src);
	~PmergeMe();

	int	compare_containers();
};