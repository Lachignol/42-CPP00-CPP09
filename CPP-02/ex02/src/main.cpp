/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 21:18:19 by ascordil          #+#    #+#             */
/*   Updated: 2025/05/22 21:27:22 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;



	std::cout << "test-perso" << std::endl;
	std::cout << "valeur de a" << std::endl;
	std::cout << a << std::endl;
	std::cout << "post decrementation" << std::endl;
	std::cout << a-- << std::endl;
	std::cout << "valeur de a" << std::endl;
	std::cout << a << std::endl;
	std::cout << "pre incrementation" << std::endl;
	std::cout << ++a << std::endl;
	std::cout << "pre decrementation" << std::endl;
	std::cout << --a << std::endl;
	std::cout << "valeur de a" << std::endl;
	std::cout << a << std::endl;
	std::cout << "valeur de b" << std::endl;
	std::cout << b << std::endl;
	std::cout << "minimum entre a et b" << std::endl;
	std::cout << Fixed::min( a, b ) << std::endl;
	std::cout << " a + b" << std::endl;
	std::cout << a + b << std::endl;
	std::cout << " a - b" << std::endl;
	std::cout << a - b << std::endl;
	std::cout << " a / b" << std::endl;
	std::cout << a / b << std::endl;
	std::cout << " a * b" << std::endl;
	std::cout << a * b << std::endl;

	return 0;
}
