/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 21:18:19 by ascordil          #+#    #+#             */
/*   Updated: 2025/05/24 21:29:58 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"
#include "../includes/Point.hpp"

/*int main( void )*/
/*{*/
/*	Point a(Fixed(0), Fixed(0));*/
/*	Point b(Fixed(10), Fixed(0));*/
/*	Point c(Fixed(0), Fixed(10));*/
/**/
/*	Point p1(Fixed(2), Fixed(2));*/
/**/
/*	if (bsp(a,b,c,p1))*/
/*		std::cout << "Dedans" << std::endl;*/
/*	else */
/*		std::cout << "not in" << std::endl;*/
/*	return 0;*/
/*}*/

int main() {
    // Triangle ABC
    Point a(0.0f, 0.0f);
    Point b(10.0f, 0.0f);
    Point c(0.0f, 10.0f);

    // Points à tester
    Point p1(2.0f, 2.0f);    // dedans
    Point p2(10.0f, 2.0f);   // dehors
    Point p3(5.0f, 0.0f);    // sur le bord
    Point p4(1.0f, 8.0f);    // dedans
    Point p5(-1.0f, 1.0f);   // dehors
    Point p6(3.0f, 3.0f);    // dedans
    Point p7(0.0f, 0.0f);    // sommet du triangle

    std::cout << "p1(2,2):   " << (bsp(a, b, c, p1) ? "DEDANS" : "DEHORS") << std::endl;
    std::cout << "p2(10,2):  " << (bsp(a, b, c, p2) ? "DEDANS" : "DEHORS") << std::endl;
    std::cout << "p3(5,0):   " << (bsp(a, b, c, p3) ? "DEDANS" : "DEHORS") << std::endl;
    std::cout << "p4(1,8):   " << (bsp(a, b, c, p4) ? "DEDANS" : "DEHORS") << std::endl;
    std::cout << "p5(-1,1):  " << (bsp(a, b, c, p5) ? "DEDANS" : "DEHORS") << std::endl;
    std::cout << "p6(3,3):   " << (bsp(a, b, c, p6) ? "DEDANS" : "DEHORS") << std::endl;
    std::cout << "p7(0,0):   " << (bsp(a, b, c, p7) ? "DEDANS" : "DEHORS") << std::endl;

    return 0;
}

