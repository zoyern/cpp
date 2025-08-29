#include "BitcoinExchange.hpp"

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << RED "Error: could not open file." COLOR_END  << std::endl;
		std::cerr << "Please use ./btc and input.txt" << std::endl;
		return (1);
	}

	BitcoinExchange btcExchange;

	if (!btcExchange.loadDatabase("data.csv"))
	{
		std::cerr << RED "Error: could not load database." COLOR_END << std::endl;
		return (1);
	}

	btcExchange.processInputFile(argv[1]);

	return (0);
}