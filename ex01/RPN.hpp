/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:46:57 by aperrein          #+#    #+#             */
/*   Updated: 2023/11/09 10:46:58 by aperrein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <iomanip>
# include <cstring>
# include <cstdlib>
# include <exception>
# include <fstream>
# include <stack>
# include <sstream>

class RPN
{
private:
		std::stack<int>	_stack;        
        RPN();
		RPN(RPN const &copy);
		RPN &	operator=(RPN const &rhs);

public:
		RPN(char *s);		
        ~RPN();


};

#endif
