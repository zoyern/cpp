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
    ~Array() {delete[] _array;}
	Array() : _array(NULL), _size(0) {}
	Array(const Array<T> &cpy) : _array(NULL), _size(0) {*this = cpy;}
    Array(unsigned int n) : _array(n ? new T[n]() : NULL), _size(n) {}
    
    Array<T>	&operator=(const Array<T> &cpy) {
		if (this == &cpy) return (*this); 
		T	*buf = !cpy._size ? NULL : new T[_size];

		for (unsigned int i = 0; i < cpy._size; ++i) {buf[i] = cpy._array[i];}
		delete[] _array;
		_array = buf;
		_size = cpy._size;
		return (*this);
	}
	T		&operator[](unsigned int index) {if (index >= _size) throw std::out_of_range("Index out of bounds"); return _array[index];}
	const T	&operator[](unsigned int index) const {	if (index >= _size) throw std::out_of_range("Index out of bounds"); return _array[index];}

	unsigned int	size() const {return _size;};
};