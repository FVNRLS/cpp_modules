/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:46:42 by rmazurit          #+#    #+#             */
/*   Updated: 2022/12/26 16:46:42 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Serializer.hpp"

void	print_data(Data *data) {
	std::cout << "name:	" << data->name << std::endl;
  	std::cout << "age:	" << data->age << std::endl << std::endl;
}

int main () {


	std::cout << "\033[33m****** CONSTRUCTOR *******\033[0m" << std::endl;
	Serializer	serializer;
	Data		*data;

	data = new Data;
	if (!data) {
		std::cout << "Error memory allocation failed" << std::endl;
		return (1);
	}
	data->name = "Gosha";
	data->age = 30;
	std::cout << "A pointer to struct 'data' was created" << std::endl;
	print_data(data);

	std::cout << "\033[33m****** TESTING SERIALIZATION *******\033[0m" << std::endl;
	Data		*tester;

	tester = serializer.deserialize(serializer.serialize(data));
	std::cout << "Serialization and deserialization of the struct 'data' finished" << std::endl;
	print_data(tester);

	std::cout << "\033[33m****** DESTRUCTOR *******\033[0m" << std::endl;

	return (0);
}