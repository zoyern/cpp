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
#include <stdexcept>
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                :+:      :+:    :+:   */
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
#include <algorithm>

#define MSG_OVERFLOW "MutantStack is full !"
#define MSG_MISS_NUMBERS "Not enough numbers to find a span !"

template <class T>
class MutantStack : public std::stack<T>
{
private:
    unsigned int        _n;
public:
    ~MutantStack();
    MutantStack();
    MutantStack(unsigned int N);
    MutantStack(const MutantStack &cpy);
    MutantStack &operator=(const MutantStack &cpy);

    void	addNumber(int n);
    int		shortestSpan();
    int		longestSpan();

	template<typename Iterator>
    void    addNumbers(Iterator begin, Iterator end);
};
