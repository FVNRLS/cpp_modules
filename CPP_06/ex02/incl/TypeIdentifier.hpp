/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TypeIdentifier.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 17:40:24 by rmazurit          #+#    #+#             */
/*   Updated: 2022/12/26 17:40:24 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "iostream"
#include "random"

class Base {

public:
	virtual ~Base();
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

Base	*generate();
void 	identify(Base *p);
void 	identify(Base &p);
