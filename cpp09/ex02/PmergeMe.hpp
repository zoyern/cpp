/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                :+:      :+:    :+:   */
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
#include <algorithm>

class PmergeMe
{
private:
	PmergeMe();
	PmergeMe(const PmergeMe &);
	PmergeMe &operator=(const PmergeMe &);
	~PmergeMe();

	static size_t nextJacobsthal(size_t seq[2], size_t limit);

	template <template <typename, typename> class Contener, typename T>
	static Contener<T, std::allocator<T> > parse(int argc, char **argv);

	template <template <typename, typename> class Contener, typename T>
	static void fjjpairs(Contener<T, std::allocator<T> > &cont, Contener<std::pair<T, T>, std::allocator<std::pair<T, T> > > &pairs);

	template <template <typename, typename> class Contener, typename T>
	static Contener<T, std::allocator<T> > fjjwinners(Contener<std::pair<T, T>, std::allocator<std::pair<T, T> > > &pairs);

	template <template <typename, typename> class Contener, typename T>
	static void fjjlosers(Contener<T, std::allocator<T> > &cont, const Contener<std::pair<T, T>, std::allocator<std::pair<T, T> > > &pairs);

	template <template <typename, typename> class Contener, typename T>
	static Contener<T, std::allocator<T> > fjj(Contener<T, std::allocator<T> > cont);

public:
	template <typename T>
	static std::vector<T> sortVector(int argc, char **argv);
	template <typename T>
	static std::deque<T> sortDeque(int argc, char **argv);
};

#include "PmergeMe.tpp"
