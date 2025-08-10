/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 21:19:38 by ascordil          #+#    #+#             */
/*   Updated: 2025/07/05 02:34:22 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MutantStack.hpp"

int main( void ) 
{
	MutantStack<int> mstack;
	std::cout << "Adress of original class: " << &mstack << std::endl;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	std::cout << "Content class: " << &mstack << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	MutantStack<int> s(mstack);
	std::cout << "Adress of copy: " << &s << std::endl;
	std::cout << "Content of copy: " << std::endl;
	MutantStack<int>::iterator at = s.begin();
	MutantStack<int>::iterator ate = s.end();
	++at;
	--at;
	while (at != ate)
	{
	std::cout << *at << std::endl;
	++at;
	}



	std::cout << "the same but with list" << std::endl;
	std::cout << "-----------------------" << std::endl;

	std::list<int> mlist;
	mlist.push_back(5);
	mlist.push_back(17);
	std::cout << mlist.back() << std::endl;
	mlist.pop_back();
	std::cout << mlist.size() << std::endl;
	mlist.push_back(3);
	mlist.push_back(5);
	mlist.push_back(737);
	//[...]
	mlist.push_back(0);
	std::list<int>::iterator itlist = mlist.begin();
	std::list<int>::iterator itelist = mlist.end();
	++itlist;
	--itlist;
	while (itlist != itelist)
	{
	std::cout << *itlist << std::endl;
	++itlist;
	}
	std::list<int> l(mlist);
	std::cout << "-----------------------" << std::endl;

	return 0;
}
