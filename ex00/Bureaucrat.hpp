/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:54:02 by ehedeman          #+#    #+#             */
/*   Updated: 2025/01/16 12:23:29 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Bureaucrat
{
private:
	const std::string	name;
	int					grade;
public:
							Bureaucrat(std::string _name, int _grade);	//constructor
							Bureaucrat(void);
							Bureaucrat(const Bureaucrat &copy);			//copy constructor
							~Bureaucrat(void);							//destructor

	Bureaucrat				&operator=(const Bureaucrat &copy);			//assignment operator
	std::ostream			&operator<<(const Bureaucrat &_this);

	//setters
	void					setGrade(int new_grade);
	//getters
	int						getGrade(void)const;
	const std::string		getName(void)const;

	//subject specific functions
	void					IncrementGrade(void);
	void					DecrementGrade(void);

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
