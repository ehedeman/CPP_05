/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:53:58 by ehedeman          #+#    #+#             */
/*   Updated: 2025/01/16 12:59:56 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	{
		try
		{
			Bureaucrat b("Herman", 150);
			std::cout << &b << std::endl;
			b.DecrementGrade();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	{
		try
		{
			Bureaucrat f("Marnie", 160);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	
		{
		try
		{
			Bureaucrat f("Linda", 1);
			f.IncrementGrade();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	{
		try
		{
			Bureaucrat f("Bob", 0);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
}