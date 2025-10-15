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
#include <sstream>

class RPN
{
private:
    static std::stack<long, std::list<long> > _stack;

	static bool	ops(const std::string &input);
	static long add(long a, long b);
	static long sub(long a, long b);
	static long mul(long a, long b);
	static long div(long a, long b);

	~RPN();
    RPN();
    RPN(const RPN &);
    RPN &operator=(const RPN &);
public:
	static long out(const std::string &input);
};
