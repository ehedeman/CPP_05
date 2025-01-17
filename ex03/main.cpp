/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:53:58 by ehedeman          #+#    #+#             */
/*   Updated: 2025/01/17 14:13:20 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main(void)
{
	Bureaucrat a("Helmut", 50);
	Bureaucrat b("Helga", 4);
	Intern c;

	AForm *formA;
	ShrubberyCreationForm shrub(".");
	PresidentialPardonForm pres("./file.txt");
	RobotomyRequestForm robo("Helga");
	std::cout << std::endl;
	{
		try
		{
			formA = c.makeForm("ShrubberyCreationForm", ".");
			b.signForm(*formA);
			b.executeForm(*formA);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		delete(formA);
	}
	std::cout << std::endl;
	{
		try
		{
			formA = c.makeForm("SomeForm", ".");
			b.signForm(*formA);
			b.executeForm(*formA);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	std::cout << std::endl;
}