/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:14:08 by ehedeman          #+#    #+#             */
/*   Updated: 2025/01/16 14:30:08 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:

public:
    RobotomyRequestForm(std::string target);
    ~RobotomyRequestForm();
    
    void		execute(Bureaucrat const &executor) const;
    void		beSigned(const Bureaucrat *b);
};
