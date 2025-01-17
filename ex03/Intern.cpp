/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 13:52:09 by ehedeman          #+#    #+#             */
/*   Updated: 2025/01/17 15:34:22 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern constructor called." << std::endl;
}

Intern::Intern(const Intern &copy)
{
	std::cout << "Intern copy constructor called." << std::endl;
	*this = copy;
}

Intern::~Intern()
{
	std::cout << "Intern destructor called." << std::endl;
}

Intern					&Intern::operator=(const Intern &copy)
{
	std::cout << "Intern assignment operator called." << std::endl;
	if (this == &copy)
		return *this;
	else return (*this);
}

AForm	*Intern::makePres(std::string _target)
{
	AForm *form = new PresidentialPardonForm(_target);
	return (form);
}

AForm	*Intern::makeShrub(std::string _target)
{
	AForm *form = new ShrubberyCreationForm(_target);
	return (form);
}

AForm	*Intern::makeRobo(std::string _target)
{
	AForm *form = new RobotomyRequestForm(_target);
	return (form);
}

AForm	*Intern::makeForm(std::string form_name, std::string target_name)
{
	AForm *form;

	AForm *(Intern::*functionPointers[])(std::string) = \
		{&Intern::makeShrub, &Intern::makeRobo, &Intern::makePres};
	std::string forms[] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	for (int i = 0; i < 3; i++)
	{
		if (form_name == forms[i])
		{
			form = (this->*functionPointers[i])(target_name);
			return (form) ;
		}
	}
	throw NoSuchFormException();
	return (form);
}

const char	*Intern::NoSuchFormException::what(void)const throw()
{
	return("No such form.");
}