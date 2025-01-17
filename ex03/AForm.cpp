/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AFormm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:27:36 by ehedeman          #+#    #+#             */
/*   Updated: 2025/01/16 14:30:27 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(std::string _name, int s_grade, int e_grade):name(_name), \
	exe_grade(e_grade), sign_grade(s_grade)
{
	std::cout << "AForm constructor called." << std::endl;
	if (s_grade < 1)
		throw GradeTooHighException();
	else if (s_grade > 150)
		throw GradeTooLowException();
	if (e_grade < 1)
		throw GradeTooHighException();
	else if (e_grade > 150)
		throw GradeTooLowException();
	this->_signed = false;
}

AForm::AForm(void): name("default"), exe_grade(50), sign_grade(50)
{
	std::cout << "AForm default constructor called." << std::endl;
	this->_signed = false;
}

AForm::AForm(const AForm &copy): name(copy.getName()), \
	exe_grade(copy.getExecGrade()), sign_grade(copy.getSignGrade()) 
{
	std::cout << "AForm copy constructor called." << std::endl;
	this->_signed = copy.getSigned();
}

AForm::~AForm()
{
	std::cout << "AForm destructor called." << std::endl;
}

AForm				&AForm::operator=(const AForm &copy)
{
	std::cout << "Assignment operator called." << std::endl;
	if (this == &copy)
		return (*this);
	else
		this->_signed = copy.getSigned();
	return (*this);
}

//setters
void			AForm::setSigned(bool state)
{
	this->_signed = state;
}

//getters
int					AForm::getExecGrade()const{return (this->exe_grade);}
int					AForm::getSignGrade()const{return (this->sign_grade);}
std::string			AForm::getName()const{return (this->name);}
bool				AForm::getSigned()const{return (this->_signed);}

void				AForm::beSigned(const Bureaucrat *b)
{
	if (this->getSigned())
	{
		std::cout << "Oops. The AForm was already signed." << std::endl;
		return ;
	}
	if (b->getGrade() <= this->getSignGrade())
		this->_signed = true;
	else
		throw GradeTooLowException();
}

const char			*AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high.");
}

const char			*AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low.");
}

const char			*AForm::FormNotSignedException::what() const throw()
{
	return ("Form not signed.");
}

std::ostream		&operator<<(std::ostream &o, AForm *f)
{
//	std::cout << "AForm ostream operator called for " << f->getName() << std::endl;
	o << "AForm " << f->getName();
	return (o);
}
