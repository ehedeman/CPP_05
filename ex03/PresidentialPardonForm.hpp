/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:15:14 by ehedeman          #+#    #+#             */
/*   Updated: 2025/01/17 13:36:46 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	const std::string	target;
public:
							PresidentialPardonForm();
							PresidentialPardonForm(std::string _target);
							PresidentialPardonForm(const PresidentialPardonForm &copy);
							~PresidentialPardonForm();
	
	PresidentialPardonForm	&operator=(const PresidentialPardonForm &copy);
	
	std::string				getTarget()	const;

	void					execute(Bureaucrat const &executor) const;
};
