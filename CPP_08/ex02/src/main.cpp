/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 12:32:00 by rmazurit          #+#    #+#             */
/*   Updated: 2022/12/29 12:32:00 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/MutantStack.hpp"

int main() {
	std::cout << "\033[33m****** BASIC TEST *******\033[0m" << std::endl;
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);

		std::cout << mstack.top() << std::endl; mstack.pop();
		std::cout << mstack.size() << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;

		while (it != ite) {
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}

	std::cout << std::endl << "\033[33m****** TEST WITH RANDOM UPPERCASE CHARS WITH CONST ITERATOR *******\033[0m" << std::endl;
	{
		MutantStack<char> char_stack;
		srand(time(NULL));
		char	c;

		for (int i = 0; i < 10; i++) {
			c = (rand() % 26) + 'A';
			char_stack.push(c);
		}
		
		MutantStack<char>::const_iterator	it = char_stack.begin();
		MutantStack<char>::const_iterator	ite = char_stack.end();
		while (it != ite) {
			std::cout << *it << std::endl;
			//*it = 'A'; not executable, because of const iterator
			it++;
		}
	}

	std::cout << std::endl << "\033[33m****** TEST WITH RANDOM UPPERCASE CHARS WITH CONST ITERATOR *******\033[0m" << std::endl;
	{
		std::list<char> my_list;

		my_list.push_front('A');
		my_list.push_back('B');
		my_list.push_back('C');

		std::list<char>::const_iterator	it = my_list.begin();
		std::list<char>::const_iterator	ite = my_list.end();
		while (it != ite) {
			std::cout << *it << std::endl;
			it++;
		}
	}

	return 0;
}