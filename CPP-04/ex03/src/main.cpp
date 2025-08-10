/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 23:42:53 by ascordil          #+#    #+#             */
/*   Updated: 2025/06/03 16:28:58 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AMateria.hpp"
#include "../includes/MateriaSource.hpp"
#include "../includes/Ice.hpp"
#include "../includes/Cure.hpp"
#include "../includes/Character.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	AMateria *temp;
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	temp = new Cure();
	src->learnMateria(temp);
	ICharacter* me = new Character("me");
	AMateria* tmp;
	AMateria* tmpFailed;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmpFailed = src->createMateria("test");
	me->equip(tmpFailed);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete temp;
	delete me;
	delete src;
	return 0;
}
