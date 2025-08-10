/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 19:41:58 by ascordil          #+#    #+#             */
/*   Updated: 2025/06/05 20:49:47 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H

#define BUREAUCRAT_H

#include <iostream>


class Form;

class Bureaucrat  
{
	private:
		const std::string _name;
		unsigned int	_grade;



	public:
		Bureaucrat(void);
		Bureaucrat(const std::string &name, unsigned int grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);
		const std::string &getName(void) const;
		unsigned int getGrade(void)const;
		void	incrementGrade();
		void	decrementGrade();
		void	signForm(Form &form)const;
		std::runtime_error GradeTooHighException(void);
		std::runtime_error GradeTooLowException(void);

};

std::ostream &operator<<(std::ostream &output, const Bureaucrat &bureaucrat);

#endif
