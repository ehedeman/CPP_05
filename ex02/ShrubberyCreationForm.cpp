/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:11:06 by ehedeman          #+#    #+#             */
/*   Updated: 2025/01/16 14:28:42 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

//sign 145, exec 137

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void		ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() <= 137 && this->getSigned())
		blah();
		//insert code to open file here
}