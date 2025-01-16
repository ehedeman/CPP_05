/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:54:05 by ehedeman          #+#    #+#             */
/*   Updated: 2025/01/16 13:15:25 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

//constructors
Bureaucrat::Bureaucrat(void): name("default"), grade(130)
{
	std::cout << "Bureaucrat default constructor called." << std::endl;
}

Bureaucrat::Bureaucrat(std::string _name, int _grade): name(_name)
{
	std::cout << "Bureaucrat constructor called." << std::endl;
	if (_grade > 150)
		throw GradeTooLowException();
	else if (_grade < 1)
		throw GradeTooHighException();
	else
		this->grade = _grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy): name(copy.getName() + "_copy")
{
	std::cout << "Bureaucrat copy constructor called for " << this->getName() << std::endl;
	this->grade = copy.getGrade();
}

//destructor
Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called." << std::endl;
}

//assignment operators
Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &copy)
{
	std::cout << "Bureaocrat Assignment operator called for " << this->getName() << std::endl;
	if (this == &copy)
		return *this;
	this->grade = copy.getGrade();
	return *this;
}

//setters
void					Bureaucrat::setGrade(int new_grade)
{
	if (new_grade > 150)
		throw GradeTooLowException();
	else if (new_grade < 1)
		throw GradeTooHighException();
	else
		this->grade = new_grade;
}

//getters
int						Bureaucrat::getGrade(void)const{return (this->grade);}
const std::string		Bureaucrat::getName(void)const{return (this->name);}

//subject specific functions
void					Bureaucrat::IncrementGrade(void)
{
	this->setGrade(this->grade - 1);
}
void			Bureaucrat::DecrementGrade(void)
{
	this->setGrade(this->grade + 1);
}
void			Bureaucrat::signForm(const Form *f)const
{
	if (f->getSigned())
		std::cout << this << " signed " << f << std::endl;
	else
		std::cout << this << " couldn't sign " << f << " because their grade was too low." << std::endl;
}

//custom exceptions
const char	*Bureaucrat::GradeTooHighException::what(void)const throw()
{
	return("Woah there! Thats a really high grade, you sure we have that?");
}
const char	*Bureaucrat::GradeTooLowException::what(void)const throw()
{
	return("Woah there! Thats a really high grade, you sure we have that?");
}

std::ostream &operator<<(std::ostream &o, Bureaucrat *b)
{
	std::cout << "Bureaocrat ostream operator called for " << b->getName() << std::endl;
	o << b->getName() << ", Bureaucrat grade " << b->getGrade();
	return (o);
}