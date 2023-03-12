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
#include <unordered_set>

enum errors {

};

#define SPACE	' '
#define TAB		'\t'


class PmergeMe {

private:
	char 					**_args;
	std::vector<int>		_vector;
	std::unordered_set<int>	_set;

	//MEMBER FUNCTIONS
	int 					parse_input();

public:
	PmergeMe();
	PmergeMe(char **argv);
	PmergeMe(const PmergeMe &src);
	PmergeMe &operator=(const PmergeMe &src);
	~PmergeMe();

	int	compare_containers();
};