/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 21:19:36 by ascordil          #+#    #+#             */
/*   Updated: 2025/05/23 16:39:10 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FIXED_H
#define _FIXED_H

#include <iostream>
#include <cmath>

class Fixed
{
	public:
		Fixed();
		Fixed(const int &integer);
		Fixed(const float &floatNumber);
		Fixed(const Fixed &other);
		Fixed 	&operator=(const Fixed &other);
		bool	operator>(const Fixed &other)const;
		bool	operator<(const Fixed &other)const;
		bool	operator<=(const Fixed &other)const;
		bool	operator>=(const Fixed &other)const;
		bool	operator==(const Fixed &other)const;
		bool	operator!=(const Fixed &other)const;
		Fixed	operator+(const Fixed &other);
		Fixed	operator-(const Fixed &other);
		Fixed	operator*(const Fixed &other);
		Fixed	operator/(const Fixed &other);
		Fixed	&operator++(void);
		Fixed	operator++(int);
		Fixed	&operator--(void);
		Fixed	operator--(int);
		static const Fixed	&min(const Fixed &instance1, const Fixed &instance2);
		static Fixed	&min(Fixed &instance1, Fixed &instance2);
		static const Fixed	&max(const Fixed &instance1, const Fixed &instance2);
		static Fixed	&max(Fixed &instance1, Fixed &instance2);
		~Fixed();
		int	getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void)const;
		int	toInt(void)const;

	private:
		int	_rawBits;
		static const int _fractBit;
	
};

std::ostream	&operator<<(std::ostream &output, Fixed const &fixedInstance);

#endif
