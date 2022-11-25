/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:39:58 by rmazurit          #+#    #+#             */
/*   Updated: 2022/11/25 13:39:58 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

void	get_input(std::string &infile, std::string &s1, std::string &s2) {
	while (infile.length() == 0)
	{
		std::cout << "Enter the filename:		";
		std::getline(std::cin, infile);
		if (std::cin.eof())
			return ;
	}
	while (s1.length() == 0)
	{
		std::cout << "Enter the first string:		";
		std::getline(std::cin, s1);
		if (std::cin.eof())
			return ;
	}
	while (s2.length() == 0)
	{
		std::cout << "Enter the second string:	";
		std::getline(std::cin, s2);
		if (std::cin.eof())
			return ;
	}
}

std::string	replace_line(std::string &line, std::string &s1, std::string &s2) {
	std::string result = "Hello";
	size_t 		start_pos;
	size_t 		pos;

	start_pos = 0;


	return (result);
}

void	replace_content(std::ifstream &infile, std::ofstream &outfile, std::string &s1, std::string &s2) {
	std::string line;
	std::string result;

	while (std::getline(infile, line)) {
		result = replace_line(line, s1, s2);
		outfile << result << std::endl;
	}
}

int	main() {
	std::string	in_name;
	std::string out_name;
//	std::string	s1;
//	std::string	s2;

//	get_input(in_name, s1, s2);
//	if (std::cin.eof())
//		return (0);
//
//	out_name = in_name + ".replace";

	std::string str1 = "blablaFINDblablaFIND";
	std::string	str2 = "FIND";
	std::string str3 = "REPLACE";
	std::string sub;
	std::string result;

	size_t 	i;
	size_t	start_pos;

	i = 0;
	start_pos = 0;
	while ((i = str1.find(str2, i)) != std::string::npos) {
		std::cout << i << std::endl;
		sub = str1.substr(start_pos, i - start_pos);
		result += sub;
		result += str3;
		i += str2.length();
		start_pos = i;
		std::cout << "start pos:	" << start_pos << std::endl;
	}
	std::cout << result << std::endl;


	std::ifstream infile(in_name);
	std::ofstream outfile(out_name);



	infile.close();


	outfile.close();


	return (0);
}

//	std::fstream infile(in_name, std::ios::in);
//	std::fstream outfile(out_name, std::ios::out | std::ios::trunc);

//	infile.open(in_name, std::ios::in);
//	outfile.open("test.txt", std::ios::out | std::ios::trunc);
//
//	if (infile.is_open() && outfile.is_open())
//		std::cout << "bljajajajaja";