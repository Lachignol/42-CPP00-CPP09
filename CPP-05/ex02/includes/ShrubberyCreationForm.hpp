/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 19:41:58 by ascordil          #+#    #+#             */
/*   Updated: 2025/06/05 17:24:33 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_H

#define SHRUBBERY_H

#include <iostream>
#include "./Bureaucrat.hpp"
#include "./AForm.hpp"


class ShrubberyCreationForm  : public AForm
{
	private:
		std::string _target;


	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(const std::string &target);
		~ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
		const std::string &getTarget(void) const;
		std::runtime_error notSigned(void)const;
		std::runtime_error GradeTooLowForExecute(void)const;
		std::runtime_error errorCreationFile(void)const;
		void	execute(const Bureaucrat &executor)const ;

};

#endif
