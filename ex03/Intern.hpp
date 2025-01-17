/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 13:52:05 by ehedeman          #+#    #+#             */
/*   Updated: 2025/01/17 15:33:01 by ehedeman         ###   ########.fr       */
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
	AForm					*makeShrub(std::string _target);
	AForm					*makePres(std::string _target);
	AForm					*makeRobo(std::string _target);

	class 					NoSuchFormException : public std::exception
	{
		public:
			const char		*what(void)const throw();
	};
};