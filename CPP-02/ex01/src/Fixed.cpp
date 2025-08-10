/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 21:21:39 by ascordil          #+#    #+#             */
/*   Updated: 2025/05/22 19:00:26 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

const int Fixed::_fractBit = 8;

Fixed::Fixed(const int &number)
{
	std::cout << "Int constructor called" << std::endl;
	this->_rawBits = number * (1 << _fractBit);
}

Fixed::Fixed(const float &floatNumber)
{
	std::cout << "Float constructor called" << std::endl;
	this->_rawBits = roundf(floatNumber * (1 << _fractBit));
}

float	Fixed::toFloat(void)const
{
	return ((float)this->getRawBits() / (1 << _fractBit));
}


int	Fixed::toInt(void)const
{
	return ((this->getRawBits()) / (int)(1 << _fractBit));
}


Fixed::Fixed():_rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

std::ostream	&operator<<(std::ostream &output, Fixed const &fixedInstance)
{
	output << fixedInstance.toFloat();
	return (output);
}

Fixed	&Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_rawBits = other.getRawBits();
	}
	return (*this);
}


int	Fixed::getRawBits(void) const
{
	return (this->_rawBits);
}


void	Fixed::setRawBits(int const raw)
{
	this->_rawBits = raw;
}

