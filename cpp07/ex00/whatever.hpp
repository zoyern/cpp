/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:36:29 by marvin            #+#    #+#             */
/*   Updated: 2024/11/22 16:36:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template<typename T> void swap(T &a, T &b) { T tmp = a; a = b; b = tmp; }
template<typename T> T const& min(T const& a, T const& b) { return (a < b ? a : b); }
template<typename T> T const& max(T const& a, T const& b) { return (a > b ? a : b); }
