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
#include <vector>
#include <algorithm>

#define MSG_OVERFLOW "Span is full !"
#define MSG_MISS_NUMBERS "Not enough numbers to find a span !"

class Span
{
private:
    unsigned int        _n;
    std::vector<int>    _numbers;
public:
    ~Span();
    Span();
    Span(unsigned int N);
    Span(const Span &cpy);
    Span &operator=(const Span &cpy);

    void	addNumber(int n);
    int		shortestSpan();
    int		longestSpan();

	template<typename Iterator>
    void    addNumbers(Iterator begin, Iterator end);
};

#include "Span.tpp"