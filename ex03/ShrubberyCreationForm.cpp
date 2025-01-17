/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:11:06 by ehedeman          #+#    #+#             */
/*   Updated: 2025/01/17 13:51:04 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

//sign 145, exec 137

ShrubberyCreationForm::ShrubberyCreationForm(): \
	AForm("ShrubberyCreationForm", 145, 137), target("default")
{
	std::cout << "ShrubberyCreationForm default constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string _target): \
	AForm("ShrubberyCreationForm", 145, 137), target(_target)
{
	std::cout << "ShrubberyCreationForm constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy): \
	AForm("ShrubberyCreationForm", 145, 137), target(copy.getTarget())
{
	std::cout << "ShrubberyCreationForm copy constructor called." << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called." << std::endl;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
	std::cout << "ShrubberyCreationForm Assignment operartor called." << std::endl;
	if (this == &copy)
		return (*this);
	//class has only constants so nothing to reassign
	return (*this);	
}

std::string		ShrubberyCreationForm::getTarget()const{return(this->target);}

void		ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() <= 137 && this->getSigned())
	{
		std::string		filename = this->target + "/file.txt";
		std::ofstream	file(filename.c_str());
		for (int i = 0; i < 5; i++)
		{
			file <<
			"         A" << "               " << "         A" << "               " << std::endl <<
			"        d$b" << "              " << "        d$b" << "              " << std::endl <<
			"      .d\\$$b." << "           " << "       .d\\$$b." << "           " << std::endl <<
			"    .d$i$$\\$$b." << "         " << "     .d$i$$\\$$b." << "         " << std::endl <<
			"       d$$@b" << "             " << "       d$$@b" << "             " << std::endl <<
			"      d\\$$$ib" << "           " << "       d\\$$$ib" << "           " << std::endl <<
			"    .d$$$\\$$$b" << "          " << "     .d$$$\\$$$b" << "          " << std::endl <<
			"  .d$$@$$$$\\$$ib." << "       " << "   .d$$@$$$$\\$$ib." << "       " << std::endl <<
			"      d$$i$$b" << "            " << "      d$$i$$b" << "            " << std::endl <<
			"     d\\$$$$@$b" << "          " << "      d\\$$$$@$b" << "          " << std::endl <<
			"  .d$@$$\\$$$$$@b." << "       " << "   .d$@$$\\$$$$$@b." << "       " << std::endl <<
			".d$$$$i$$$\\$$$$$$b." << "     " << " .d$$$$i$$$\\$$$$$$b." << "     " << std::endl <<
			"        ###" << "              " << "        ###" << "              " << std::endl <<
			"        ###" << "              " << "        ###" << "              " << std::endl <<
			"        ###" << "              " << "        ###" << "              " << std::endl <<
			std::endl;
		}
		file.close();
	}
	else if (!this->getSigned())
		throw FormNotSignedException();
	else if (executor.getGrade() > 137)
		throw GradeTooLowException();
}

