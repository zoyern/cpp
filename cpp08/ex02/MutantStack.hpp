/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:21:55 by marvin            #+#    #+#             */
/*   Updated: 2025/05/27 15:21:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
    typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;

	~MutantStack();
	MutantStack();
	MutantStack(MutantStack const &cpy);

	MutantStack	&operator=(const MutantStack &cpy);

    iterator		begin();
    iterator		end();
	const_iterator	begin() const;
    const_iterator	end() const;
};

#include "MutantStack.tpp"