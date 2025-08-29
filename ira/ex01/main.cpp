#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << RED "Error: invalid number of arguments" COLOR_END << std::endl;
		std::cerr << "Usage: " << argv[0] << " \"calculation\"" << std::endl;
		return (1);
	}

	RPN calculation;
	try
	{
		double result = calculation.parse(argv[1]);
	
		std::cout << GREEN << result << COLOR_END << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << COLOR_END << std::endl;
		return (1);
	}
	

	return (0);
}