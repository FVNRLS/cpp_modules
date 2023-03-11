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
	_file = src._file;
	return *this;
}

BitcoinExchanger::~BitcoinExchanger() {}

//MEMBER FUNCTIONS
int	BitcoinExchanger::exchange() {
	if (open_file() == EXIT_FAILURE)
		return EXIT_FAILURE;
	if (parse_data() == EXIT_FAILURE)
		return EXIT_FAILURE;
	return EXIT_SUCCESS;
}

int BitcoinExchanger::open_file() {
	if (_path.empty() || access(_path.c_str(), F_OK))
		return print_error(BAD_FILEPATH);
	_file.open(_path);
	if (_file.bad() || !_file.is_open())
		return print_error(BAD_PERMISSIONS);
	return EXIT_SUCCESS;
}

int BitcoinExchanger::parse_data() {
	std::string					line;
	std::pair<std::string, int>	data_sequence;
	std::deque<std::string>		tokens;

	while (std::getline(_file, line)) {
		tokens = tokenize_line(line, PIPE);
		if (tokens.size() == 2) {
			if (check_data(tokens[0]) == EXIT_SUCCESS)
				data_sequence.first = tokens[0];
			else {
				print_error(BAD_DATA);
				continue;
			}
			if (check_value(tokens[1]) == EXIT_SUCCESS)
				data_sequence.second = static_cast<int>(std::strtol(tokens[1].c_str(), NULL, 10));
			else {
				print_error(BAD_VALUE);
				continue;
			}
			_data.insert(data_sequence);
		}
		else
			print_error(BAD_INPUT);




//		_data.insert(data_sequence);
	}
	return EXIT_SUCCESS;
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
	if (year < 1 || month < 1 || month > 12 || day < 1) {
		return false;
	}
	if (month == 2) {
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
			return day <= 29;
		} else {
			return day <= 28;
		}
	} else if (month == 4 || month == 6 || month == 9 || month == 11) {
		return day <= 30;
	} else {
		return day <= 31;
	}
}

int BitcoinExchanger::check_data(std::string &date) {
	std::deque<std::string>	tokens;
	int 					year;
	int 					month;
	int 					day;
	bool 					date_valid;

	tokens = tokenize_line(date, MINUS);
	if (tokens.size() != 3)
		return EXIT_FAILURE;
	year = std::strtol(tokens[0].c_str(), NULL, 10);
	month = std::strtol(tokens[1].c_str(), NULL, 10);
	day = std::strtol(tokens[2].c_str(), NULL, 10);
	date_valid = validate_date(year, month, day);
	if (!date_valid)
		return (BAD_DATA);
	return EXIT_SUCCESS;
}

int BitcoinExchanger::check_value(std::string &str_val) {


	return EXIT_SUCCESS;
}


//ERROR MANAGEMENT
int	BitcoinExchanger::print_error(int error) {
	switch (error) {
		case BAD_PERMISSIONS: {
			std::cerr << "Error: invalid file path: " << _path << std::endl;
			break;
		}
		case BAD_FILEPATH: {
			std::cerr << "Error: access denied on path: " << _path << std::endl;
			break;
		}
		case BAD_INPUT: {
			std::cerr << "Error: bad input" << std::endl;
			break;
		}
		case BAD_DATA: {
			std::cerr << "Error: invalid data format" << std::endl;
			break;
		}
		case BAD_VALUE: {
			std::cerr << "Error: invalid value" << std::endl;
			break;
		}
		default:
			std::cerr << "Unknown error" << std::endl;
	}
	return EXIT_FAILURE;
}
