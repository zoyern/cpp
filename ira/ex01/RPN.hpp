#ifndef RPN_HPP
#define RPN_HPP

#define BLACK "\033[1;30m"
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN "\033[1;36m"
#define WHITE "\033[1;37m"
#define ORANGE "\033[1;38;5;208m"
#define PINK "\033[1;38;5;213m"
#define PURPLE "\033[1;38;5;129m"
#define BROWN "\033[1;38;5;94m"
#define GREY "\033[1;38;5;245m"
#define COLOR_END "\033[0m"

#include <iostream>
#include <string>
#include <stack>
#include <list>
#include <cctype>
#include <stdexcept>

class RPN
{
	public:
		RPN();
		RPN(const RPN &src);
		RPN& operator=(const RPN &src);
		~RPN();

		double parse(const std::string &expression);

	private:
	// pour eviter deque hihi
		std::stack<double, std::list<double> > _numbers;

		bool isOperator(const std::string &token) const;
		bool isValidNumber(const std::string &token) const;
		double calculate(double a, double b, char op) const;
		double stringToDouble(const std::string &str) const;
		std::string removeWhiteSpaces(const std::string &str) const;
		std::string getNextToken(const std::string &expression, size_t &pos) const;
};

#endif