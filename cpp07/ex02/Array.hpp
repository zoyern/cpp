/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
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

template <typename T>
class Array {
private:
	T				*_array;
	unsigned int	_size;
public:
    ~Array();
	Array();
	Array(const Array<T> &cpy);
    Array(unsigned int n);
    
    Array<T>	&operator=(const Array<T> &cpy);
	T			&operator[](unsigned int index);
	const T		&operator[](unsigned int index) const;

	unsigned int	size() const;
};

#include "Array.tpp"