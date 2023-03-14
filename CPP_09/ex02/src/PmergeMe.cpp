/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 17:51:31 by rmazurit          #+#    #+#             */
/*   Updated: 2023/03/12 17:51:31 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

//BASIC CLASS SETUP
PmergeMe::PmergeMe() : _args(NULL), _vector(), _set() {}

PmergeMe::PmergeMe(char **argv) : _args(argv), _vector(), _set() {}

PmergeMe::PmergeMe(const PmergeMe &src) { *this = src; }

PmergeMe &PmergeMe::operator=(const PmergeMe &src) {
	if (this == &src)
		return *this;
	_args = src._args;
	_vector = src._vector;
	_set = src._set;
	return *this;
}

PmergeMe::~PmergeMe() {}

//TOOLS
std::string trim(std::string &s) {
	size_t 	front_pos;
	size_t 	back_pos;

	//TRIM SPACES
	if (s.empty())
		return ("");
	front_pos = s.find_first_not_of(SPACE);
	if (front_pos == std::string::npos)
		return (s);
	back_pos = s.find_last_not_of(SPACE);
	if (front_pos != back_pos)
		s = s.substr(front_pos, back_pos + 1);

	//TRIM TABS
	front_pos = s.find_first_not_of('\t');
	if (front_pos == std::string::npos)
		return (s);
	back_pos = s.find_last_not_of(TAB);
	if (front_pos != back_pos)
		s = s.substr(front_pos, back_pos + 1);
	return (s);
}

std::vector<std::string> tokenize(std::string &line, char sep) {
	line = trim(line);
	std::vector<std::string>	tokens;
	std::string 				tok;
	std::istringstream 			iss(line);

	while (getline(iss, tok, sep)) {
		tok = trim(tok);
		if (tok.empty())
			continue;
		tokens.push_back(tok);
	}
	return (tokens);
}

//MEMBER FUNCTIONS
int	PmergeMe::compare_containers() {
	if (_args == NULL)
		return EXIT_FAILURE;

	if (parse_input() == EXIT_FAILURE) {
		std::cerr << "Error" << std::endl;
		return EXIT_FAILURE;
	}


	return EXIT_SUCCESS;
}

//TODO: cont here!
int PmergeMe::parse_input() {
	int 						i;
	std::string					chunk;
	std::vector<std::string>	tokens;
	long						val;
	bool 						duplicate_found;

	i = 1;
	while (_args[i] != NULL) {
		chunk = _args[i];
		chunk = trim(chunk);
		tokens = tokenize(chunk, SPACE);
		for (std::vector<std::string>::iterator it = tokens.begin(); it != tokens.end(); it++) {
			try {
				val = std::strtol(it->c_str(), NULL, 10);
			}
			catch (...) {
				return EXIT_FAILURE;
			}
			if (val < INT_MIN || val > INT_MAX)
				return EXIT_FAILURE;
			duplicate_found = false;
			for (std::vector<int>::iterator it= _vector.begin(); it != _vector.end(); it++) {
				if (*it == val) {
					duplicate_found = true;
					break;
				}
			}
			if (!duplicate_found)
				_vector.push_back(static_cast<int>(val));
			_set.insert(static_cast<int>(val));
		}
		i++;
	}
	return EXIT_SUCCESS;
}


//"1 4 3 7 1 4 2 77 85 34 22" "2 7 1 11 22 4" 8 9 10






//ERROR MANAGEMENT