/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 21:31:19 by ascordil          #+#    #+#             */
/*   Updated: 2025/05/24 21:16:11 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _POINT_H
#define _POINT_H

#include "./Fixed.hpp"

class Point
{
	public:
		Point();
		Point(const float argX, const float argY);
		Point(const Fixed &argX, const Fixed &argY);
		Point(const Point &other);
		Point &operator=(const Point &other);
		Fixed getX(void)const;
		Fixed getY(void)const;
		~Point();



	private:
		const Fixed _x;
		const Fixed _y;
	
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
