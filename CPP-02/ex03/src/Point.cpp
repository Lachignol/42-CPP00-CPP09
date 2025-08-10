/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 21:30:18 by ascordil          #+#    #+#             */
/*   Updated: 2025/05/24 21:22:09 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ".././includes/Point.hpp"

Point::Point():_x(0),_y(0)
{

}

Point::~Point(){}

Point::Point(const float argX, const float argY):_x(argX),_y(argY){}

Point::Point(const Fixed &argX, const Fixed &argY):_x(argX),_y(argY){}

Point::Point(const Point &other):_x(other._x),_y(other._y){}

Point &Point::operator=(const Point &other)
{
	static_cast<void>(other);
	return (*this);
}

Fixed Point::getX(void)const
{
	return (this->_x);
}

Fixed	Point::getY(void)const
{
	return(this->_y);
}

/*Point	Point::operator-(const Point &other)*/
/*{*/
/*	Point result = {static_cast<const float>(static_cast<Fixed>this->toFloat()) - static_cast<Fixed>(other.toFloat()))};*/
/*}*/
