/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:11:04 by ehedeman          #+#    #+#             */
/*   Updated: 2025/01/17 13:36:41 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
	const std::string	target;
public:
							ShrubberyCreationForm();
							ShrubberyCreationForm(std::string _target);
							ShrubberyCreationForm(const ShrubberyCreationForm &copy);
							~ShrubberyCreationForm();
	
	ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &copy);
	
	std::string				getTarget()	const;

	void					execute(Bureaucrat const &executor) const;
};
