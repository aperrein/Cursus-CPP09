/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:00:25 by aperrein          #+#    #+#             */
/*   Updated: 2023/11/07 13:00:27 by aperrein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(char *tab[])
{

    std::ifstream   input(tab[1]);
    if (!input.is_open())
        throw NotOpen();

    input.close();
    fillBase();
    checkInput(tab[1]);
    
}

BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & copy)
{
    *this = copy;
}

BitcoinExchange &       BitcoinExchange::operator=(BitcoinExchange const & rhs)
{
    this->_base = rhs.getBase();
    return (*this);
}

std::map <std::string, float>       BitcoinExchange::getBase() const
{
    return(this->_base);
}

char const *        BitcoinExchange::NotOpen::what() const throw()
{
    return ("Error: could not open file.");
}


void                BitcoinExchange::checkInput(char *s)
{
    std::string		date;
	std::string		line;
	float			value;
	int	i = 0;

    std::ifstream   ifs(s);

    while (getline(ifs, line))
	{
		if (line.find("|") == std::string::npos)
			std::cout << "Error: bad input => " << line << std::endl;
        else if (i != 0)
		{
			date = strtok((char *)line.c_str(), "|");
			value = std::atof(strtok(NULL, "\n"));
			try
			{
				validInput(date, value);
				this->_base.insert(std::pair<std::string, float>(date, value));
				printRes(date, value);
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
		}
		i++;
    }

}

void                BitcoinExchange::fillBase()
{
	std::string		date;
	std::string		line;
	float			value;

    std::ifstream   ifsb("data.csv");

	while (getline(ifsb, line))
	{
		date = strtok((char *)line.c_str(), ",");
		value = std::atof(strtok(NULL, "\n"));
		this->_base.insert(std::pair<std::string, float>(date, value));
	}

    ifsb.close();
}

void        BitcoinExchange::validInput(std::string date, float value)
{
	std::string ok = date;
	std::string	yy;
	std::string	mm;
	std::string	dd;
	std::string	len;

	yy = strtok((char *)ok.c_str(), "-");
	mm = strtok(NULL, "-");
	dd = strtok(NULL, "\0");
	len = yy + mm + dd;
	if (len.length() > 10 || len.length() < 9)
		throw std::logic_error("Error: bad input => " + date);
	if ((std::atoi(len.c_str()) > 20231109) || std::atoi(len.c_str()) < 20090102)
		throw std::logic_error("Error: bad input => " + date);
	if (std::atoi(mm.c_str()) > 12 || std::atoi(dd.c_str()) > 31)
		throw std::logic_error("Error: bad input => " + date);
	if (value > 1000)
		throw std::logic_error("Error: too large number.");
	if (value < 0)
		throw std::logic_error("Error: not positive number");

	std::map<std::string, float>::iterator it = _base.find(date);
	
	if (it != _base.end())
	{
		std::stringstream ss;
		std::string test = "";

		ss << value * it->second;
		ss >> test;
		throw std::logic_error(it->first + " => " + test);
	}
}


void        BitcoinExchange::printRes(std::string date, float value)
{
	std::map<std::string, float>::iterator it = _base.find(date);

	if (it != _base.end())
	{
		std::cout << it->first;
		it--;
	 	std::cout << " => " << value << " = " << (value * it->second) << std::endl;

	this->_base.erase(date);
	}
}
