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
	std::cout << "\033[33m****** MAIN TEST *******\033[0m" << std::endl << std::endl;
//	Animal	animal; // will not work, because it's a abstract class!

	Animal	*p_animal;
	Cat		cat;

	p_animal = &cat;

	std::cout << std::endl;

	cat.set_idea(0, "Hmm...who a I?");
	cat.set_idea(1, "Maybe I'm a cat?...");
	cat.set_idea(2, "Yes! I am a cat!");
	cat.set_idea(3, "And look what I can do:)");

	cat.get_ideas();
	p_animal->make_sound();
	std::cout << std::endl;

	return (0);
}