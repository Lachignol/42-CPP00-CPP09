/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 02:35:39 by ascordil          #+#    #+#             */
/*   Updated: 2025/07/08 22:00:00 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>
#include <algorithm>
#include <stdexcept>
#include <cassert>

// Destructor
PmergeMe::~PmergeMe(void) {}

// Constructor
PmergeMe::PmergeMe(void) {}

// Copy constructor
PmergeMe::PmergeMe(const PmergeMe &other) : _vec(other._vec), _dec(other._dec) {}

// Assignment operator
PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		this->_vec = other._vec;
		this->_dec = other._dec;
	}
	return (*this);
}

bool PmergeMe::checkArgs(char **args)
{
	this->_vec.clear();
	this->_dec.clear();

	int i = 1;
	while (args[i])
	{
		char *endptr = NULL;
		long val_long = strtol(args[i], &endptr, 10);
		if (*endptr != '\0' || args[i] == endptr) 
		{
			throw std::runtime_error("Only digit is ok");
			return false;
		}
		if (val_long > INT_MAX || val_long < 1) 
		{
			if (val_long < 1)
			{
				throw std::runtime_error("Number must be positive");
				return false; 
			}
			throw std::runtime_error("Number is larger than a integer");
			return false;
		}
		int val_int = static_cast<int>(val_long);
		this->_dec.push_back(val_int);
		this->_vec.push_back(val_int);
		i++;
	}
	return true;
}

void PmergeMe::run(char **args)
{
	if (!checkArgs(args))
		return;
	std::cout << "Avant tri (vector) : ";
	for (size_t i = 0; i < _vec.size(); i++)
		std::cout << _vec[i] << " ";
	std::cout << std::endl;
	std::cout << "Avant tri (deque) : ";
	for (size_t i = 0; i < _dec.size(); i++)
		std::cout << _dec[i] << " ";
	std::cout << std::endl;

	clock_t start_vec = clock();
	fordJohnsonSort(_vec);
	clock_t end_vec = clock();
	double duration_vec = (double)(end_vec - start_vec) / CLOCKS_PER_SEC * 1e6;

	clock_t start_deq = clock();
	fordJohnsonSort(_dec);
	clock_t end_deq = clock();
	double duration_deq = (double)(end_deq - start_deq) / CLOCKS_PER_SEC * 1e6;

	std::cout << "Après tri (vector) : \n";
	printVector(_vec);
	std::cout << "Après tri (deque) : \n";
	printDeque(_dec);
	std::cout << "Time to process a range of " << _vec.size() << " elements with std::vector : "
	      << duration_vec << " us" << std::endl;
	std::cout << "Time to process a range of " << _dec.size() << " elements with std::deque : "
	      << duration_deq << " us" << std::endl;

}

void PmergeMe::fordJohnsonSort(std::vector<int> &arr)
{
	if (arr.size() < 2)
		return;
	std::vector<size_t> indices(arr.size());
	for (size_t i = 0; i < indices.size(); i++)
		indices[i] = i;

	std::vector<int> result;
	fordJohnsonRecursiveVector(arr, indices, result);

	for (size_t i = 0; i < arr.size(); i++)
		arr[i] = result[i];
}

void PmergeMe::fordJohnsonSort(std::deque<int> &arr)
{
	if (arr.size() < 2)
		return;
    	std::deque<size_t> indices(arr.size());
    	for (size_t i = 0; i < arr.size(); i++)
		indices[i] = i;

	std::deque<int> result;
	fordJohnsonRecursiveDeque(arr, indices, result);

	for (size_t i = 0; i < arr.size(); i++)
		arr[i] = result[i];
}


void PmergeMe::fordJohnsonRecursiveVector(std::vector<int> &arr, std::vector<size_t> &indices, std::vector<int> &result)
{
	result.clear();
	size_t n = indices.size();

	if (n == 1)
	{
		result.push_back(arr[indices[0]]);
		return;
	}

	std::vector<size_t> minIndices;
	std::vector<size_t> maxIndices;

	for (size_t i = 0; i + 1 < n; i += 2)
	{
		if (arr[indices[i]] < arr[indices[i + 1]])
		{
	    		minIndices.push_back(indices[i]);
	    		maxIndices.push_back(indices[i + 1]);
		}
		else
		{
			minIndices.push_back(indices[i + 1]);
			maxIndices.push_back(indices[i]);
		}
	}

	if (n % 2 != 0)
		minIndices.push_back(indices[n - 1]);

	std::vector<int> sortedMax;
	fordJohnsonRecursiveVector(arr, maxIndices, sortedMax);

	std::vector<int> sorted = sortedMax;
	int firstMin = arr[minIndices[0]];
	std::vector<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), firstMin);
	sorted.insert(pos, firstMin);

	if (minIndices.size() > 1)
	{
		std::vector<size_t> jacobOrder = jacobsthallIndices(minIndices.size() - 1);

		for (size_t i = 0; i < jacobOrder.size(); i++)
		{
		    size_t idx = jacobOrder[i] + 1;
		    if (idx < minIndices.size())
		    {
			int value = arr[minIndices[idx]];
			pos = std::lower_bound(sorted.begin(), sorted.end(), value);
			sorted.insert(pos, value);
		    }
		}
	}

	for (size_t i = 0; i < sorted.size(); i++)
	result.push_back(sorted[i]);
}


void PmergeMe::fordJohnsonRecursiveDeque(std::deque<int> &arr, std::deque<size_t> &indices, std::deque<int> &result)
{
	result.clear();
	size_t n = indices.size();

	if (n == 1)
	{
		result.push_back(arr[indices[0]]);
		return;
	}

	std::deque<size_t> minIndices;
	std::deque<size_t> maxIndices;

	for (size_t i = 0; i + 1 < n; i += 2)
	{
		int val1 = arr[indices[i]];
		int val2 = arr[indices[i + 1]];
		if (val1 < val2)
		{
		    minIndices.push_back(indices[i]);
		    maxIndices.push_back(indices[i + 1]);
		}
		else
		{
		    minIndices.push_back(indices[i + 1]);
		    maxIndices.push_back(indices[i]);
		}
	}

	if (n % 2 != 0)
	{
		minIndices.push_back(indices[n - 1]);
	}

	std::deque<int> sortedMax;
	fordJohnsonRecursiveDeque(arr, maxIndices, sortedMax);


	std::deque<int> sorted = sortedMax;
	int firstMin = arr[minIndices[0]];
	std::deque<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), firstMin);
	sorted.insert(pos, firstMin);


	if (minIndices.size() > 1)
	{
		std::vector<size_t> jacobOrder = jacobsthallIndices(minIndices.size() - 1);

		for (size_t i = 0; i < jacobOrder.size(); ++i)
		{
			size_t idx = jacobOrder[i] + 1;
			if (idx < minIndices.size())
			{
				int value = arr[minIndices[idx]];
				pos = std::lower_bound(sorted.begin(), sorted.end(), value);
				sorted.insert(pos, value);
			}
		}
	}

	for (size_t i = 0; i < sorted.size(); ++i)
		result.push_back(sorted[i]);
}

std::vector<size_t> PmergeMe::jacobsthallIndices(size_t n)
{
	std::vector<size_t> indices;
	size_t j1 = 1;
	size_t j2 = 2;

	while (j2 <= n)
	{
		indices.push_back(j2 - 1);
		size_t next = j2 + 2 * j1;
		j1 = j2;
		j2 = next;
	}

	for (size_t i = 0; i < n; i++)
	{
		if (std::find(indices.begin(), indices.end(), i) == indices.end())
			indices.push_back(i);
	}
	return indices;
}

void PmergeMe::fordJohnsonRecursiveVectorDebug(std::vector<int> &arr, std::vector<size_t> &indices, std::vector<int> &result)
{
	result.clear();
	size_t n = indices.size();

	std::cout << "DEBUG: Appel fordJohnsonRecursive avec " << n << " indices, valeurs: ";
	for (size_t i = 0; i < n; ++i)
		std::cout << arr[indices[i]] << " ";
	std::cout << std::endl;

	// Cas de base : un seul élément, il est déjà trié
	if (n == 1)
	{
		std::cout << "DEBUG: Cas base atteint avec un élément: " << arr[indices[0]] << std::endl;
		result.push_back(arr[indices[0]]);
		return;
	}

	// Séparer les indices en minimums et maximums par paires
	std::vector<size_t> minIndices;
	std::vector<size_t> maxIndices;

	for (size_t i = 0; i + 1 < n; i += 2)
	{
		int val1 = arr[indices[i]];
		int val2 = arr[indices[i + 1]];
		if (val1 < val2)
		{
		    minIndices.push_back(indices[i]);
		    maxIndices.push_back(indices[i + 1]);
		    std::cout << "DEBUG: Paire (" << val1 << ", " << val2 << ") => min: " << val1 << ", max: " << val2 << std::endl;
		}
		else
		{
		    minIndices.push_back(indices[i + 1]);
		    maxIndices.push_back(indices[i]);
		    std::cout << "DEBUG: Paire (" << val1 << ", " << val2 << ") => min: " << val2 << ", max: " << val1 << std::endl;
		}
	}

	// Si nombre impair, dernier élément ajouté aux minimums
	if (n % 2 != 0)
	{
	minIndices.push_back(indices[n - 1]);
	std::cout << "DEBUG: Élément impair ajouté à minIndices: " << arr[indices[n - 1]] << std::endl;
	}

	// Affichage des minimums et maximums extraits
	std::cout << "DEBUG: minIndices valeurs: ";
	for (size_t i = 0; i < minIndices.size(); ++i)
		std::cout << arr[minIndices[i]] << " ";
	std::cout << std::endl;

	std::cout << "DEBUG: maxIndices valeurs: ";
	for (size_t i = 0; i < maxIndices.size(); ++i)
		std::cout << arr[maxIndices[i]] << " ";
	std::cout << std::endl;

	// Tri récursif des maximums
	std::vector<int> sortedMax;
	fordJohnsonRecursiveVector(arr, maxIndices, sortedMax);

	std::cout << "DEBUG: Résultat trié des maxIndices: ";
	for (size_t i = 0; i < sortedMax.size(); ++i)
		std::cout << sortedMax[i] << " ";
	std::cout << std::endl;

	// Construire la séquence triée en insérant le premier minimum dans sortedMax trié
	std::vector<int> sorted = sortedMax;
	int firstMin = arr[minIndices[0]];
	std::vector<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), firstMin);
	sorted.insert(pos, firstMin);

	std::cout << "DEBUG: 'sorted' après insertion du premier min " << firstMin << ": ";
	for (size_t i = 0; i < sorted.size(); ++i)
		std::cout << sorted[i] << " ";
	std::cout << std::endl;

	// Générer la séquence Jacobsthal pour ordonner les insertions restantes
	if (minIndices.size() > 1)
	{
		std::vector<size_t> jacobOrder = jacobsthallIndices(minIndices.size() - 1);

		std::cout << "DEBUG: Séquence Jacobsthal pour insertion: ";
		for (size_t i = 0; i < jacobOrder.size(); ++i)
		    std::cout << jacobOrder[i] << " ";
		std::cout << std::endl;

		// Insérer les autres minimums dans l’ordre donné par Jacobsthal
		for (size_t i = 0; i < jacobOrder.size(); ++i)
		{
			size_t idx = jacobOrder[i] + 1; // +1 car minIndices[0] déjà inséré
			if (idx < minIndices.size())
			{
				int value = arr[minIndices[idx]];
				pos = std::lower_bound(sorted.begin(), sorted.end(), value);
				sorted.insert(pos, value);

				std::cout << "DEBUG: Insertion de " << value << " selon Jacobsthal à l'indice " << idx << std::endl;
				std::cout << "DEBUG: 'sorted' après insertion: ";
				for (size_t k = 0; k < sorted.size(); ++k)
				    std::cout << sorted[k] << " ";
				std::cout << std::endl;
			}
		}
	}

	// Copier la séquence triée dans le résultat
	for (size_t i = 0; i < sorted.size(); ++i)
		result.push_back(sorted[i]);

	std::cout << "DEBUG: Résultat final de cet appel récursif: ";
	for (size_t i = 0; i < result.size(); ++i)
		std::cout << result[i] << " ";
	std::cout << std::endl << "---------------------------------------------" << std::endl;
}

std::vector<size_t> PmergeMe::jacobsthallIndicesDebug(size_t n)
{
	std::vector<size_t> indices;
	size_t j1 = 1;
	size_t j2 = 2;

	while (j2 <= n)
	{
		indices.push_back(j2 - 1);
		size_t next = j2 + 2 * j1;
		j1 = j2;
		j2 = next;
	}

	for (size_t i = 0; i < n; i++)
	{
		if (std::find(indices.begin(), indices.end(), i) == indices.end())
			indices.push_back(i);
	}
	std::cout << "DEBUG: Jacobsthal sequence for n=" << n << ": ";
    	for (size_t i = 0; i < indices.size(); i++)
        	std::cout << indices[i] << " ";
    	std::cout << std::endl;
	return indices;
}

void PmergeMe::printDeque(std::deque<int> &deque)
{
	std::cout << "--------------------DEQUE------------------" << std::endl;
	for (size_t i = 0; i < deque.size(); i++)
		std::cout << "[ " << deque[i] << " ] ";
	std::cout << std::endl << "-------------------------------------------" << std::endl;
}

void PmergeMe::printVector(std::vector<int> &vec)
{
    std::cout << "--------------------VECTOR------------------" << std::endl;
    for (size_t i = 0; i < vec.size(); i++)
        std::cout << "[ " << vec[i] << " ] ";
    std::cout << std::endl << "--------------------------------------------" << std::endl;
}


