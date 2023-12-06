/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:00:31 by aperrein          #+#    #+#             */
/*   Updated: 2023/11/07 13:00:33 by aperrein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <iomanip>
# include <cstring>
# include <cstdlib>
# include <exception>
# include <fstream>
# include <map>
# include <sstream>

class BitcoinExchange
{
private:
        BitcoinExchange();
        std::map <std::string, float>   _base;

public:
        BitcoinExchange(char *tab[]);
        ~BitcoinExchange();
        BitcoinExchange(BitcoinExchange const & copy);
        BitcoinExchange &   operator=(BitcoinExchange const & rhs);

        std::map <std::string, float>       getBase() const;

        void        fillBase();
        void        checkInput(char *);
        void        validInput(std::string date, float value);
        void        printRes(std::string date, float value);
        


        class NotOpen : public std::exception 
        {
        public:
            virtual char const  *what() const throw();
        };

};

#endif
