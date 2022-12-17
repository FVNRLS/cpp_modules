/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:59:24 by rmazurit          #+#    #+#             */
/*   Updated: 2022/12/16 16:59:24 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Cat.hpp"
#include "../incl/Dog.hpp"
#include "../incl/WrongCat.hpp"

int	main() {
	std::cout << "\033[1;31m******** TESTING ANIMAL CLASS WITH DEFAULT CONSTRUCTOR ********\033[0m" << std::endl;
	{
		std::cout << std::endl;
		Animal	default_animal;
		Cat		cat;
		Dog		dog;

		std::cout << std::endl;

		default_animal.make_sound();
		cat.make_sound();
		dog.make_sound();
		std::cout << std::endl;
	}

	std::cout << std::endl;

	std::cout << "\033[1;31m******** TESTING ANIMAL CLASS WITH COPY CONSTRUCTOR ********\033[0m" << std::endl;
	{
		std::cout << std::endl;
		Animal	default_animal;
		Cat		cat;
		Dog		dog;

		std::cout << std::endl;

		default_animal.make_sound();
		cat.make_sound();
		dog.make_sound();
		std::cout << std::endl;
	}

	std::cout << std::endl;

	std::cout << "\033[1;31m******** TESTING WRONG ANIMAL CLASS WITH DEFAULT CONSTRUCTOR ********\033[0m" << std::endl;
	{
		std::cout << std::endl;
		WrongAnimal	wrong_animal;
		WrongCat	wrong_cat;

		std::cout << std::endl;
		wrong_animal.make_sound();
		wrong_cat.make_sound();
		std::cout << std::endl;
	}

	std::cout << std::endl;

	std::cout << "\033[1;31m******** TESTING POLYMORPHISM ********\033[0m" << std::endl;
	{
		std::cout << std::endl;
		const Animal	*p_animal;

		Cat	cat;
		p_animal = &cat;

		std::cout << std::endl;

		p_animal->make_sound(); //access of derived object method via pointer of the base class
		std::cout << std::endl;
	}

//	std::cout << std::endl;
//
//	std::cout << "\033[1;31m******** TESTING THE TEST FROM SUBJECT ********\033[0m" << std::endl;
//	{
//		const Animal* meta = new Animal();
//		const Animal* j = new Dog();
//		const Animal* i = new Cat();
//		std::cout << j->get_type() << " " << std::endl;
//		std::cout << i->get_type() << " " << std::endl;
//		i->make_sound(); //will output the cat sound!
//		j->make_sound();
//		meta->make_sound();
//	}

	return (0);
}