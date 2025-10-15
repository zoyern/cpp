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
#include <algorithm>

class PmergeMe
{
private:
	PmergeMe();
	PmergeMe(const PmergeMe &);
	PmergeMe &operator=(const PmergeMe &);
	~PmergeMe();

	static size_t nextJacobsthal(size_t seq[2], size_t limit) {
		size_t next = seq[1] + 2 * seq[0];
		return (seq[0] = seq[1], seq[1] = next, next <= limit ? next : limit);
	}

	template <template <typename, typename> class Contener, typename T>
	static Contener<T, std::allocator<T> > parse(int argc, char **argv) {
		Contener<T, std::allocator<T> > cont;
		for (int i = 0; i < argc; ++i)
		{
			std::stringstream ss(argv[i]); T val;
			if (!(ss >> val) || !ss.eof() || val < 1)
				throw(std::runtime_error("Error"));
			cont.push_back(val);
		}
		return (cont);
	}

	template <template <typename, typename> class Contener, typename T>
	static void fjjpairs(Contener<T, std::allocator<T> > &cont, Contener<std::pair<T, T>, std::allocator<std::pair<T, T> > > &pairs) {
		for (size_t i = 0; i + 1 < cont.size(); i += 2)
			pairs.push_back(cont[i] > cont[i + 1] ? std::make_pair(cont[i], cont[i + 1]) : std::make_pair(cont[i + 1], cont[i]));
	}

	template <template <typename, typename> class Contener, typename T>
	static Contener<T, std::allocator<T> > fjjwinners(Contener<std::pair<T, T>, std::allocator<std::pair<T, T> > > &pairs) {
		Contener<T, std::allocator<T> > winners;
		if (pairs.size() <= 1)
		{
			if (!pairs.empty()) winners.push_back(pairs[0].first);
			return (winners);
		}
		for (size_t i = 0; i < pairs.size(); ++i) winners.push_back(pairs[i].first);
		return (fjj(winners));
	}

	template <template <typename, typename> class Contener, typename T>
	static void fjjlosers(Contener<T, std::allocator<T> > &cont, const Contener<std::pair<T, T>, std::allocator<std::pair<T, T> > > &pairs) {
		if (pairs.empty()) return;
		size_t jac[2] = {0, 1}, curr = 0;
		while (curr < pairs.size())
		{
			size_t end = nextJacobsthal(jac, pairs.size());
			for (size_t i = end; i > curr; --i)
				cont.insert(std::lower_bound(cont.begin(), cont.end(), pairs[i - 1].second), pairs[i - 1].second);
			curr = end;
		}
	}

	template <template <typename, typename> class Contener, typename T>
	static Contener<T, std::allocator<T> > fjj(Contener<T, std::allocator<T> > cont) {
		Contener<std::pair<T, T>, std::allocator<std::pair<T, T> > > pairs;
		bool odd = cont.size() % 2;
		T rem = odd ? cont.back() : T();
		fjjpairs(cont, pairs);
		cont = fjjwinners(pairs);
		fjjlosers(cont, pairs);
		if (odd) cont.insert(std::lower_bound(cont.begin(), cont.end(), rem), rem);
		return (cont);
	}

public:
	template <typename T>
	static std::vector<T> sortVector(int argc, char **argv) { return (fjj(parse<std::vector, T>(argc, argv))); }
	template <typename T>
	static std::deque<T> sortDeque(int argc, char **argv) { return (fjj(parse<std::deque, T>(argc, argv))); }
};
