/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 19:41:58 by ascordil          #+#    #+#             */
/*   Updated: 2025/06/05 17:24:33 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_H

#define ROBOTOMY_H

#include <iostream>
#include "./Bureaucrat.hpp"
#include "./AForm.hpp"


class RobotomyRequestForm  : public AForm
{
	private:
		std::string _target;


	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(const std::string &target);
		~RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm &other);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
		const std::string &getTarget(void) const;
		std::runtime_error notSigned(void)const;
		std::runtime_error GradeTooLowForExecute(void)const;
		void	execute(const Bureaucrat &executor)const;

};

#endif
