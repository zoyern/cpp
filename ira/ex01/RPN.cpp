#include "RPN.hpp"
#include <cstdlib>

RPN::RPN()
{
}

RPN::RPN(const RPN &src)
{
	_numbers = src._numbers;
}

RPN& RPN::operator=(const RPN &src)
{
	if (this != &src)
		_numbers = src._numbers;
	return (*this);
}

RPN::~RPN()
{
}

std::string RPN::removeWhiteSpaces(const std::string &str) const
{
	size_t start = str.find_first_not_of(" \t\r\n");
	if (start == std::string::npos)
		return ("");
	size_t end = str.find_last_not_of(" \t\r\n");
	return str.substr(start, end - start + 1);
}

double RPN::stringToDouble(const std::string &str) const
{
	if (str.empty())
		return (-1);
	
	char *endptr;
	double value = std::strtod(str.c_str(), &endptr);
	
	// Vérifier si toute la chaîne a été convertie
	if (*endptr != '\0')
		return (-1);
	
	return (value);
}

bool RPN::isOperator(const std::string &token) const
{
	return (token == "+" || token == "-" || token == "*" || token == "/");
}

bool RPN::isValidNumber(const std::string &token) const
{
	if (token.length() != 1)
		return (false);
	return (std::isdigit(token[0]));
}

double RPN::calculate(double a, double b, char op) const
{
	switch (op)
	{
		case '+':
			return (a + b);
		case '-':
			return (a - b);
		case '*':
			return (a * b);
		case '/':
			if (b == 0)
			{
				throw(std::runtime_error("Error: division by zero"));

			}
			return (a / b);
		default:
			throw(std::runtime_error("Error: invalid operator"));
	}
}

std::string RPN::getNextToken(const std::string &expression, size_t &pos) const
{
	// ignorer les espaces mais maybe useless car je trim deja
	while (pos < expression.length() && (expression[pos] == ' ' || expression[pos] == '\t'))
		pos++;
	
	if (pos >= expression.length())
		return ("");
	
	// pr trouver la fin du token
	size_t start = pos;
	while (pos < expression.length() && expression[pos] != ' ' && expression[pos] != '\t')
		pos++;
	
	return (expression.substr(start, pos - start));
}

double RPN::parse(const std::string &expression)
{
	while (!_numbers.empty())
		_numbers.pop();

	std::string expr = removeWhiteSpaces(expression);
	size_t pos = 0;
	std::string token;
	
	while ((token = getNextToken(expr, pos)) != "")
	{
		
		if (isValidNumber(token))
		{
            //convrt
			_numbers.push(token[0] - '0');
		}
		else if (isOperator(token))
		{
			//deux dans la pile
			if (_numbers.size() < 2)
			{
				throw(std::runtime_error("Error"));
			
			}

			double b = _numbers.top();
			_numbers.pop();
			double a = _numbers.top();
			_numbers.pop();

			double result = calculate(a, b, token[0]);
			
			_numbers.push(result);
		}
		else
		{
			throw(std::runtime_error("Error"));
		}
	}

	if (_numbers.size() != 1)
	{
		throw(std::runtime_error("Error"));
	}

	return (_numbers.top());
}