/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:13:45 by ehedeman          #+#    #+#             */
/*   Updated: 2025/01/16 14:29:08 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

//sign 72, exec 45

RobotomyRequestForm::RobotomyRequestForm(std::string target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void		RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() <= 45 && this->getSigned())
        blah();
}