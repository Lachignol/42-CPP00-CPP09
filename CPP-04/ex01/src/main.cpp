/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:27:10 by ascordil          #+#    #+#             */
/*   Updated: 2025/06/03 19:27:01 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"
#include "../includes/WrongDog.hpp"

int	main(void)
{
	Animal *tabAnimal[20];
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	for (int i = 0 ; i < 20; i++)
	{
		if (i < 10)
			tabAnimal[i] = new Dog();
		else	
			tabAnimal[i] = new Cat();

		tabAnimal[i]->makeSound();
	}

	for (int i = 0 ; i < 20; i++)
	{
		delete  tabAnimal[i];
	}


	delete j;//should not create a leak
	delete i;


	// Main que j'ai genere par perplexity

	    std::cout << "=== Test polymorphisme et makeSound() ===" << std::endl;
	    const Animal* animals[4];

	    for (int i = 0; i < 2; i++)
		animals[i] = new Dog();
	    for (int i = 2; i < 4; i++)
		animals[i] = new Cat();

	    for (int i = 0; i < 4; i++)
	    {
		animals[i]->makeSound();  // Affiche le son spécifique (Dog ou Cat)
	    }

	    for (int i = 0; i < 4; i++)
		delete animals[i];

	    std::cout << "\n=== Test deep copy Brain ===" << std::endl;
	    Dog dog1;
	    dog1.getBrain()->setIdea("Manger", 0);
	    dog1.getBrain()->setIdea("Dormir", 1);

	    Dog dog2 = dog1; // Utilisation du constructeur de copie profond
	    dog2.getBrain()->setIdea("Jouer", 0);

	    std::cout << "dog1 Brain idée 0: " << dog1.getBrain()->getIdea(0) << std::endl; // Doit afficher "Manger"
	    std::cout << "dog2 Brain idée 0: " << dog2.getBrain()->getIdea(0) << std::endl; // Doit afficher "Jouer"

	    Cat cat1;
	    cat1.getBrain()->setIdea("Chasser", 0);

	    Cat cat2;
	    cat2 = cat1; // Utilisation de l'opérateur d'affectation profond
	    cat2.getBrain()->setIdea("Dormir", 0);

	    std::cout << "cat1 Brain idée 0: " << cat1.getBrain()->getIdea(0) << std::endl; // Doit afficher "Chasser"
	    std::cout << "cat2 Brain idée 0: " << cat2.getBrain()->getIdea(0) << std::endl; // Doit afficher "Dormir"


	return (0);
}
