/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:15:27 by ehedeman          #+#    #+#             */
/*   Updated: 2025/01/17 13:48:14 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

//sign 25, exec 5

PresidentialPardonForm::PresidentialPardonForm(): \
	AForm("PresidentialPardonForm", 25, 5), target("default")
{
	std::cout << "PresidentialPardonForm default constructor called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string _target): \
	AForm("PresidentialPardonForm", 25, 5), target(_target)
{
	std::cout << "PresidentialPardonForm constructor called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy): \
	AForm("PresidentialPardonForm", 25, 5), target(copy.getTarget())
{
	std::cout << "PresidentialPardonForm copy constructor called." << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor called." << std::endl;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
	std::cout << "PresidentialPardonForm Assignment operartor called." << std::endl;
	if (this == &copy)
		return (*this);
	//class has only constants so nothing to reassign
	return (*this);	
}

std::string		PresidentialPardonForm::getTarget()const{return(this->target);}


void		PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() <= 5 && this->getSigned())
		std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	else if (!this->getSigned())
		throw FormNotSignedException();
	else if (executor.getGrade() > 5)
		throw GradeTooLowException();
}