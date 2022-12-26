/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TypeIdentifier.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 17:40:15 by rmazurit          #+#    #+#             */
/*   Updated: 2022/12/26 17:40:15 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/TypeIdentifier.hpp"

Base::~Base() {}

static A	*create_a() {
	A	*a;

	a = new A;
	std::cout << "Object of class A was created" << std::endl;
	return (a);
}

static B	*create_b() {
	B	*b;

	b = new B;
	std::cout << "Object of class B was created" << std::endl;
	return (b);
}

static C	*create_c() {
	C	*c;

	c = new C;
	std::cout << "Object of class C was created" << std::endl;
	return (c);
}

Base	*generate() {
	int		rand_num;
	Base *(*base[3])() = {reinterpret_cast<Base *(*)()>(&create_a),
						  reinterpret_cast<Base *(*)()>(&create_b),
						  reinterpret_cast<Base *(*)()>(&create_c)};
	rand_num =  rand() % 3;
	return (base[rand_num]());
}

//Explicit downcast using pointer
void	identify(Base *p) {
	if (dynamic_cast<A *>(p) != NULL)
		std::cout << "Identified by pointer: type A" << std::endl;
	else if (dynamic_cast<B *>(p) != NULL)
		std::cout << "Identified by pointer: type B" << std::endl;
	else if (dynamic_cast<C *>(p) != NULL)
		std::cout << "Identified by pointer: type C" << std::endl;
	else
		std::cout << "The type doesn't belong to any of classes A,B or C " << std::endl;
}

//Explicit downcast using reference
void	identify(Base &p) {
	Base	&tmp = (Base &)"Some_memory_address";

	try {
		tmp = dynamic_cast<A &>(p);
		std::cout << "Identified by reference: type A" << std::endl;
		return;
	}
	catch(const std::exception &e) {}

	try {
		tmp = dynamic_cast<B &>(p);
		std::cout << "Identified by reference: type B" << std::endl;
		return;
	}
	catch(const std::exception &e) {}

	try {
		tmp = dynamic_cast<C &>(p);
		std::cout << "Identified by reference: type C" << std::endl;
		return;
	}
	catch(const std::exception &e) {}
	std::cout << "The type doesn't belong to any of classes A,B or C " << std::endl;
}
