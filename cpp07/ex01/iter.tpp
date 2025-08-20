/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:21:55 by marvin            #+#    #+#             */
/*   Updated: 2025/05/27 15:21:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cstddef>

template <typename T> void iter(T *array, size_t length, void (*func)(T &)) {
	if (array && func) for (size_t i = 0; i < length; ++i) func(array[i]);
}
template <typename T> void iter(T const* array, size_t length, void (*func)(T const&)) {
    if (array && func) for (size_t i = 0; i < length; ++i) func(array[i]);
}