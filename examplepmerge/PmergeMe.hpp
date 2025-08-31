#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <sstream>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <cctype>
#include <cmath>
#include <iterator>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define ORANGE "\033[38;5;208m"
#define PINK "\033[38;5;205m"
#define PURPLE "\033[38;5;129m"
#define COLOR_END "\033[0m"

class PmergeMe
{
public:
	PmergeMe();
	PmergeMe(const PmergeMe &src);
	PmergeMe& operator=(const PmergeMe &src);
	~PmergeMe();

	bool parseArguments(int argc, char** argv);
	void sortAndCompare();

private:
	std::vector<int> _vectorData;
	std::deque<int> _dequeData;
   
	int _vectorComparisons;
	int _dequeComparisons;

	bool hasDuplicates() const;
	bool isValidNumber(const std::string &str) const;
	void displayVector(const std::vector<int> &seq) const;
	void displayDeque(const std::deque<int> &seq) const;

	void fordJohnsonVectorStep1(std::vector<int> &vectorData, size_t element_size);
	void fordJohnsonVectorStep2(std::vector<int> &vectorData, size_t element_size);
	void fordJohnsonVectorStep3(std::vector<int> &main_chain, size_t element_size, std::vector<std::pair<std::vector<int>, int> > &pending);
	void binarysearchVector(size_t idx_to_reinsert, std::vector<int> &main_chain, size_t element_size, std::vector<std::pair<std::vector<int>, int> > &pending);

	void fordJohnsonDequeStep1(std::deque<int> &dequeData, size_t element_size);
	void fordJohnsonDequeStep2(std::deque<int> &dequeData, size_t element_size);
	void fordJohnsonDequeStep3(std::deque<int> &main_chain, size_t element_size, std::deque<std::pair<std::deque<int>, int> > &pending);
	void binarysearchDeque(size_t idx_to_reinsert, std::deque<int> &main_chain, size_t element_size, std::deque<std::pair<std::deque<int>, int> > &pending);

};    

#endif