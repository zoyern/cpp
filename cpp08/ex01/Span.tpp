/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:21:55 by marvin            #+#    #+#             */
/*   Updated: 2025/08/29 03:51:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Span.hpp"

template<typename Iterator>
void    Span::addNumbers(Iterator begin, Iterator end)
{
    if (_numbers.size() + static_cast<size_t>(std::distance(begin, end)) > _n)
        throw (std::overflow_error(MSG_OVERFLOW));
    _numbers.insert(_numbers.end(), begin, end);
}