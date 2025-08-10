/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 21:21:39 by ascordil          #+#    #+#             */
/*   Updated: 2025/05/22 21:25:38 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

const int Fixed::_fractBit = 8;


//CONSTRUCTEUR / DESTRUCTOR

Fixed::Fixed():_rawBits(0)
{
	/*std::cout << "Default constructor called" << std::endl;*/
}



Fixed::Fixed(const Fixed &other)
{
	/*std::cout << "Copy constructor called" << std::endl;*/
	*this = other;
}

Fixed::Fixed(const int &number)
{
	/*std::cout << "Int constructor called" << std::endl;*/
	this->_rawBits = number * (1 << _fractBit);
}

Fixed::Fixed(const float &floatNumber)
{
	/*std::cout << "Float constructor called" << std::endl;*/
	this->_rawBits = roundf(floatNumber * (1 << _fractBit));
}

Fixed::~Fixed()
{
	/*std::cout << "Destructor called" << std::endl;*/
}


//GETERS / SETTERS

int	Fixed::getRawBits(void) const
{
	return (this->_rawBits);
}


void	Fixed::setRawBits(int const raw)
{
	this->_rawBits = raw;
}


//METHOD MAN


const Fixed	&Fixed::min(const Fixed &instance1, const Fixed &instance2)
{
	if (instance1 > instance2)
		return (instance2);
	else
		return (instance1);
}

Fixed	&Fixed::min(Fixed &instance1, Fixed &instance2)
{
	if (instance1 > instance2)
		return (instance2);
	else
		return (instance1);
}



const Fixed	&Fixed::max(const Fixed &instance1, const Fixed &instance2)
{
	if (instance1 > instance2)
		return (instance1);
	else 
		return (instance2);
}



Fixed	&Fixed::max(Fixed &instance1, Fixed &instance2)
{
	if (instance1 > instance2)
		return (instance1);
	else 
		return (instance2);

}

float	Fixed::toFloat(void)const
{
	return ((float)this->getRawBits() / (1 << _fractBit));
}


int	Fixed::toInt(void)const
{
	return ((this->getRawBits()) / (int)(1 << _fractBit));
}

//OPERATOR

std::ostream	&operator<<(std::ostream &output, Fixed const &fixedInstance)
{
	output << fixedInstance.toFloat();
	return (output);
}

Fixed	&Fixed::operator=(const Fixed &other)
{
	/*std::cout << "Copy assignment operator called" << std::endl;*/
	if (this != &other)
	{
		this->_rawBits = other.getRawBits();
	}
	return (*this);
}


bool	Fixed::operator>(const Fixed &other)const
{
	return (this->getRawBits() > other.getRawBits());
}

bool	Fixed::operator<(const Fixed &other)const
{
	return (this->getRawBits() < other.getRawBits());
}

bool	Fixed::operator<=(const Fixed &other)const
{
	return (this->getRawBits() <= other.getRawBits());
}

bool	Fixed::operator>=(const Fixed &other)const
{
	return (this->getRawBits() >= other.getRawBits());
}

bool	Fixed::operator==(const Fixed &other)const
{
	return (this->getRawBits() == other.getRawBits());
}

bool	Fixed::operator!=(const Fixed &other)const
{
	return (this->getRawBits() != other.getRawBits());
}

Fixed	Fixed::operator+(const Fixed &other)
{
	return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed	Fixed::operator-(const Fixed &other)
{
	return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed	Fixed::operator*(const Fixed &other)
{
	return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed	Fixed::operator/(const Fixed &other)
{
	return (Fixed(this->toFloat() / other.toFloat()));
}

Fixed	&Fixed::operator++(void)
{
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

Fixed	&Fixed::operator--(void)
{
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed temp = *this;
	this->setRawBits(this->getRawBits() + 1);
	return (temp);
}

Fixed	Fixed::operator--(int)
{
	Fixed temp = *this;
	this->setRawBits(this->getRawBits() - 1);
	return (temp);
}
