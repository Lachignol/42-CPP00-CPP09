/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 21:33:20 by ascordil          #+#    #+#             */
/*   Updated: 2025/05/24 21:12:05 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ".././includes/Fixed.hpp"
#include ".././includes/Point.hpp"


static Fixed	formule(Point a, Point b, Point const point)
{
	Fixed	result;

	result = (a.getX() - point.getX()) * (b.getY() - point.getY()) - (a.getY() - point.getY()) * (b.getX() - point.getX());
	return (result);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{

	Fixed d1 = formule(point,a,b);
	Fixed d2 = formule(point,b,c);
	Fixed d3 = formule(point,c,a);

	if (d1 > Fixed(0) && d2 > Fixed(0) && d3 > Fixed(0))
		return (true);
	if (d1 < Fixed(0) && d2 < Fixed(0) && d3 < Fixed(0))
		return (true);

	return (false);
}
