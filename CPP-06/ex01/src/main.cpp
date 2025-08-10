/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:23:03 by ascordil          #+#    #+#             */
/*   Updated: 2025/06/25 20:28:52 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"

int	main(void)
{
	Data data = {"Brad","Le-pitt",33};
	std::cout << "Adresse structure data: " << &data << std::endl;
	std::cout << "Name Data: " << data.name << std::endl;
	std::cout << "Lastname Data: " << data.lastName << std::endl;
	std::cout << "Age Data: " << data.age << std::endl;

	uintptr_t ptrTotest = Serializer::serialize(&data);
	std::cout << "Adresse Serializer: " << &ptrTotest << std::endl;
	std::cout << "Serializer value: " << ptrTotest << std::endl;

	Data *deserializeValue = Serializer::deserialize(ptrTotest);
	std::cout << "deserializer value: " << deserializeValue << std::endl;
	std::cout << "Name deserializer: " << deserializeValue->name << std::endl;
	std::cout << "Lastname deserializer: " << deserializeValue->lastName << std::endl;
	std::cout << "Age deserializer: " << deserializeValue->age << std::endl;
	if (&data == deserializeValue)
		std::cout << "Bien la meme adresse" << std::endl;
	else
		std::cout << "Pas la meme adresse" << std::endl;

}
