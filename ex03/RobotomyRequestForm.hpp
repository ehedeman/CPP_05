/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:14:08 by ehedeman          #+#    #+#             */
/*   Updated: 2025/01/17 13:20:05 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
    const std::string	target;
public:
							RobotomyRequestForm();
							RobotomyRequestForm(std::string _target);
							RobotomyRequestForm(const RobotomyRequestForm &copy);
							~RobotomyRequestForm();
	
	RobotomyRequestForm	&operator=(const RobotomyRequestForm &copy);
	
	std::string				getTarget()	const;

	void					execute(Bureaucrat const &executor) const;
   // void		beSigned(const Bureaucrat *b);
};
