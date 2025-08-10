/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 19:41:58 by ascordil          #+#    #+#             */
/*   Updated: 2025/06/05 17:24:33 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_H

#define PRESIDENTIAL_H

#include <iostream>
#include "./Bureaucrat.hpp"
#include "./AForm.hpp"

class PresidentialPardonForm  : public AForm
{
	private:
		std::string _target;


	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(const std::string &target);
		~PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm &other);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
		const std::string &getTarget(void) const;
		std::runtime_error notSigned(void)const;
		std::runtime_error GradeTooLowForExecute(void)const;
		void	execute(const Bureaucrat &executor)const ;

};

#endif
