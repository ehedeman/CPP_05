/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:27:36 by ehedeman          #+#    #+#             */
/*   Updated: 2025/01/16 13:58:38 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(std::string _name, int s_grade, int e_grade):name(_name), \
	exe_grade(e_grade), sign_grade(s_grade)
{
	std::cout << "Form constructor called." << std::endl;
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

Form::Form(void): name("default"), exe_grade(50), sign_grade(50)
{
	std::cout << "Form default constructor called." << std::endl;
	this->_signed = false;
}

Form::Form(const Form &copy): name(copy.getName()), \
	exe_grade(copy.getExecGrade()), sign_grade(copy.getSignGrade()) 
{
	std::cout << "Form copy constructor called." << std::endl;
	this->_signed = copy.getSigned();
}

Form::~Form()
{
	std::cout << "Form destructor called." << std::endl;
}

Form				&Form::operator=(const Form &copy)
{
	std::cout << "Assignment operator called." << std::endl;
	if (this == &copy)
		return (*this);
	else
		this->_signed = copy.getSigned();
	return (*this);
}

//setters
// void			Form::setSigned()
// {
// 	this->_signed = !this->_signed;
// }

//getters
int					Form::getExecGrade()const{return (this->exe_grade);}
int					Form::getSignGrade()const{return (this->sign_grade);}
std::string			Form::getName()const{return (this->name);}
bool				Form::getSigned()const{return (this->_signed);}

void				Form::beSigned(const Bureaucrat *b)
{
	if (this->getSigned())
	{
		std::cout << "Oops. The form was already signed." << std::endl;
		return ;
	}
	if (b->getGrade() <= this->getSignGrade())
		this->_signed = true;
	else
		throw GradeTooLowException();
}

const char			*Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high.");
}

const char			*Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low.");
}

std::ostream		&operator<<(std::ostream &o, Form *f)
{
//	std::cout << "Form ostream operator called for " << f->getName() << std::endl;
	o << "Form " << f->getName();
	return (o);
}
