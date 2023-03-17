/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 11:17:45 by rmazurit          #+#    #+#             */
/*   Updated: 2023/03/11 11:17:45 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <algorithm>
#include <fstream>
#include <climits>
#include <map>
#include <unistd.h>

enum errors {
	BAD_FILEPATH,
	BAD_PERMISSIONS,
	EMPTY_FILE,
	BAD_INPUT_FORMAT,
	BAD_DATE,
	BAD_VALUE,
	DUPLICATE_ENTRY,

};

#define SPACE	' '
#define TAB		'\t'
#define PIPE	'|'
#define DASH	'-'
#define COMMA	','

const std::string PATH_TO_DATA_CSV = "data.csv";

struct	info {
	float 						price;
	bool 						is_set;
};

class BitcoinExchange {

private:
	std::map<int, struct info> 	_data;
	std::string 				_path_to_input_txt;
	std::ifstream 				_file;
	int 						_year;
	int 						_month;
	int 						_day;

	//MEMBER FUNCTIONS
	int 						open_file(const std::string &path);
	int 						parse_data_csv();
	int 						parse_input_txt();
	int 						extract_date(std::string &date);
	int 						check_value(std::string &str_val);
	std::map<int, struct info>::iterator	find_closest_lower_date(int date_val);

public:
	BitcoinExchange();
	BitcoinExchange(std::string &file_path);
	BitcoinExchange(const BitcoinExchange &src);
	BitcoinExchange &operator=(const BitcoinExchange &src);
	~BitcoinExchange();

	int	exchange();
};