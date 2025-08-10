/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 21:37:28 by ascordil          #+#    #+#             */
/*   Updated: 2025/05/30 22:44:45 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BRAIN_H

#define BRAIN_H

#include <iostream>

class Brain
{
	private:
		std::string ideas[100];

	public:
		Brain(void);
		~Brain(void);
		Brain(const Brain &other);
		Brain &operator=(const Brain &other);
		void	printIdeas(void)const;
		void	setIdea(const std::string &idea , unsigned int idx);
		std::string	getIdea(unsigned int idx)const;
};
#endif
