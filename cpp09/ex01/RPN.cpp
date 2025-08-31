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

RPN::~RPN() {}
RPN::RPN() : _n(0), _numbers(0){}
RPN::RPN(unsigned int N) : _n(N), _numbers(0){}
RPN::RPN(const RPN &cpy) { *this = cpy;}

RPN    &RPN::operator=(const RPN &cpy) {
	if (this == &cpy) return (*this); 
    return (*this);
}

long RPN::add(long a, long b) { return a + b; }
long RPN::sub(long a, long b) { return a - b; }
long RPN::mul(long a, long b) { return a * b; }
long RPN::div(long a, long b) { return b ? a / b : throw (std::runtime_error("Error")); }


//long RPN::out(const std::string &expression) {
    //static const char ops[] = "+-*/";
    /*static operation_func funcs[] = {add, sub, mul, div};
    
    stack_type stack;
    std::istringstream iss(expression);
    std::string token;
    
    while (iss >> token) {
        const char* found = std::strchr(ops, token[0]);
        if (found && token.size() == 1) {
            if (stack.size() < 2) throw RPNException();
            long b = stack.top(); stack.pop();
            long a = stack.top(); stack.pop();
            stack.push(funcs[found - ops](a, b));
        } else {
            std::istringstream ns(token);
            long num;
            if (!(ns >> num) || !ns.eof() || num < 0 || num >= 10)
                throw RPNException();
            stack.push(num);
        }
    }
    if (stack.size() != 1) throw RPNException();
    return stack.top();
}*/

//    static long evaluate(const std::string &expr) {
      //  static const char ops[] = "+-*/";
    //   static op_func funcs[] = {add, sub, mul, div};
       /*
        std::stack<long, std::list<long> > stack;
        std::istringstream iss(expr);
        std::string token;
        
        while (iss >> token) {
            if (token.size() == 1) {
                if (const char *pos = std::strchr(ops, token[0])) {
                    if (stack.size() < 2) throw std::runtime_error("Error");
                    long b = stack.top(); stack.pop();
                    long a = stack.top(); stack.pop();
                    stack.push(funcs[pos - ops](a, b));
                } else if (std::isdigit(token[0])) {
                    stack.push(token[0] - '0');
                } else throw std::runtime_error("Error");
            } else throw std::runtime_error("Error");
        }
        
        return stack.size() == 1 ? stack.top() : throw std::runtime_error("Error"), 0;
    }*/