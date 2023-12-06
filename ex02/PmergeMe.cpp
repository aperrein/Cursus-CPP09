/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:25:29 by aperrein          #+#    #+#             */
/*   Updated: 2023/11/10 10:25:30 by aperrein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(char *tab[])
{
    int val = 0;
    int i = 1;
    while (tab[i])
	{
        int j = 0;
		while (tab[i][j])
        {
			if (!isdigit(tab[i][j]))
				throw std::logic_error("Error : not digit");
            j++;
        }
		val = atoi(tab[i]);
		_vec.push_back(val);
		_list.push_back(val);
        i++;
	}
    printRes();
}

PmergeMe::~PmergeMe()
{}

long long int	Timer()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000000) + tv.tv_usec;
}

void            InsertVec(std::vector<int>& vec, int left, int right)
{
    int i = left + 1;

    while (i <= right)
    {
        int val = vec[i];
        int j = i - 1;
        while (j >= left && vec[j] > val)
        {
            vec[j + 1] = vec[j];
            j--;
        }
        vec[j + 1] = val;
        i++;
    }
}

void            InsertList(std::list<int>& lst)
{
    std::list<int>::iterator it = lst.begin();
    it++; // Déplacer l'itérateur vers le deuxième élément
    int val = 0;
    //std::list<int>::iterator tmp;

    while (it != lst.end())
    {
        val = *it;
        std::list<int>::iterator it2 = it;
        it2--;

        while (it2 != lst.begin() && *it2 > val)
        {
            --it2;
            if (*it2 <= val)
            {
                ++it2;
                lst.insert(it2, val);
                lst.erase(it);
                it = it2;
                it2--;
            }
        }
        if (*it2 >= val && it2 == lst.begin())
        {
            lst.insert(it2, val); // Insérer au début de la liste si la valeur est la plus petite
            lst.erase(it);
            it = it2;
        }

        it++;
    }
}

void            MergeVec(std::vector<int>& vec, int left, int mid, int right)
{
    int n1 = mid - left +1;
    int n2 = right - mid;

    std::vector<int>  Lvec(n1);
    std::vector<int>  Rvec(n2);

    int i = -1;  // pos dans left
    int j = -1;  // pos dans right
    while (++i < n1)
        Lvec[i] = vec[left + i];
    while (++j < n2)
        Rvec[j] = vec[mid + 1 + j];

    i = 0;
    j = 0;
    int g = left; // pos generale dans vec
    while (i < n1 && j < n2)
    {
        if (Lvec[i] <= Rvec[j])
        {
            vec[g] = Lvec[i];
            i++;
        }
        else 
        {
            vec[g] = Rvec[j];
            j++;
        }
        g++;
    }

    while (i < n1)
    {
        vec[g] = Lvec[i];
        i++;
        g++;
    }

    while (j < n2)
    {
        vec[g] = Rvec[j];
        j++;
        g++;
    }

}

void        MergeList(std::list<int>& lst, std::list<int> left, std::list<int> right)
{
    std::list<int>::iterator itlst = lst.begin();
	std::list<int>::iterator itLeft = left.begin();
	std::list<int>::iterator itRight = right.begin();

	while (itLeft != left.end() && itRight != right.end())
	{
		if (*itLeft <= *itRight)
		{
			*itlst = *itLeft;
			itLeft++;
		}
		else
		{
			*itlst = *itRight;
			itRight++;
		}
		itlst++;
	}

	while (itLeft != left.end())
	{
		*itlst = *itLeft;
		itLeft++;
		itlst++;
	}

	while (itRight != right.end())
	{
		*itlst = *itRight;
		itRight++;
		itlst++;
	}
}

void            PmergeMe::MIVec(std::vector<int>& vec, int left, int right, int k)
{
    if (right - left + 1 <= k)
        InsertVec(vec, left, right);
    else
    {
        int mid =  left + (right - left) / 2;

        MIVec(vec, left, mid, k);
        MIVec(vec, mid + 1, right, k);

        MergeVec(vec, left, mid, right);
    }
}

void            PmergeMe::MIList(std::list<int>& lst, int k)
{
    if (lst.size() <= static_cast<unsigned long>(k))
        InsertList(lst);
    else
    {
        int mid = lst.size() / 2;
        int i = -1;
	    std::list<int>::iterator it = lst.begin();

	    while (++i < mid)
		    ++it;

	    std::list<int> left(lst.begin(), it);
	    std::list<int> right(it, lst.end());

	    MIList(left, k);
	    MIList(right, k);
	    MergeList(lst, left, right);
    }
}


void            PmergeMe::printRes()
{
    long long int lstStart;
    long long int lstEnd;
    long long int vecStart;
    long long int vecEnd;
    int k = 4;

    std::list<int>::const_iterator it = _list.begin();

    std::cout << "Before : ";
    while (it != _list.end())
        std::cout << *it++ << " ";
    std::cout << std::endl;

    lstStart = Timer();
    MIList(_list, k);
    lstEnd = Timer();
    vecStart = Timer();
    MIVec(_vec, 0, _vec.size() - 1, k);
    vecEnd = Timer();
    std::cout << "Time to process a range of " << _vec.size();
    std::cout << " elements with std::list : " << lstEnd - lstStart << " us" << std::endl;
    std::cout << "Time to process a range of " << _vec.size();
    std::cout << " elements with std::vector : " << vecEnd - vecStart << " us" << std::endl;

    std::vector<int>::const_iterator it2 = _vec.begin();
    std::cout << "After vec : ";
    while (it2 != _vec.end())
        std::cout << *it2++ << " ";

    std::cout << std::endl;

    std::list<int>::const_iterator it3 = _list.begin();
    std::cout << "After list : ";
    while (it3 != _list.end())
        std::cout << *it3++ << " ";

}
