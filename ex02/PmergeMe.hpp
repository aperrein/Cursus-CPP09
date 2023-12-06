/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:25:38 by aperrein          #+#    #+#             */
/*   Updated: 2023/11/10 10:25:40 by aperrein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <iomanip>
# include <cstring>
# include <cstdlib>
# include <exception>
# include <fstream>
# include <sstream>
# include <vector>
# include <list>
# include <sys/time.h>
# include <algorithm>


class PmergeMe
{
private:
        PmergeMe();
        PmergeMe(PmergeMe const & copy);
        PmergeMe &  operator=(PmergeMe const & rhs);
        std::vector<int>    _vec;
	std::list<int>  _list;

public:
        PmergeMe(char *tab[]);
        ~PmergeMe();

        void            MIVec(std::vector<int>& vec, int left, int right, int k);
        void            MIList(std::list<int>& lst, int k);
        void            printRes();
};

#endif
