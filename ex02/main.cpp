/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:25:08 by aperrein          #+#    #+#             */
/*   Updated: 2023/11/10 10:25:10 by aperrein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int     main(int ac, char *av[])
{
    if (ac < 3)
	{
		std::cout << "Program must take at least 2 integers" << std::endl;
		return (1);
	}

	try
	{
		PmergeMe(static_cast<char **>(av));
	}

	catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    return (0);
}