/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2072/01/16 14:13:45 by ehedeman          #+#    #+#             */
/*   Updated: 2025/01/17 13:48:14 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

//sign 72, exec 45

RobotomyRequestForm::RobotomyRequestForm(): \
	AForm("RobotomyRequestForm", 72, 45), target("default")
{
	std::cout << "RobotomyRequestForm default constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string _target): \
	AForm("RobotomyRequestForm", 72, 45), target(_target)
{
	std::cout << "RobotomyRequestForm constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy): \
	AForm("RobotomyRequestForm", 72, 45), target(copy.getTarget())
{
	std::cout << "RobotomyRequestForm copy constructor called." << std::endl;
	*this = copy;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called." << std::endl;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
	std::cout << "RobotomyRequestForm Assignment operartor called." << std::endl;
	if (this == &copy)
		return (*this);
	//class has only constants so nothing to reassign
	return (*this);	
}

std::string		RobotomyRequestForm::getTarget()const{return(this->target);}

static int _chance = 0;

void		RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() <= 45 && this->getSigned())
	{
		if (_chance % 2)
			std::cout << this->target << " has been robotomized successfully." << std::endl;
		else
			std::cout << "Robotomy has failed." << std::endl;
		_chance++;
	}
	else if (!this->getSigned())
		throw FormNotSignedException();
	else if (executor.getGrade() > 45)
		throw GradeTooLowException();
}