/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:27:40 by ehedeman          #+#    #+#             */
/*   Updated: 2025/01/16 13:33:15 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string	name;
	const int			exe_grade;
	const int			sign_grade;
	bool				_signed;
	
public:
						Form(std::string _name, int s_grade, int e_grade);	//constructor
						Form(void);
						Form(const Form &copy);								//copy constructor
						~Form(void);										//destructor

	Form				&operator=(const Form &copy);						//assignment operator
	
	//setters
	//void				setSigned();
	//getters
	int					getExecGrade()const;
	int					getSignGrade()const;
	std::string			getName()const;
	bool				getSigned()const;
	
	//member functions
	void				beSigned(const Bureaucrat *b);
	//custom exceptions
	class 				GradeTooHighException : public std::exception
	{
		public:
			const char	*what() const throw();
	};
	class 				GradeTooLowException : public std::exception
	{
		public:
			const char	*what() const throw();
	};
};

std::ostream			&operator<<(std::ostream &o, Form *f);