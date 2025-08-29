#include "BitcoinExchange.hpp"

const std::string BitcoinExchange::BITCOIN_CREATION = "2009-01-02";

BitcoinExchange::BitcoinExchange()
{
}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
	 _bitcoinExchanges = src._bitcoinExchanges;
}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &src)
{
	if (this != &src)
		_bitcoinExchanges = src._bitcoinExchanges;
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

std::string BitcoinExchange::removeWhiteSpaces(const std::string &str) const
{
	size_t start = str.find_first_not_of(" \t\r\n");
	if (start == std::string::npos)
		return ("");
	size_t end = str.find_last_not_of(" \t\r\n");
	return str.substr(start, end - start + 1);
}

double BitcoinExchange::stringToDouble(const std::string &str) const
{
	std::istringstream iss(str);
	double value;
	iss >> value;
	if (iss.fail() || !iss.eof())
		return (-1);
	return (value);
}

bool BitcoinExchange::isLeapYear(int year) const
{
	return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

bool BitcoinExchange::isValidDate(const std::string &date) const
{
	if (date.length() != 10)
		return (false);
	if (date[4] != '-' || date[7] != '-')
		return (false);

	for (int i = 0; i < 10; i++)
	{
		if (i == 4 || i == 7)
			continue;
		if (!isdigit(date[i]))
			return (false);
	}
	int year = stringToDouble(date.substr(0, 4));
	int month = stringToDouble(date.substr(5, 2));
	int day = stringToDouble(date.substr(8, 2));

	if (year < 1000 || year > 9999)
		return (false);
	if (month < 1 || month > 12)
		return (false);
	if (day < 1 || day > 31)
		return (false);

	// verif fevrier et leap year
	if (month == 2)
	{
		if (isLeapYear(year) && day > 29)
			return (false);
		if (!isLeapYear(year) && day > 28)
			return (false);
	}
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return (false);
	return (true);
}

bool BitcoinExchange::isDateBeforeCreation(const std::string &date) const
{
	return (date < BITCOIN_CREATION);
}

bool BitcoinExchange::isValidValue(double value) const
{
	return (value >= 0 && value <= 1000);
}

void BitcoinExchange::parseDataLine(const std::string &line)
{
	size_t commaFlag = line.find(',');
	if (commaFlag == std::string::npos)
		return;

	std::string date = removeWhiteSpaces(line.substr(0, commaFlag));
	std::string rate_str = removeWhiteSpaces(line.substr(commaFlag + 1));

	if (isValidDate(date))
	{
		double rate = stringToDouble(rate_str);
		if (rate >= 0)
			_bitcoinExchanges[date] = rate;
	}
}

bool BitcoinExchange::loadDatabase(const std::string &filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		std::cerr << RED "Error: could not open database file." COLOR_END << std::endl;
		return (false);
	}

	std::string line;
	bool firstLine = true;

	while (std::getline(file, line))
	{
		if (firstLine)
		{
			firstLine = false;
			continue;
		}
		parseDataLine(line);
	}

	file.close();
	return (!_bitcoinExchanges.empty());
}

double BitcoinExchange::findClosestRate(const std::string &date) const
{
	std::map<std::string, double>::const_iterator it = _bitcoinExchanges.lower_bound(date);

	if (it != _bitcoinExchanges.end() && it->first == date)
		return (it->second);

	// pour la premiere occur de la map
	if (it == _bitcoinExchanges.begin())
		return (-1);

	// Prendre la date précédente
	--it;
	return (it->second);
}

void BitcoinExchange::processInputFile(const std::string &filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		std::cerr << RED "Error: could not open file." COLOR_END << std::endl;
		return;
	}

	std::string line;
	bool firstLine = true;

	while (std::getline(file, line))
	{
		if (firstLine)
		{
			firstLine = false;
			continue;
		}
		if (isWhiteSpace(line) == true)
			continue;
		else
		{
			size_t pipePos = line.find(" | ");
			if (pipePos == std::string::npos)
			{
				std::cerr << RED "Error: bad input => " COLOR_END << line << std::endl;
				continue;
			}
			std::string date = removeWhiteSpaces(line.substr(0, pipePos));
			std::string valueStr = removeWhiteSpaces(line.substr(pipePos + 3));
			if (!isValidDate(date))
			{
				std::cerr << RED "Error: bad input => " COLOR_END << date << std::endl;
				continue;
			}
			if (isDateBeforeCreation(date))
			{
				std::cerr << RED "Error: Bitcoin didn't exist before " << BITCOIN_CREATION << COLOR_END " => " << date << std::endl;
				continue;
			}
			double value = stringToDouble(valueStr);
			if (value < 0)
			{
				std::cerr << RED "Error: not a positive number." COLOR_END << std::endl;
				continue;
			}

			if (value > 1000)
			{
				std::cerr << RED "Error: too large a number." COLOR_END << std::endl;
				continue;
			}
			double rate = findClosestRate(date);
			if (rate < 0)
			{
				std::cerr << RED "Error: no exchange rate available for date => " COLOR_END << date << std::endl;
				continue;
			}

			std::cout << date << " => " << value << " = " << GREEN << (value * rate) << COLOR_END << std::endl;
			}
	}

	file.close();
}

bool BitcoinExchange::isWhiteSpace(const std::string &line)
{
	size_t i = 0;
	while (line[i] != '\0')
	{
		if (!isspace(line[0]))
			return (false);
		i++;
	}
	return (true);
}