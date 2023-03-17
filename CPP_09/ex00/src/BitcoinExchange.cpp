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
BitcoinExchange::BitcoinExchange() : _data(), _path_to_input_txt(), _file(), _year(), _month(), _day() {}

BitcoinExchange::BitcoinExchange(std::string &file_path) : _path_to_input_txt(file_path), _file(), _year(), _month(), _day() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) { *this = src; }

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &src) {
	if (this == &src)
		return *this;
	_data = src._data;
	_path_to_input_txt = src._path_to_input_txt;
	_file.close();
	if (open_file(_path_to_input_txt) == EXIT_FAILURE)
		std::cerr << "Assignment operator failed on opening the file " << _path_to_input_txt << std::endl;
	_year = src._year;
	_month = src._month;
	_day = src._day;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}


//TOOLS
std::string	trim(std::string &s) {
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

//ERROR MANAGEMENT
int	print_error(int error, const std::string &str) {
	switch (error) {
		case BAD_PERMISSIONS: {
			std::cerr << "\033[31mError: access denied on path: " << str << "\033[0m" << std::endl;
			break;
		}
		case BAD_FILEPATH: {
			std::cerr << "\033[31mError: invalid file path: " << str << "\033[0m" << std::endl;
			break;
		}
		case EMPTY_FILE: {
			std::cerr << "\033[31mError: file is empty: " << str << "\033[0m" << std::endl;
			break;
		}
		case BAD_INPUT_FORMAT: {
			std::cerr << "\033[31mError: bad input: " << str << "\033[0m" << std::endl;
			break;
		}
		case BAD_DATE: {
			std::cerr << "\033[31mError: invalid data format: " << str << "\033[0m" << std::endl;
			break;
		}
		case BAD_VALUE: {
			std::cerr << "\033[31mError: invalid value: " << str << "\033[0m" << std::endl;
			break;
		}
		case DATE_NOT_IN_CSV: {
			std::cerr << "\033[31mError: date not in .csv table: " << str << "\033[0m" << std::endl;
			break;
		}
		case DUPLICATE_ENTRY: {
			std::cerr << "\033[31mError: duplicated input for date: " << str << "\033[0m" << std::endl;
			break;
		}
		default:
			std::cerr << "Unknown error" << std::endl;
	}
	return EXIT_FAILURE;
}

//MEMBER FUNCTIONS
int	BitcoinExchange::exchange() {
	if (_path_to_input_txt.empty())
		return (EXIT_FAILURE);
	if (open_file(PATH_TO_DATA_CSV) == EXIT_FAILURE)
		return EXIT_FAILURE;
	parse_data_csv();
	_file.close();
	if (open_file(_path_to_input_txt) == EXIT_FAILURE)
		return EXIT_FAILURE;
	if (parse_input_txt() == EXIT_FAILURE)
		return EXIT_FAILURE;
	return EXIT_SUCCESS;
}

int BitcoinExchange::open_file(const std::string &path) {
	if (path.empty() || access(path.c_str(), F_OK))
		return print_error(BAD_FILEPATH, path);
	_file.open(path);
	if (_file.bad() || !_file.is_open())
		return print_error(BAD_PERMISSIONS, path);
	return EXIT_SUCCESS;
}

void	BitcoinExchange::parse_data_csv() {
	std::string						line;
	std::pair<int, struct info>		data_sequence;
	size_t 							num_sep;
	std::string 					date;
	std::string						value;

	std::getline(_file, line);
	while (std::getline(_file, line)) {
		num_sep = count(line.begin(), line.end(), COMMA);
		if (num_sep == 1) {
			date = line.substr(0, line.find(COMMA));;
			value = line.substr(line.find(COMMA) + 1, line.length());
			if (extract_date(date) == EXIT_SUCCESS)
				data_sequence.first = (_year * 1000) + (_month * 100) + _day;
			else {
				print_error(BAD_DATE, date);
				continue;
			}
			if (check_value(value) == EXIT_SUCCESS) {
				data_sequence.second.price = std::strtof(value.c_str(), NULL);
				data_sequence.second.is_set = false;
			}
			else {
				print_error(BAD_VALUE, value);
				continue;
			}
			_data.insert(data_sequence);
		}
		else
			print_error(BAD_INPUT_FORMAT, line);
	}
}

int	BitcoinExchange::parse_input_txt() {
	std::string								line;
	size_t 									num_sep;
	std::string 							date;
	std::string								value;
	int 									date_val;
	float 									exch_rate;
	std::map<int, struct info>::iterator	it;
	float 									res;

	std::getline(_file, line);
	if (line.empty())
		return print_error(EMPTY_FILE, _path_to_input_txt);
	while (std::getline(_file, line)) {
		num_sep = count(line.begin(), line.end(), PIPE);
		if (num_sep == 1) {
			date = line.substr(0, line.find(PIPE));
			value = line.substr(line.find(PIPE) + 1, line.length());
			if (extract_date(date) == EXIT_SUCCESS)
				date_val = (_year * 1000) + (_month * 100) + _day;
			else {
				print_error(BAD_DATE, date);
				continue;
			}
			if (check_value(value) == EXIT_SUCCESS) {
				exch_rate = std::strtof(value.c_str(), NULL);
				if (exch_rate > 1000) {
					print_error(BAD_VALUE, value);
					continue;
				}
			}
			else {
				print_error(BAD_VALUE, value);
				continue;
			}
		}
		else {
			print_error(BAD_INPUT_FORMAT, line);
			continue;
		}

		it = _data.find(date_val);
		if (it == _data.end()) //todo::cont here!
			print_error(DATE_NOT_IN_CSV, date);
		else if (it->second.is_set)
			print_error(DUPLICATE_ENTRY, date);
		else {
			res = it->second.price * exch_rate;
			std::cout << "\033[32m" << date << 	" =>  "  << std::setw(10) << std::right << exch_rate <<
												" = " << std::setw(10) << std::right << res << "\033[0m" << std::endl;
			it->second.is_set = true;
		}
	}
	return EXIT_SUCCESS;
}

static bool validate_date(int year, int month, int day) {
	if (year < 2009 || year > 2023 || month < 1 || month > 12 || day < 1)
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

int BitcoinExchange::extract_date(std::string &date) {
	std::deque<std::string>	tokens;
	bool 					date_valid;
	size_t 					num_sep;
	std::string 			year;
	std::string 			month;
	std::string 			day;
	size_t 					first_dash_pos;
	size_t 					second_dash_pos;

	num_sep = count(date.begin(), date.end(), DASH);
	if (num_sep != 2)
		return EXIT_FAILURE;

	first_dash_pos = date.find(DASH);
	second_dash_pos = date.find(DASH, first_dash_pos + 1);

	year = date.substr(0, first_dash_pos);
	month = date.substr(first_dash_pos + 1, second_dash_pos - first_dash_pos - 1);
	day = date.substr(second_dash_pos + 1, date.length());

	year = trim(year);
	month = trim(month);
	day = trim(day);

	try {
		_year = static_cast<int>(std::strtol(year.c_str(), NULL, 10));
		_month = static_cast<int>(std::strtol(month.c_str(), NULL, 10));
		_day = static_cast<int>(std::strtol(day.c_str(), NULL, 10));
	}
	catch (...) {
		return EXIT_FAILURE;
	}
	date_valid = validate_date(_year, _month, _day);
	if (!date_valid)
		return EXIT_FAILURE;
	return EXIT_SUCCESS;
}

int BitcoinExchange::check_value(std::string &str_val) {
	float	val;
	try {
		val = (std::strtof(str_val.c_str(), NULL));
	}
	catch (...) {
		return EXIT_FAILURE;
	}
	if (val < 0 || val > static_cast<float>(INT_MAX))
		return EXIT_FAILURE;
	return EXIT_SUCCESS;
}

