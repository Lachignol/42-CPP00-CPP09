/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 23:25:32 by ascordil          #+#    #+#             */
/*   Updated: 2025/06/02 12:09:06 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_H

#define MATERIASOURCE_H


#include "./IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private :
		std::string _name;
		AMateria*	memoryMateria[4];
	public:

	MateriaSource();
	~MateriaSource();
	MateriaSource(std::string const & name);
	MateriaSource( const MateriaSource & other);
	MateriaSource &operator=( const MateriaSource & other);
	std::string const &getName() const;
	void learnMateria(AMateria* materia);
	AMateria* createMateria(std::string const & type);

};

#endif
