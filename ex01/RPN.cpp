/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:47:02 by aperrein          #+#    #+#             */
/*   Updated: 2023/11/09 10:47:03 by aperrein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::~RPN()
{}

RPN::RPN(char *s)
{
	int		left;
	int		right;
	int		result;

	int		number = 0;
	int		sign = 0;
    int     i = 0;

	while(s[i])
	{
		if (s[i] == ' ')
			i++;
		if (isdigit(s[i]))
			number++;
		else if ((s[i]) == '*' || (s[i]) == '/' || (s[i]) == '+' || (s[i]) == '-')
			sign++;
        i++;
	}

	if (sign != number - 1)
		throw std::logic_error("Error syntax: not inverted Polish mathematical expression");

    i = 0;
    while (s[i])
	{
		if (s[i] == ' ')
			i++;
		if (isdigit(s[i]))
		{
			this->_stack.push(s[i] - '0');
		}
		else if ((s[i]) == '*' || (s[i]) == '/' || (s[i]) == '+' || (s[i]) == '-')
		{
			right = this->_stack.top();
			this->_stack.pop();
			left = this->_stack.top();
			this->_stack.pop();
            if (s[i] == '+')
				result = left + right;
			if (s[i] == '-')
				result = left - right;
			if (s[i] == '*')
				result = left * right;
			if (s[i] == '/')
				result = left / right;

			this->_stack.push(result);
		}
		else
            throw std::logic_error("Error syntax: not inverted Polish mathematical expression");
        i++;
	}
	std::cout << result << std::endl;

}
