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
	~MutantStack() {}
	MutantStack() : std::stack<T>() {}
	MutantStack(MutantStack const &cpy) : std::stack<T>(cpy) {}

	MutantStack &operator=(const MutantStack &cpy) { return (std::stack<T>::operator=(cpy), *this); }
	
    typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;

    iterator		begin(){ return (this->c.begin()); }
    iterator		end(){ return (this->c.end()); }
	const_iterator	begin() const { return this->c.begin(); }
    const_iterator	end()   const { return this->c.end(); }
};
