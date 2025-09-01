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
#include "Array.hpp"

template <typename T>
Array<T>::~Array() {delete[] _array;}
template <typename T>
Array<T>::Array() : _array(0), _size(0) {}
template <typename T>
Array<T>::Array(const Array<T> &cpy) : _array(0), _size(0) {*this = cpy;}
template <typename T>
Array<T>::Array(unsigned int n) : _array(n ? new T[n]() : NULL), _size(n) {}

template <typename T>
Array<T>	&Array<T>::operator=(const Array<T> &cpy) {
	if (this == &cpy) return (*this); 
	T	*buf = !cpy._size ? 0 : new T[cpy._size];

	for (unsigned int i = 0; i < cpy._size; ++i) {buf[i] = cpy._array[i];}
	delete[] _array;
	_array = buf;
	_size = cpy._size;
	return (*this);
}
template <typename T>
T		&Array<T>::operator[](unsigned int index) {if (index >= _size) throw std::out_of_range("Index out of bounds"); return _array[index];}

template <typename T>
const T	&Array<T>::operator[](unsigned int index) const {	if (index >= _size) throw std::out_of_range("Index out of bounds"); return _array[index];}

template <typename T>
unsigned int	Array<T>::size() const {return _size;};
