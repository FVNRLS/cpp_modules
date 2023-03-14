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
PmergeMe::PmergeMe() : _args(NULL), _vector(), _deque(), _values_sorted(false) {}

PmergeMe::PmergeMe(char **argv) : _args(argv), _vector(), _deque(), _values_sorted(false) {}

PmergeMe::PmergeMe(const PmergeMe &src) { *this = src; }

PmergeMe &PmergeMe::operator=(const PmergeMe &src) {
	if (this == &src)
		return *this;
	_args = src._args;
	_vector = src._vector;
	_deque = src._deque;
	_values_sorted = src._values_sorted;
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

bool index_is_even(size_t index) {
	return index % 2 == 0;
}

//MEMBER FUNCTIONS
int	PmergeMe::compare_containers() {
	if (_args == NULL)
		return EXIT_FAILURE;

	if (parse_input() == EXIT_FAILURE) {
		std::cerr << "Error" << std::endl;
		return EXIT_FAILURE;
	}
	print_container_values();
	sort_vector();
	sort_deque();
	print_container_values();
	return EXIT_SUCCESS;
}

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
			if (!duplicate_found) {
				_vector.push_back(static_cast<int>(val));
				_deque.push_back(static_cast<int>(val));
			}
		}
		i++;
	}
	return EXIT_SUCCESS;
}

void PmergeMe::print_container_values() {
	if (!_values_sorted)
		std::cout << "UNSORTED VALUES FOR VECTOR:		";
	else
		std::cout << "SORTED VALUES FOR VECTOR:		";
	for (std::vector<int>::iterator it = _vector.begin(); it != _vector.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	if (_values_sorted)
		std::cout << "UNSORTED VALUES FOR DEQUE:		";
	else
		std::cout << "SORTED VALUES FOR DEQUE:		";
	for (std::deque<int>::iterator it = _deque.begin(); it != _deque.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

}

//VECTOR-SORT HELPERS
static std::vector<std::pair<int, int> >	split_vector_in_pairs(std::vector<int> &vec) {
	std::vector<std::pair<int, int> >	vec_pairs;
	std::pair<int, int>					pair;
	size_t 								index;

	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
		index = it - vec.begin();
		if (index_is_even(index))
			pair.first = *it;
		else {
			pair.second = *it;
			vec_pairs.push_back(pair);
		}
	}
	if (vec.size() % 2 == 1) {
		pair.first = *vec.end();
		pair.second = INT_MAX; //todo: cont here!
		vec_pairs.push_back(pair);
	}

	return vec_pairs;
}

//VECTOR
void	PmergeMe::sort_vector() {
	std::vector<std::pair<int, int> >	pairs;

	pairs = split_vector_in_pairs(_vector);
}

//DEQUE-SORT HELPERS


//DEQUE
void	PmergeMe::sort_deque() {
}


//"1 4 3 7 1 4 2 77 85 34 22" "2 7 1 11 22 4" 8 9 10

