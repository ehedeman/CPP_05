/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:54:02 by ehedeman          #+#    #+#             */
/*   Updated: 2025/01/16 14:24:19 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
private:
	const std::string		name;
	int						grade;
public:
							Bureaucrat(std::string _name, int _grade);	//constructor
							Bureaucrat(void);
							Bureaucrat(const Bureaucrat &copy);			//copy constructor
							~Bureaucrat(void);							//destructor

	Bureaucrat				&operator=(const Bureaucrat &copy);			//assignment operator

	//setters
	void					setGrade(int new_grade);
	//getters
	int						getGrade(void)const;
	const std::string		getName(void)const;

	//member functions
	void					IncrementGrade(void);
	void					DecrementGrade(void);
	void					signForm(AForm &f)const;
	void					executeForm(AForm const & form);
	
	//custom exceptions
	class 					GradeTooHighException : public std::exception
	{
		public:
			const char			*what(void)const throw();
	};
	class 					GradeTooLowException : public std::exception
	{
		public:
			const char			*what(void)const throw();
	};
};

std::ostream			&operator<<(std::ostream &o, Bureaucrat *b);