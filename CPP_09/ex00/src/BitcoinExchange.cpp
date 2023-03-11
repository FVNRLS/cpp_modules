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

BitcoinExchanger::BitcoinExchanger() : _data(), _path(), _file() {}

BitcoinExchanger::BitcoinExchanger(std::string &file_path) : _path(file_path), _file() {}

BitcoinExchanger::BitcoinExchanger(const BitcoinExchanger &src) { *this = src; }

BitcoinExchanger	&BitcoinExchanger::operator=(const BitcoinExchanger &src) {
	if (this == &src)
		return (*this);
	_data = src._data;
	_path = src._path;
	_file = src._file;
	return (*this);
}

int BitcoinExchanger::open_file(std::string &path) {

	return (EXIT_SUCCESS);
}

int	BitcoinExchanger::exchange() {
	if (open_file(_path) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

BitcoinExchanger::~BitcoinExchanger() {}

int	BitcoinExchanger::print_error(int &error) {
	switch (error) {
		case BAD_PERMISSIONS: {
			std::cerr << "Error: invalid file path: " << _path << std::endl;
			break;
		}
		case BAD_FILEPATH: {
			std::cerr << "Error: access denied on path: " << _path << std::endl;
			break;
		}
		default:
			std::cerr << "Unknown error" << std::endl;
	}
}
