/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:22:06 by marvin            #+#    #+#             */
/*   Updated: 2025/05/27 15:22:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::~Span() {}
Span::Span() : _n(0), _numbers(){}
Span::Span(unsigned int N) : _n(N), _numbers(0){}
Span::Span(const Span &cpy) { *this = cpy;}

Span    &Span::operator=(const Span &cpy) { if (this == &cpy) return (*this); 
    _n = cpy._n;
    _numbers = cpy._numbers;
    return (*this);
}

void    Span::addNumber(int n)
{
    if (_numbers.size() >= _n)
        throw (std::overflow_error(MSG_OVERFLOW));
    _numbers.push_back(n);
}

int Span::shortestSpan() {
    if (_numbers.size() < 2)
        throw (std::logic_error(MSG_MISS_NUMBERS));

    std::vector<int> sorted(_numbers);
    std::sort(sorted.begin(), sorted.end());
    std::adjacent_difference(sorted.begin(), sorted.end(), sorted.begin());
    return (*std::min_element(sorted.begin() + 1, sorted.end()));
}

int Span::longestSpan() {
    if (_numbers.size() < 2)
        throw (std::logic_error(MSG_MISS_NUMBERS));
    return (*std::max_element(_numbers.begin(), _numbers.end())
		- *std::min_element(_numbers.begin(), _numbers.end()));
}
