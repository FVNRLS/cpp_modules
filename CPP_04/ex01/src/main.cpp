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
//BASIC TESTING
	std::cout << "\033[33m****** MAIN TEST *******\033[0m" << std::endl << std::endl;
	{
		std::cout << "\033[31m****** CONSTRUCTION *******\033[0m" << std::endl;
		const Animal	*animals[NUM_IDEAS];

		for (int i = 0; i < NUM_IDEAS; i++) {
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
			}
		}

		std::cout << std::endl << "\033[31m****** DESTRUCTION *******\033[0m" << std::endl;
		for (int i = 0; i < NUM_IDEAS; i++) {
			delete(animals[i]);
			std::cout << std::endl;
		}
	}

//PROOF OF DEEP COPY
std::cout << "\033[33m****** PROOF OF DEEP COPY *******\033[0m" << std::endl << std::endl;
	{
		std::cout << "\033[31m****** CONSTRUCTION *******\033[0m" << std::endl;
		Cat	cat;
		cat.set_idea(0, "Meaow... probably I'm an original cat...");

		std::cout << std::endl;
		std::cout << "\033[31m****** DEEP COPY *******\033[0m" << std::endl;

		std::cout << std::endl;
		Cat cat_copy = Cat(cat);
		std::cout << std::endl;

		std::cout << "Original cat:	";
		cat.get_ideas();
		std::cout << std::endl;

		std::cout << "Copy cat:	";
		cat_copy.get_ideas();
		std::cout << "Copy cat:	";
		cat_copy.set_idea(0, "Murmurmur... i changed my idea, because probably I'm an copy cat...");
		cat_copy.get_ideas();

		std::cout << "Original cat:	"; //proof, that copied cat doesn't point to the same memory as original cat
		cat.get_ideas();

		std::cout << "\033[31m****** DESTRUCTION *******\033[0m" << std::endl;
//		system("leaks ex01");
	}

	return (0);
}