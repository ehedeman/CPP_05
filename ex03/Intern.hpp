/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 13:52:05 by ehedeman          #+#    #+#             */
/*   Updated: 2025/01/17 14:01:36 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
public:
							Intern();
							Intern(const Intern &copy);			//copy constructor
							~Intern(void);	
	Intern					&operator=(const Intern &copy);

	AForm					*makeForm(std::string form_name, std::string target_name);
	class 					NoSuchFormException : public std::exception
	{
		public:
			const char		*what(void)const throw();
	};
};