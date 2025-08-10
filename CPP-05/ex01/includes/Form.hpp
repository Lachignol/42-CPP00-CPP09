/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 19:41:58 by ascordil          #+#    #+#             */
/*   Updated: 2025/06/05 17:24:33 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H

#define FORM_H

#include <iostream>
#include "./Bureaucrat.hpp"


class Form  
{
	private:
		const std::string _name;
		const unsigned int	_gradeToSign;
		const unsigned int	_gradeToExecute;
		bool	_isSigned;



	public:
		Form(void);
		Form(const std::string &name, unsigned int gradeToSign, unsigned int gradeToExecute);
		~Form();
		Form(const Form &other);
		Form &operator=(const Form &other);
		const std::string &getName(void) const;
		unsigned int getGradeToSign(void)const;
		unsigned int getGradeToExecute(void)const;
		bool 		   getisSigned(void)const;
		std::runtime_error GradeTooHighException(void);
		std::runtime_error GradeTooLowException(void);
		void	beSigned(const Bureaucrat &bureaucrat);

};

std::ostream &operator<<(std::ostream &output, const Form &bureaucrat);

#endif
