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
#include <string>
#include <map>

enum errors {
	BAD_PERMISSIONS,
	BAD_FILEPATH,

};

class BitcoinExchanger {

private:
	std::map<std::string, int>	_data;
	std::string 				_path;
	std::ifstream 				_file;

	int							print_error(int &error);
	int 						open_file(std::string &path);

public:
	BitcoinExchanger();
	BitcoinExchanger(std::string &file_path);
	BitcoinExchanger(const BitcoinExchanger &src);
	BitcoinExchanger &operator=(const BitcoinExchanger &src);
	~BitcoinExchanger();

	int	exchange();
};