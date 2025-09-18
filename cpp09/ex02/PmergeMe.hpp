/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:21:55 by marvin            #+#    #+#             */
/*   Updated: 2025/05/27 15:21:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <sstream>
#include <vector>
#include <deque>
#include <limits>
#include <algorithm>

#define VAL_MAX std::numeric_limits<int>::max()
#define VAL_MIN 1

/*
	Groupement par paires
	Tri des paires localement
	Tri récursif des gagnants
	Construction de la main_chain
	Génération de la séquence de Jacobsthal
	Insertion des perdants selon Jacobsthal
	Insertion du straggler (si existe)


	fjj([5,3,9,7,4,1]) 
	↓ paires: [(5,3), (9,7), (4,1)]
	↓ gagnants: [5,9,4]
		↓ fjj([5,9,4])
		↓ paires: [(9,5), (4,straggler)]  
		↓ gagnants: [9]
		↓ fjj([9]) → retour immédiat

	[15, 3, 11, 7, 13, 5]
	Paires : [(15,3), (11,7), (13,5)]
*/

class PmergeMe  {
	private:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		static size_t nextJacobsthal(size_t jacob[2], size_t remaining) {
			size_t next = jacob[1] + 2 * jacob[0];
			size_t end = (next <= remaining) ? next : remaining;
			jacob[0] = jacob[1];
			jacob[1] = next;
			return end;
		}

    	template<template<typename, typename> class Container, typename T>
    	static Container<T, std::allocator<T> > parse(int argc, char** argv) {
			Container<T, std::allocator<T> > container;
			for (int i = 0; i < argc; ++i) {
				std::stringstream ss(argv[i]);
				T val;
				if (!(ss >> val) || !ss.eof() || ss.fail() || val < VAL_MIN || val > VAL_MAX ) 
					throw std::runtime_error("Error");
				container.push_back((val));
			}
			return container;
		}

		template<template<typename, typename> class Container, typename T>
    	static void fjjPairs(Container<T, std::allocator<T> > &container, Container<std::pair<T, T>, std::allocator<std::pair<T, T> > > &pairs) {
			pairs.clear();
			for (size_t i = 0; i + 1 < container.size(); i += 2)
				pairs.push_back(container[i] > container[i + 1] ? 
					std::make_pair(container[i], container[i + 1]) : 
					std::make_pair(container[i + 1], container[i]));
		}

		template<template<typename, typename> class Container, typename T>
		static Container<T, std::allocator<T> > fjjSortWinners(Container<std::pair<T, T>, std::allocator<std::pair<T, T> > > &pairs) {
			Container<T, std::allocator<T> > winners;
			if (pairs.size() <= 1) {
				if (!pairs.empty()) winners.push_back(pairs[0].first);
				return winners;
			}
			for (size_t i = 0; i < pairs.size(); ++i) winners.push_back(pairs[i].first);
			return (fjj(winners));
		}

		template<template<typename, typename> class Container, typename T>
		static void fjjMainChain(Container<T, std::allocator<T> > &container, Container<T, std::allocator<T> > winners, const Container<std::pair<T, T>, std::allocator<std::pair<T, T> > > &pairs) {
			container.clear();
			if (pairs.empty()) return;
			container.push_back(pairs[0].second);
			for (size_t i = 0; i < pairs.size(); ++i) container.push_back(winners[i]);
		}


		template<template<typename, typename> class Container, typename T>
		static void fjjSortLosers(Container<T, std::allocator<T> > &container, const Container<std::pair<T, T>, std::allocator<std::pair<T, T> > > &pairs) {
			if (pairs.size() <= 1) return;
			
			size_t jacob[2] = {0, 1};
			size_t remaining = pairs.size() - 1;
			
			while (remaining > 0) {
				size_t next = jacob[1] + 2 * jacob[0];
				size_t end = std::min(next, pairs.size() - 1);  // Borner à la taille réelle
				
				for (size_t i = end; i > jacob[0] && i < pairs.size(); --i) {
					container.insert(
						std::lower_bound(container.begin(), container.end(), pairs[i].second), 
						pairs[i].second
					);
				}
				
				remaining -= std::min(end - jacob[0], remaining);
				jacob[0] = jacob[1];
				jacob[1] = next;
			}
		}

		template<template<typename, typename> class Container, typename T>
		static Container<T, std::allocator<T> > fjj(Container<T, std::allocator<T> > container)
		{
			Container<std::pair<T, T>, std::allocator<std::pair<T, T> > > pairs;
			bool straggler = (container.size() % 2 == 1);
			T stragglerValue = straggler ? container.back() : T();

			fjjPairs(container, pairs);
			fjjMainChain(container, fjjSortWinners(pairs), pairs);
			fjjSortLosers(container, pairs);
			if (straggler)
				container.insert(std::lower_bound(container.begin(), container.end(), stragglerValue), stragglerValue);
			return (container);
		}
public:
		template<typename T>
    	static std::vector<T> sortVector(int argc, char** argv) {
			return fjj(parse<std::vector, T >(argc, argv));
		}
		template<typename T>
    	static std::deque<T>  sortDeque(int argc, char** argv) {
			return fjj(parse<std::deque, T >(argc, argv));
		}
};
