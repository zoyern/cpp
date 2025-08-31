/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:21:55 by marvin            #+#    #+#             */
/*   Updated: 2025/05/27 15:21:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <algorithm>
#include <stack>
#include <list>

class RPN
{
private:
    std::stack<long, std::list<long>> _numbers;

	~RPN();
    RPN();
    RPN(unsigned int N);
    RPN(const RPN &cpy);
    RPN &operator=(const RPN &cpy);
public:

	static long out(const std::string &str);

	static long add(long a, long b);
	static long sub(long a, long b);
	static long mul(long a, long b);
	static long div(long a, long b);

};
