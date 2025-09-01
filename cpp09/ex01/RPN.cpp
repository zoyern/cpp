/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:22:06 by marvin            #+#    #+#             */
/*   Updated: 2025/05/27 15:22:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

std::stack<long, std::list<long> > RPN::_stack;

RPN::~RPN() {}
RPN::RPN() {}
RPN::RPN(const RPN &cpy) { *this = cpy;}

RPN    &RPN::operator=(const RPN &cpy) {
	if (this == &cpy) return (*this); 
    return (*this);
}

long    RPN::add(long a, long b) { return (a + b); }
long    RPN::sub(long a, long b) { return (a - b); }
long    RPN::mul(long a, long b) { return (a * b); }
long    RPN::div(long a, long b) { return (b ? a / b : throw (std::runtime_error("Error"))); }

bool    RPN::ops(const std::string &input)
{
    struct {std::string key; long (*op)(long, long);} funcs[] = {
		{"+", RPN::add},
		{"-", RPN::sub},
		{"*", RPN::mul},
		{"/", RPN::div},
		{"", 0}
	};

    if (input.size() == 1 && std::isdigit(input[0]))
        return (_stack.push(input[0] -  '0'), true);
    for (int i = 0; !funcs[i].key.empty(); ++i) {
        if (funcs[i].key == input)
        {
            if (_stack.size() < 2) return (false);
            long b = _stack.top(); _stack.pop();
            long a = _stack.top(); _stack.pop();
            return (_stack.push(funcs[i].op(a, b)), true);
        }
    }
    return (false);
}
long    RPN::out(const std::string &input)
{
    while (!_stack.empty()) _stack.pop();
    std::istringstream iss(input);
    
    for (std::string token; iss >> token;)
        if (!ops(token)) throw (std::runtime_error("Error"));
    if (_stack.size() == 1) return (_stack.top());

    throw (std::runtime_error("Error"));
}
