/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:15:27 by ehedeman          #+#    #+#             */
/*   Updated: 2025/01/16 14:34:00 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

//sign 25, exec 5

PresidentialPardonForm::PresidentialPardonForm(std::string target)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

void		PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() <= 5 && this->getSigned())
		blah();
}
