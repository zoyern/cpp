#include "PmergeMe.hpp"

int main(int argc, char** argv)
{    
	if (argc < 2)
	{
		std::cerr << RED "Error: Give me some arguments please." COLOR_END << std::endl;
		std::cerr << "Usage: ./PmergeMe + positive integers..." << std::endl;
		return (1);
	}

	PmergeMe sorter;
	
	if (!sorter.parseArguments(argc, argv))
	{
		std::cerr << RED "Error: Invalid arguments." COLOR_END << std::endl;
		return (1);
	}
	
	sorter.sortAndCompare();
	
	return (0);
}


