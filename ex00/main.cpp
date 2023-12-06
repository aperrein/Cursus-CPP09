/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:00:03 by aperrein          #+#    #+#             */
/*   Updated: 2023/11/07 13:00:05 by aperrein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int 	main(int ac, char *argv[])
{
	if (ac != 2)
	{
		std::cout << "Program must take a file as argument." << std::endl;
		return (1);
	}

	try
	{
		BitcoinExchange(static_cast<char **>(argv));
	}

	catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }

	return 0;
}
