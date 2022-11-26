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

static int	get_input(std::string &infile, std::string &s1, std::string &s2, int argc, char **argv) {
	if (argc != 4) {
		std::cout << "error: invalid number of arguments" << std::endl;
		return (EXIT_FAILURE);
	}
	infile = argv[1];
	if (infile.length() == 0) {
		std::cout << "error: missing input file" << std::endl;
		return (EXIT_FAILURE);
	}
	s1 = argv[2];
	if (s1.length() == 0) {
		std::cout << "error: missing string to replace" << std::endl;
		return (EXIT_FAILURE);
	}
	s2 = argv[3];
	if (s2.length() == 0) {
		std::cout << "error: missing string to replace with" << std::endl;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static bool	open_error(std::ifstream &infile, std::ofstream &outfile, std::string &in_name, std::string &out_name) {
	if (!infile.is_open()) {
		std::cout << "error: failed to open " << in_name << std::endl;
		return (true);
	}
	if (!outfile.is_open()) {
		std::cout << "error: failed to create " << out_name << std::endl;
		infile.close();
		return (true);
	}
	return (false);
}

static std::string	replace_line(std::string &line, std::string &s1, std::string &s2) {
	std::string	result;
	size_t 		start_pos;
	size_t 		i;
	size_t		s1_len;
	size_t		line_Len;

	s1_len = s1.length();
	line_Len = line.length();
	i = 0;
	start_pos = 0;
	while ((i = line.find(s1, i)) != std::string::npos) {
		result += line.substr(start_pos, i - start_pos);
		result += s2;
		i += s1_len;
		start_pos = i;
	}
	if (start_pos < line_Len)
		result += line.substr(start_pos, line_Len - start_pos);
	return (result);
}

static void	replace_content(std::ifstream &infile, std::ofstream &outfile, std::string &s1, std::string &s2) {
	std::string line;
	std::string result;

	while (std::getline(infile, line)) {
		result = replace_line(line, s1, s2);
		if (infile.eof())
			outfile << result;
		else
			outfile << result << std::endl;
	}
}

int	main(int argc, char **argv) {
	std::string	in_name;
	std::string out_name;
	std::string	s1;
	std::string	s2;

	if (get_input(in_name, s1, s2, argc, argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	out_name.append(in_name + ".replace");

	std::ifstream infile(in_name);
	std::ofstream outfile(out_name, std::ios_base::trunc);
	if (open_error(infile, outfile, in_name, out_name))
		return (EXIT_FAILURE);

	replace_content(infile, outfile, s1, s2);
	infile.close();
	outfile.close();
	return (EXIT_SUCCESS);
}
