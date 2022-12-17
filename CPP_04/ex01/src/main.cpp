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

int main() {
	std::cout << "\033[31m****** CONSTRUCTION *******\033[0m" << std::endl;
	const Animal	*animals[NUM_IDEAS];

	for (int i = 0; i < NUM_IDEAS; i++)
	{
		if (i % 2 == 0) {
			Cat	*cat;
			cat = new Cat();
			animals[i] = cat;
			if (!animals[i]) {
				perror("allocation failed");
				exit(1);
			}
			for (int j = 0; j < NUM_IDEAS; j++)
				cat->set_idea(j, "Meaow... probably I'm a cat...");
			std::cout << "-----------------------------" << std::endl;
			cat->get_ideas();
			std::cout << std::endl;
		}
		else {
			Dog	*dog;
			dog = new Dog;
			animals[i] = dog;
			if (!animals[i]) {
				perror("allocation failed");
				exit(1);
			}
			for (int j = 0; j < NUM_IDEAS; j++)
				dog->set_idea(j, "Woof... probably I'm a dog...");
			std::cout << "-----------------------------" << std::endl;
			dog->get_ideas();
			std::cout << std::endl;
		}
	}

	std::cout << std::endl;

	std::cout << "\033[31m****** DESTRUCTION *******\033[0m" << std::endl;
	for (int i = 0; i < NUM_IDEAS; i++) {
		delete(animals[i]);
		std::cout << std::endl;
	}

////THIS PART IS FOR TESTING DEEP COPY ↓
//
//	std::cout << std::endl << std::endl;
//	std::cout << "#### showing that the copy constructor creates a deep copy ####" << std::endl;
//	std::cout << std::endl;
//
//	std::cout << "\033[34mConstructing\033[0m" << std::endl;
//	Dog *a = new Dog();
//
//	a->set_idea(0, "I have to sniff it");
//	a->set_idea(1, "I have to pee on it");
//	a->set_idea(2, "I have to sniff it again");
//	a->set_idea(101, "some shit");
//
//	Dog *b = new Dog(*a);
//
//	std::cout << std::endl;
//
//	std::cout << "\033[34mTesting a\033[0m" << std::endl;
//	std::cout << "The " << a->get_type() << " a has the following ideas: " << std::endl;
//	a->get_ideas();
//	std::cout << std::endl;
//
//	std::cout << "\033[34mDeconstructing a\033[0m" << std::endl;
//	delete(a);
//	std::cout << std::endl;
//
//	std::cout << "\033[34mTesting b\033[0m" << std::endl;
//	std::cout << "The " << b->get_type() << " b has the following ideas: " << std::endl;
//	b->get_ideas();
//	std::cout << std::endl;
//
//	std::cout << "\033[34mDeconstructing b\033[0m" << std::endl;
//	delete(b);

	return (0);
}