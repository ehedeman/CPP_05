/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:27:40 by ehedeman          #+#    #+#             */
/*   Updated: 2025/01/16 13:59:23 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string	name;
	const int			exe_grade;
	const int			sign_grade;
	bool				_signed;
	
public:
						AForm(std::string _name, int s_grade, int e_grade);	//constructor
						AForm(void);
						AForm(const AForm &copy);								//copy constructor
	virtual				~AForm(void);										//destructor

	AForm				&operator=(const AForm &copy);						//assignment operator
	
	//setters
	//void				setSigned();
	//getters
	int					getExecGrade()const;
	int					getSignGrade()const;
	std::string			getName()const;
	bool				getSigned()const;
	
	//member functions
	void				beSigned(const Bureaucrat *b);
	virtual void		executeForm(AForm const & form) = 0;				//purely virtual function
	//custom exceptions
	class 				GradeTooHighException : public std::exception
	{
		public:
			virtual const char	*what() const throw();
	};
	class 				GradeTooLowException : public std::exception
	{
		public:
			virtual const char	*what() const throw();
	};
};

std::ostream			&operator<<(std::ostream &o, AForm *f);