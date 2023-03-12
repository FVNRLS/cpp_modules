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
#include <fstream>
#include <sstream>
#include <deque>
#include <unistd.h>

enum errors {
	BAD_FILEPATH,
	BAD_PERMISSIONS,
	BAD_INPUT_FORMAT,
	BAD_DATE,
	BAD_VALUE,

};

#define SPACE	' '
#define TAB		'\t'
#define PIPE	'|'
#define MINUS	'-'

class BitcoinExchanger {

private:
	std::deque<std::pair<std::string, float> >	_data;
	std::string 								_path;
	std::ifstream 								_file;
	int 										_year;
	int 										_month;
	int 										_day;
	float 										_value;

	//MEMBER FUNCTIONS
	int 										open_file();
	void 										parse_data();
	std::deque<std::string>						tokenize_line(std::string &line, char c);
	std::string 								trim(std::string &str);
	int 										check_data(std::string &data);
	int 										check_value(std::string &str_val);

	//ERROR MANAGEMENT
	int								print_error(int error, std::string &str);

public:
	BitcoinExchanger();
	BitcoinExchanger(std::string &file_path);
	BitcoinExchanger(const BitcoinExchanger &src);
	BitcoinExchanger &operator=(const BitcoinExchanger &src);
	~BitcoinExchanger();

	int	exchange();
};