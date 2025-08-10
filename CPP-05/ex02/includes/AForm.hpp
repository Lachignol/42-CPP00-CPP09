/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 19:41:58 by ascordil          #+#    #+#             */
/*   Updated: 2025/06/05 17:24:33 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_H

#define AFORM_H

#include <iostream>
#include "./Bureaucrat.hpp"


class AForm  
{
	private:
		const std::string _name;
		const unsigned int	_gradeToSign;
		const unsigned int	_gradeToExecute;
		bool	_isSigned;



	public:
		AForm(void);
		AForm(const std::string &name, unsigned int gradeToSign, unsigned int gradeToExecute);
		virtual ~AForm();
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		const std::string &getName(void) const;
		unsigned int getGradeToSign(void)const;
		unsigned int getGradeToExecute(void)const;
		bool 		   getisSigned(void)const;
		std::runtime_error GradeTooHighException(void);
		std::runtime_error GradeTooLowException(void);
		void	beSigned(const Bureaucrat &bureaucrat);
		virtual void	execute(const Bureaucrat &bureaucrat)const = 0;

};

std::ostream &operator<<(std::ostream &output, const AForm &bureaucrat);

#endif
