/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:15:14 by ehedeman          #+#    #+#             */
/*   Updated: 2025/01/16 14:30:00 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:

public:
	PresidentialPardonForm(std::string target);
	~PresidentialPardonForm();
	
	void		execute(Bureaucrat const &executor) const;
	void		beSigned(const Bureaucrat *b);
};
