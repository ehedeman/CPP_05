/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 13:52:09 by ehedeman          #+#    #+#             */
/*   Updated: 2025/01/17 14:11:36 by ehedeman         ###   ########.fr       */
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

AForm	*Intern::makeForm(std::string form_name, std::string target_name)
{
	AForm *form;
	if (form_name == "ShrubberyCreationForm")
		form = new ShrubberyCreationForm(target_name);
	else if (form_name == "RobotomyRequestForm")
		form = new RobotomyRequestForm(target_name);
	else if (form_name == "PresidentialPardonForm")
		form = new PresidentialPardonForm(target_name);
	else
		throw NoSuchFormException();
	return (form);
}

const char	*Intern::NoSuchFormException::what(void)const throw()
{
	return("No such form.");
}