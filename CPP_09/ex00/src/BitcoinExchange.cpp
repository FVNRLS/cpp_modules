/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 11:17:15 by rmazurit          #+#    #+#             */
/*   Updated: 2023/03/11 11:17:15 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

//BASIC CLASS SETUP
BitcoinExchanger::BitcoinExchanger() : _data(), _path(), _file() {}

BitcoinExchanger::BitcoinExchanger(std::string &file_path) : _path(file_path), _file() {}

BitcoinExchanger::BitcoinExchanger(const BitcoinExchanger &src) { *this = src; }

BitcoinExchanger	&BitcoinExchanger::operator=(const BitcoinExchanger &src) {
	if (this == &src)
		return *this;
	_data = src._data;
	_path = src._path;
	return *this;
}

BitcoinExchanger::~BitcoinExchanger() {}

//MEMBER FUNCTIONS
int	BitcoinExchanger::exchange() {
	if (open_file() == EXIT_FAILURE)
		return EXIT_FAILURE;
	parse_data();
	//TODO: parse exchange rate and calculate prices!
	return EXIT_SUCCESS;
}

int BitcoinExchanger::open_file() {
	if (_path.empty() || access(_path.c_str(), F_OK))
		return print_error(BAD_FILEPATH, _path);
	_file.open(_path);
	if (_file.bad() || !_file.is_open())
		return print_error(BAD_PERMISSIONS, _path);
	return EXIT_SUCCESS;
}

bool compare_pairs(const std::pair<std::string, float> &left, const std::pair<std::string, float> &right) {
	return left.first < right.first;
}

void	BitcoinExchanger::parse_data() {
	std::string					line;
	std::pair<std::string, float>	data_sequence;
	std::deque<std::string>		tokens;

	std::getline(_file, line);
	while (std::getline(_file, line)) {
		tokens = tokenize_line(line, PIPE);
		if (tokens.size() == 2) {
			if (check_data(tokens[0]) == EXIT_SUCCESS)
				data_sequence.first = tokens[0];
			else {
				print_error(BAD_DATE, tokens[0]);
				continue;
			}
			if (check_value(tokens[1]) == EXIT_SUCCESS)
				data_sequence.second = _value;
			else {
				print_error(BAD_VALUE, tokens[1]);
				continue;
			}
			_data.push_back(data_sequence);
//			std::cout << tokens[0] << " => " << std::setw(6) << std::right << tokens[1] << std::endl;
		}
		else
			print_error(BAD_INPUT_FORMAT, line);
		tokens.clear();
	}
	std::sort(_data.begin(), _data.end(), compare_pairs);
}

std::deque<std::string> BitcoinExchanger::tokenize_line(std::string &line, char sep) {
	line = trim(line);
	std::deque<std::string>		tokens;
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

std::string	BitcoinExchanger::trim(std::string &s) {
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

static bool validate_date(int year, int month, int day) {
	if (year < 2011 || year > 2023 || month < 1 || month > 12 || day < 1)
		return false;
	if (month == 2) {
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) //calculating leap year
			return day <= 29;
		else
			return day <= 28;
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11)
		return day <= 30;
	else
		return day <= 31;
}

int BitcoinExchanger::check_data(std::string &date) {
	std::deque<std::string>	tokens;
	bool 					date_valid;

	tokens = tokenize_line(date, MINUS);
	if (tokens.size() != 3)
		return EXIT_FAILURE;
	try {
		_year = static_cast<int>(std::strtol(tokens[0].c_str(), NULL, 10));
		_month = static_cast<int>(std::strtol(tokens[1].c_str(), NULL, 10));
		_day = static_cast<int>(std::strtol(tokens[2].c_str(), NULL, 10));
	}
	catch (...) {
		return EXIT_FAILURE;
	}
	date_valid = validate_date(_year, _month, _day);
	if (!date_valid)
		return EXIT_FAILURE;
	return EXIT_SUCCESS;
}

int BitcoinExchanger::check_value(std::string &str_val) {
	try {
		_value = (std::strtof(str_val.c_str(), NULL));
	}
	catch (...) {
		return EXIT_FAILURE;
	}
	if (_value < 0 || _value > 1000)
		return EXIT_FAILURE;
	return EXIT_SUCCESS;
}


//ERROR MANAGEMENT
int	BitcoinExchanger::print_error(int error, std::string &str) {
	switch (error) {
		case BAD_PERMISSIONS: {
			std::cerr << "Error: access denied on path: " << str << std::endl;
			break;
		}
		case BAD_FILEPATH: {
			std::cerr << "Error: invalid file path: " << str << std::endl;
			break;
		}
		case BAD_INPUT_FORMAT: {
			std::cerr << "Error: bad input: " << str << std::endl;
			break;
		}
		case BAD_DATE: {
			std::cerr << "Error: invalid data format: " << str << std::endl;
			break;
		}
		case BAD_VALUE: {
			std::cerr << "Error: invalid value: " << str << std::endl;
			break;
		}
		default:
			std::cerr << "Unknown error" << std::endl;
	}
	return EXIT_FAILURE;
}
