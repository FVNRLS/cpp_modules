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

void print_time(clock_t start, clock_t end, const std::string &cont_type) {
	clock_t	res;

	res = static_cast<double>(end - start) / CLOCKS_PER_SEC * 10000000;
	std::cout << "NEEDED TIME FOR " << std::setw(15) << std::left << cont_type;
	if (res > 10000)
		std::cout << res / 1000 << " MILLISECONDS" << std::endl;
	else
		std::cout <<  res << " MICROSECONDS" << std::endl;
}

//!MEMBER FUNCTIONS!
int	PmergeMe::compare_containers() {
	clock_t start_time;
	clock_t end_time;

	if (_args == NULL)
		return EXIT_FAILURE;

	if (parse_input() == EXIT_FAILURE) {
		std::cerr << "Error" << std::endl;
		return EXIT_FAILURE;
	}
	if (std::is_sorted(_vector.begin(), _vector.end())) {
		std::cout << "The sequence is already sorted!" << std::endl;
		return EXIT_SUCCESS;
	}
	print_container_values();

	start_time = std::clock();
	_vector = sort_vector();
	end_time = std::clock();
	print_time(start_time, end_time, "VECTOR");
	_values_sorted = true;
	print_container_values();


	start_time = std::clock();
	_deque = sort_deque();
	end_time = std::clock();
	print_time(start_time, end_time, "DEQUE");
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
		char *endptr = NULL;

		for (std::vector<std::string>::iterator it = tokens.begin(); it != tokens.end(); it++) {
			try {
				val = std::strtol(it->c_str(), &endptr, 10);
				if (*endptr != '\0' || val < 0 || val > INT_MAX) {
					throw std::invalid_argument("");
				}
			}
			catch (std::invalid_argument &e) {
				return EXIT_FAILURE;
			}
			catch (...) {
				return EXIT_FAILURE;
			}
			duplicate_found = false;
			for (std::vector<long>::iterator it= _vector.begin(); it != _vector.end(); it++) {
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
	for (std::vector<long>::iterator it = _vector.begin(); it != _vector.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

//	if (_values_sorted)
//		std::cout << "SORTED VALUES FOR DEQUE:		";
//	else
//		std::cout << "UNSORTED VALUES FOR DEQUE:		";
//	for (std::deque<long>::iterator it = _deque.begin(); it != _deque.end(); it++) {
//		std::cout << *it << " ";
//	}
//	std::cout << std::endl;

}


//VECTOR-SORT HELPERS
static std::vector<std::pair<long, long> >	split_vector_in_pairs(std::vector<long> &vec) {
	std::vector<std::pair<long, long> >		vec_pairs;
	std::pair<long, long>					pair;
	size_t 									index;

	for (std::vector<long>::iterator it = vec.begin(); it != vec.end(); it++) {
		index = it - vec.begin();
		if (index_is_even(index))
			pair.first = *it;
		else {
			pair.second = *it;
			vec_pairs.push_back(pair);
		}
	}
	if (vec.size() % 2 == 1) {
		pair.first = vec.back();
		pair.second = LONG_MAX;
		vec_pairs.push_back(pair);
	}
	return vec_pairs;
}

static std::vector<std::pair<long, long> > sort_vector_first_second(std::vector<std::pair<long, long> > &pairs) {
	for (std::vector<std::pair<long, long> >::iterator it = pairs.begin(); it != pairs.end(); it++) {
		if (it->first > it->second)
			std::swap(it->first, it->second);
	}
	return (pairs);
}

/*
 * Recursion pair-sorting algorithm based on first pair item.
 * Define a pivot element to compare the other elements to (first_pair).
 * Define 2 vectors of pairs to store pairs:
 * 		less = stores pairs which first item is < pivot.
 * 		greater = stores pairs which first item is > pivot.
 * Sort pairs into less/greater vectors.
 * Sort the less and greater vectors recursively, like the input pair vector. (again with first_pair as pivot and for loop)
 * Save the result accordingly in less and greater and in the end combine less, greater and pivot into 1 final result.
 *
 * HINT:
 * With reserving space we optimize the algorithm a little, because without reserving space,
 * the vector may need to allocate additional memory as it grows, which can be a relatively expensive operation.
 * This is because the vector needs to allocate new memory, copy the existing elements to the new memory,
 * and then deallocate the old memory.
 * */
static std::vector<std::pair<long, long> >	sort_vector_pairs_recursively(std::vector<std::pair<long, long> > &pairs) {
	if (pairs.size() <= 1)
		return pairs;

	std::vector<std::pair<long, long> > less;
	std::vector<std::pair<long, long> > greater;
	std::vector<std::pair<long, long> > result;
	std::pair<long, long> first_pair = pairs.front();

	for (std::vector<std::pair<long, long> >::iterator it = pairs.begin() + 1; it != pairs.end(); it++) {
		if (it->first < first_pair.first)
			less.push_back(*it);
		else
			greater.push_back(*it);
	}

	less = sort_vector_pairs_recursively(less);
	greater = sort_vector_pairs_recursively(greater);

	result.reserve(less.size() + greater.size() + 1);
	result.insert(result.end(), less.begin(), less.end());
	result.push_back(first_pair);
	result.insert(result.end(), greater.begin(), greater.end());

	return result;
}

static std::vector<long>	create_vector_main_chain(std::vector<std::pair<long, long> > &pairs) {
	std::vector<long>	main_chain;
	size_t 				size;

	size = pairs.size();
	main_chain.reserve(size);
	for (std::vector<std::pair<long, long> >::iterator it = pairs.begin(); it != pairs.end(); it++)
		main_chain.push_back(it->first);
	return main_chain;
}

/*
 * Uses binary search to find the position for number to insert in the main chain.
 * Returns the insert position.
 * */
static size_t find_vector_insert_pos(std::vector<long>& main_chain, long num) {
	size_t left = 0;
	size_t right = main_chain.size();

	while (left < right) {
		size_t mid = left + (right - left) / 2;
		if (main_chain[mid] < num)
			left = mid + 1;
		else
			right = mid;
	}
	return left;
}


//VECTOR
std::vector<long>	PmergeMe::sort_vector() {
	std::vector<std::pair<long, long> >	pairs;
	std::vector<long>					main_chain;
	size_t								pos;

	pairs = split_vector_in_pairs(_vector);
	pairs = sort_vector_first_second(pairs);
	pairs = sort_vector_pairs_recursively(pairs);
	main_chain = create_vector_main_chain(pairs);

	main_chain.reserve(_vector.size());
	for (std::vector<std::pair<long, long> >::iterator it = pairs.begin(); it != pairs.end(); it++) {
		if (it->second == LONG_MAX)
			continue;
		pos = find_vector_insert_pos(main_chain, it->second);
		if (pos == main_chain.size() - 1)
			main_chain.push_back(it->second);
		else
			main_chain.insert((main_chain.begin() + pos), it->second);
	}
	if (main_chain.back() < main_chain.at(main_chain.size() - 2))
		std::swap(main_chain.back(), main_chain.at(main_chain.size() - 2));
	return main_chain;
}


//DEQUE-SORT HELPERS
static std::deque<std::pair<long, long> >	split_deque_in_pairs(std::deque<long> &deq) {
	std::deque<std::pair<long, long> >		vec_pairs;
	std::pair<long, long>					pair;
	size_t 									index;

	for (std::deque<long>::iterator it = deq.begin(); it != deq.end(); it++) {
		index = it - deq.begin();
		if (index_is_even(index))
			pair.first = *it;
		else {
			pair.second = *it;
			vec_pairs.push_back(pair);
		}
	}
	if (deq.size() % 2 == 1) {
		pair.first = deq.back();
		pair.second = LONG_MAX;
		vec_pairs.push_back(pair);
	}
	return vec_pairs;
}

static std::deque<std::pair<long, long> > sort_deque_first_second(std::deque<std::pair<long, long> > &pairs) {
	for (std::deque<std::pair<long, long> >::iterator it = pairs.begin(); it != pairs.end(); it++) {
		if (it->first > it->second)
			std::swap(it->first, it->second);
	}
	return (pairs);
}

static std::deque<std::pair<long, long> >	sort_deque_pairs_recursively(std::deque<std::pair<long, long> > &pairs) {
	if (pairs.size() <= 1)
		return pairs;

	std::deque<std::pair<long, long> > less;
	std::deque<std::pair<long, long> > greater;
	std::deque<std::pair<long, long> > result;
	std::pair<long, long> first_pair = pairs.front();

	for (std::deque<std::pair<long, long> >::iterator it = pairs.begin() + 1; it != pairs.end(); it++) {
		if (it->first < first_pair.first)
			less.push_back(*it);
		else
			greater.push_back(*it);
	}

	less = sort_deque_pairs_recursively(less);
	greater = sort_deque_pairs_recursively(greater);

	result.insert(result.end(), less.begin(), less.end());
	result.push_back(first_pair);
	result.insert(result.end(), greater.begin(), greater.end());

	return result;
}

static std::deque<long>	create_deque_main_chain(std::deque<std::pair<long, long> > &pairs) {
	std::deque<long>	main_chain;

	for (std::deque<std::pair<long, long> >::iterator it = pairs.begin(); it != pairs.end(); it++)
		main_chain.push_back(it->first);
	return main_chain;
}

/*
 * Uses binary search to find the position for number to insert in the main chain.
 * Returns the insert position.
 * */
static size_t find_deque_insert_pos(std::deque<long> &main_chain, long num) {
	size_t left = 0;
	size_t right = main_chain.size();

	while (left < right) {
		size_t mid = left + (right - left) / 2;
		if (main_chain[mid] < num)
			left = mid + 1;
		else
			right = mid;
	}
	return left;
}


//DEQUE
std::deque<long>	PmergeMe::sort_deque() {
	std::deque<std::pair<long, long> >	pairs;
	std::deque<long>					main_chain;
	size_t								pos;

	pairs = split_deque_in_pairs(_deque);
	pairs = sort_deque_first_second(pairs);
	pairs = sort_deque_pairs_recursively(pairs);
	main_chain = create_deque_main_chain(pairs);

	for (std::deque<std::pair<long, long> >::iterator it = pairs.begin(); it != pairs.end(); it++) {
		if (it->second == LONG_MAX)
			continue;
		pos = find_deque_insert_pos(main_chain, it->second);
		if (pos == main_chain.size() - 1)
			main_chain.push_back(it->second);
		else
			main_chain.insert((main_chain.begin() + pos), it->second);
	}
	if (main_chain.back() < main_chain.at(main_chain.size() - 2))
		std::swap(main_chain.back(), main_chain.at(main_chain.size() - 2));
	return main_chain;
}


//"1 4 3 7 1 4 2 77 85 34 22" "2 7 1 11 22 4" 8 9 10

