/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 02:34:24 by ascordil          #+#    #+#             */
/*   Updated: 2025/07/07 01:56:49 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <bits/stdc++.h>

class PmergeMe
{
	private:
		std::vector<int>	_vec;
		std::deque<int>		_dec;


	public:
		~PmergeMe(void);
		PmergeMe(void);
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		bool	checkArgs(char **args);
		void	encapsulateInPair(std::deque<int> &numbers);
		void	run(char **args);
		void	fordJohnsonSort(std::deque<int>  &arr);
		void	fordJohnsonSort(std::vector<int>  &arr);
		void	fordJohnsonRecursiveVector(std::vector<int>  &arr,std::vector<size_t> &indices ,std::vector<int> &result);
		void	fordJohnsonRecursiveDeque(std::deque<int>  &arr,std::deque<size_t> &indices,std::deque<int> &result);
		void	fordJohnsonRecursiveVectorDebug(std::vector<int>  &arr,std::vector<size_t> &indices,std::vector<int> &result);
		std::vector<size_t>	jacobsthallIndices(size_t n);
		std::vector<size_t>	jacobsthallIndicesDebug(size_t n);
		void	printDeque(std::deque<int> &deque);
		void	printVector(std::vector<int> &vec);
		

};
