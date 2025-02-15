/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:53:58 by ehedeman          #+#    #+#             */
/*   Updated: 2025/01/17 13:38:30 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	{
		try
		{
			Bureaucrat h("Herman", 150);
			Bureaucrat l("Louis", 1);
			Form g("Great Form", 50, 20);

			g.beSigned(&h);
			g.beSigned(&l);
			g.beSigned(&l);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		try
		{
			Bureaucrat h("Herman", 150);
			Bureaucrat l("Louis", 1);
			Form g("Great Form", 50, 20);

			g.beSigned(&l);
			l.signForm(g);
			g.beSigned(&l);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
}