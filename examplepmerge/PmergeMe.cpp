#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &src)
{
	(void) src;
}

PmergeMe& PmergeMe::operator=(const PmergeMe &src)
{
	(void) src;
	return (*this);
}

PmergeMe::~PmergeMe()
{
}
bool PmergeMe::hasDuplicates() const
{
	for (size_t i = 0; i < _vectorData.size(); i++)
	{
		for (size_t j = i + 1; j < _vectorData.size(); j++)
		{
			if (_vectorData[i] == _vectorData[j])
				return (true);
		}
	}
	return (false);
}

bool PmergeMe::isValidNumber(const std::string &str) const
{
	if (str.empty())
		return (false);
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!std::isdigit(str[i]))
			return (false);
	}
	std::istringstream iss(str);
	long num;
	iss >> num;

	return (!iss.fail() && iss.eof() && num >= 0 && num <= 2147483647);
}

bool PmergeMe::parseArguments(int argc, char** argv)
{
	std::cout << BLUE "~~~~~~~Let's check your arguments~~~~~~~" COLOR_END << std::endl;

	for (int i = 1; i < argc; i++)
	{
		std::string arg(argv[i]);

		if (!isValidNumber(arg))
		{
			std::cerr << RED "Error: '" << arg << "' is not a valid positive number." COLOR_END << std::endl;
			return (false);
		}

		int num = std::atoi(arg.c_str());
		_vectorData.push_back(num);
		_dequeData.push_back(num);
	}
	if (hasDuplicates())
	{
		std::cerr << RED "Error: Found duplicates, try new numbers please." COLOR_END << std::endl;
		return (false);
	}

	std::cout << GREEN "Arguments validated, let's Ford-Johnson them!" COLOR_END << std::endl << std::endl;
	return (true);
}
////////////// FIN DU PARSING

void PmergeMe::sortAndCompare()
{
	// std::cout << YELLOW "~~~~~~~Sequence before sorting~~~~~~~" COLOR_END << std::endl;
	// std::cout << YELLOW "Before: " COLOR_END ;
	// displayVector(_vectorData);
	// std::cout << std::endl;

	// //VECTOR
	// std::cout << CYAN "~~~~~~~Ford-Johnson with vector~~~~~~~" COLOR_END << std::endl;
	// _vectorComparisons = 0;
	// clock_t vectorStart = std::clock();
	
	// std::cout << ORANGE "Recursion vector with " << _vectorData.size() << " elements." COLOR_END << std::endl << std::endl;
	
	// if (_vectorData.size() <= 1)
	// {
	// 	std::cout << YELLOW "After : " COLOR_END;
	// 	displayVector(_vectorData);
	// 	return ;
	// }

	// if (_vectorData.size() == 2)
	// {
	// 	std::cout << ORANGE "~~~~~~~Sorting pair: [" << _vectorData[0] << ", " << _vectorData[1] << "]~~~~~~~" COLOR_END << std::endl;
		
	// 	++_vectorComparisons;
	// 	if (_vectorData[0] > _vectorData[1])
	// 		std::swap(_vectorData[0], _vectorData[1]);
	// }
	// fordJohnsonVectorStep1(_vectorData, 1);

	// std::cout << CYAN "~~~~~~~Sequence after complete Ford-Johnson~~~~~~~" COLOR_END << std::endl;
	// std::cout << YELLOW "After:  " COLOR_END;
	// displayVector(_vectorData);
	// std::cout << MAGENTA "\n~~~~~~~VECTOR used " << _vectorComparisons << " comparisons~~~~~~~" COLOR_END << std::endl;
	// clock_t vectorEnd = std::clock();
	// clock_t vectorTime = (vectorEnd - vectorStart) / (CLOCKS_PER_SEC / 1000000);
	// std::cout << MAGENTA "Time to process a range of 5 elements with std::vector : " << vectorTime << " us" COLOR_END << std::endl << std::endl;

	//DEQUE
	std::cout << YELLOW "~~~~~~~Sequence before sorting with DEQUE~~~~~~~" COLOR_END << std::endl;
	std::cout << YELLOW "Before: " COLOR_END ;
	displayDeque(_dequeData);
	std::cout << std::endl;
	std::cout << CYAN "\n~~~~~~~Ford-Johnson with deque~~~~~~~" COLOR_END << std::endl;
	_dequeComparisons = 0;
	clock_t dequeStart = std::clock();
	
	std::cout << ORANGE "Recursion deque with " << _dequeData.size() << " elements." COLOR_END << std::endl << std::endl;
	
	if (_dequeData.size() == 2)
	{
		std::cout << ORANGE "~~~~~~~Sorting pair: [" << _dequeData[0] << ", " << _dequeData[1] << "]~~~~~~~" COLOR_END << std::endl;
		
		++_dequeComparisons;
		if (_dequeData[0] > _dequeData[1])
			std::swap(_dequeData[0], _dequeData[1]);
	}
	else
		fordJohnsonDequeStep1(_dequeData, 1);
	
	std::cout << CYAN "~~~~~~~Sequence after complete Ford-Johnson~~~~~~~" COLOR_END << std::endl;
	std::cout << YELLOW "After:  " COLOR_END;
	displayDeque(_dequeData);
	std::cout << MAGENTA "\n~~~~~~~DEQUE used " << _dequeComparisons << " comparisons~~~~~~~" COLOR_END << std::endl;
	clock_t dequeEnd = std::clock();
	clock_t dequeTime = (dequeEnd - dequeStart) / (CLOCKS_PER_SEC / 1000000);
	std::cout << MAGENTA "Time to process a range of 5 elements with std::deque : " << dequeTime << " us" COLOR_END << std::endl << std::endl;


	//
	std::cout << YELLOW "~~~~~~~Sequence before sorting with VECTOR~~~~~~~" COLOR_END << std::endl;
	std::cout << YELLOW "Before: " COLOR_END ;
	displayVector(_vectorData);
	std::cout << std::endl;

	//VECTOR
	std::cout << CYAN "~~~~~~~Ford-Johnson with vector~~~~~~~" COLOR_END << std::endl;
	_vectorComparisons = 0;
	clock_t vectorStart = std::clock();
	
	std::cout << ORANGE "Recursion vector with " << _vectorData.size() << " elements." COLOR_END << std::endl << std::endl;
	
	if (_vectorData.size() == 2)
	{
		std::cout << ORANGE "~~~~~~~Sorting pair: [" << _vectorData[0] << ", " << _vectorData[1] << "]~~~~~~~" COLOR_END << std::endl;
		
		++_vectorComparisons;
		if (_vectorData[0] > _vectorData[1])
			std::swap(_vectorData[0], _vectorData[1]);
	}
	else 
		fordJohnsonVectorStep1(_vectorData, 1);

	std::cout << CYAN "~~~~~~~Sequence after complete Ford-Johnson~~~~~~~" COLOR_END << std::endl;
	std::cout << YELLOW "After:  " COLOR_END;
	displayVector(_vectorData);
	std::cout << MAGENTA "\n~~~~~~~VECTOR used " << _vectorComparisons << " comparisons~~~~~~~" COLOR_END << std::endl;
	clock_t vectorEnd = std::clock();
	clock_t vectorTime = (vectorEnd - vectorStart) / (CLOCKS_PER_SEC / 1000000);
	std::cout << MAGENTA "Time to process a range of 5 elements with std::vector : " << vectorTime << " us" COLOR_END << std::endl;

}

void PmergeMe::fordJohnsonVectorStep1(std::vector<int> &vectorData, size_t element_size)
{
	if (element_size == 1)
	{
		// std::cout << PINK "STEP 1: Division into pairs & sorting" COLOR_END << std::endl;

		//demo pour les gens qui n'ont pas fait le FJ
		// std::vector<int> pairedArray;

		// std::cout << ORANGE "Pairs created: " COLOR_END;
		// for (size_t i = 0; i < vectorData.size(); i += 2)
		// {
		// 	if (i + 1 < vectorData.size())
		// 	{
		// 		int a = vectorData[i];
		// 		int b = vectorData[i + 1];
		// 		if (a > b)
		// 		{
		// 			std::swap(vectorData[i], vectorData[i + 1]);
		// 			pairedArray.push_back(b);
		// 			pairedArray.push_back(a);
		// 			std::cout << "(" << b << "," << a << ")";
		// 		}
		// 		else
		// 		{
		// 			pairedArray.push_back(a);
		// 			pairedArray.push_back(b);
		// 			std::cout << "(" << a << "," << b << ")";
		// 		}
		// 		if (i < vectorData.size() - 2)
		// 			std::cout << ", ";
		// 	}
		// }
		// std::cout << std::endl;


		// std::cout << ORANGE "Array after pairing: " COLOR_END ;
		// displayVector(pairedArray);
		// std::cout << std::endl << std::endl;

		// std::cout << GREEN "Cannot form pairs with element_size = 2 (need 4 elements, have " << pairedArray.size() << ")" COLOR_END << std::endl;
		//fin de la demo

	}


	// std::cout << PINK "Recursive sorting with element_size = " << element_size << COLOR_END << std::endl;
	

	// voyons, a supp
	// for (size_t i = 0; i + (element_size * 2) <= vectorData.size(); i += (element_size * 2))
	// {
	// 	// left L
	// 	for (size_t k = i; k < i + element_size; k++)
	// 	{
	// 		std::cout << vectorData[k];
	// 		if (k < i + element_size - 1)
	// 			std::cout << " ";
	// 	}
	// 	std::cout << " | ";

	// 	// R
	// 	for (size_t k = i + element_size; k < i + (element_size * 2); k++)
	// 	{
	// 		std::cout << vectorData[k];
	// 		if (k < i + (element_size * 2) - 1)
	// 			std::cout << " ";
	// 	}

	// 	if (i + (element_size * 2) * 2 <= vectorData.size())
	// 		std::cout << " || ";
	// }

	// // le reste
	// if (vectorData.size() % (element_size * 2) != 0)
	// {
	// 	size_t remaining_start = (vectorData.size() / (element_size * 2)) * (element_size * 2);
	// 	std::cout << " || ";
	// 	for (size_t k = remaining_start; k < vectorData.size(); k++)
	// 	{
	// 		std::cout << vectorData[k];
	// 		if (k < vectorData.size() - 1)
	// 			std::cout << " ";
	// 	}

	// 	std::vector<int> remainingGroup;
	// 	for (size_t k = remaining_start; k < vectorData.size(); k++)
	// 	{
	// 		remainingGroup.push_back(vectorData[k]);
	// 	}
	// }
	// std::cout << std::endl;

	// plus de copie - on modifie directement arr

	//comp swap
	for (size_t i = 0; i + (element_size * 2) <= vectorData.size(); i += (element_size * 2))
	{
		int a = vectorData[i + element_size - 1];
		int b = vectorData[i + (element_size * 2) - 1];

		std::vector<int> leftGroup, rightGroup;
		for (size_t j = 0; j < element_size; j++)
		{
			leftGroup.push_back(vectorData[i + j]);
			rightGroup.push_back(vectorData[i + element_size + j]);
		}
		if (a > b)
		{
			// std::cout << a << " > " << b << " swap groups" << std::endl;
			for (size_t j = 0; j < element_size; j++)
				std::swap(vectorData[i + j], vectorData[i + element_size + j]);
		}
		else
		{
			// std::cout << a << " <= " << b << " keep order" << std::endl;

		}
		++_vectorComparisons;
	}
	// std::cout << ORANGE "Array after swaps: " COLOR_END;
	// displayVector(vectorData);
	// std::cout << std::endl << std::endl;

// fin de demo 
	// Récurs
	if ((element_size * 2) * 2 <= vectorData.size())
		fordJohnsonVectorStep1(vectorData, element_size * 2);
	// else
	// {
	// 	std::cout << GREEN "Cannot form pairs with element_size = " << (element_size * 2) << " (need " << ((element_size * 2) * 2) << " elements, have " << vectorData.size() << ")" COLOR_END << std::endl;

	// }
	// std::cout << PINK "\nSTEP 2: creating pendings" COLOR_END << std::endl;
	fordJohnsonVectorStep2(vectorData, element_size);
}

void PmergeMe::fordJohnsonDequeStep1(std::deque<int> &dequeData, size_t element_size)
{
	for (size_t i = 0; i + (element_size * 2) <= dequeData.size(); i += (element_size * 2))
	{
		int a = dequeData[i + element_size - 1];
		int b = dequeData[i + (element_size * 2) - 1];

		std::deque<int> leftGroup, rightGroup;
		for (size_t j = 0; j < element_size; j++)
		{
			leftGroup.push_back(dequeData[i + j]);
			rightGroup.push_back(dequeData[i + element_size + j]);
		}
		if (a > b)
		{
			for (size_t j = 0; j < element_size; j++)
				std::swap(dequeData[i + j], dequeData[i + element_size + j]);
		}

		++_dequeComparisons;
	}
	if ((element_size * 2) * 2 <= dequeData.size())
		fordJohnsonDequeStep1(dequeData, element_size * 2);
	fordJohnsonDequeStep2(dequeData, element_size);
}


void PmergeMe::fordJohnsonVectorStep2(std::vector<int> &vectorData, size_t element_size)
{
	// std::cout << CYAN "Step 2 for element_size = " << element_size << COLOR_END << std::endl;

	std::vector<std::pair<std::vector<int>, int> > pending;
	std::vector<int> nonParticipating;
	size_t pair_size = element_size * 2;
	size_t complete_pairs = vectorData.size() / pair_size;

	size_t remaining_elements = vectorData.size() % pair_size;
	bool has_straggler = false;
	size_t straggler_start = 0;
	size_t np_start = vectorData.size();

	if (remaining_elements >= element_size)
	{
		has_straggler = true;
		straggler_start = complete_pairs * pair_size;
		np_start = straggler_start + element_size;

	}
	else if (remaining_elements > 0)
	{
		np_start = complete_pairs * pair_size;
	}
	// Extraire les NP d'abord
	for (size_t i = np_start; i < vectorData.size(); i++)
	{
		nonParticipating.push_back(vectorData[i]);
	}

	std::vector<int> main_chain;

	if (complete_pairs >= 1)
	{
		// jadd b1
		for (size_t i = 0; i < element_size; i++)
		{
			main_chain.push_back(vectorData[i]);
		}

		// j'add a1
		for (size_t i = element_size; i < pair_size; i++)
		{
			main_chain.push_back(vectorData[i]);
		}
		// juste les a
		for (size_t i = 1; i < complete_pairs; i++)
		{
			size_t pair_start = i * pair_size;
			size_t b_start = pair_start;
			size_t a_start = pair_start + element_size;

			// Ajouter A à main_chain
			for (size_t j = 0; j < element_size; j++)
			{
				main_chain.push_back(vectorData[a_start + j]);
			}
			// Ajouter B à pending avec bound = dernier élément de A
			std::vector<int> b_group;
			for (size_t j = 0; j < element_size; j++)
			{
				b_group.push_back(vectorData[b_start + j]);
			}
			int bound = vectorData[a_start + element_size - 1];

			pending.push_back(std::make_pair(b_group, bound));
		}
	}
	// Ajouter le straggler à pending s'il existe
	if (has_straggler)
	{
		std::vector<int> straggler_group;
		for (size_t i = straggler_start; i < straggler_start + element_size; i++)
		{
			straggler_group.push_back(vectorData[i]);
		}

		// bound = max de lui-même si pas de A correspondant
		int bound = *std::max_element(straggler_group.begin(), straggler_group.end());

		pending.push_back(std::make_pair(straggler_group, bound));
	}

	// std::cout << PINK "STEP 3: Binary search and insertion with Jacobsthal" COLOR_END << std::endl;
	fordJohnsonVectorStep3(main_chain, element_size, pending);

	vectorData = main_chain;
	for (size_t i = 0; i < nonParticipating.size(); i++)
	{
		vectorData.push_back(nonParticipating[i]);
	}

	// std::cout << "Main chain: ";
	// displayVector(vectorData);
	// std::cout << std::endl;

	// Affichage des pending - voyons à supprimer plus tard
	// std::cout << "Pending: ";
	// for (size_t i = 0; i < pending.size(); i++)
	// {
	// 	std::cout << "([";
	// 	for (size_t j = 0; j < pending[i].first.size(); j++)
	// 	{
	// 		std::cout << pending[i].first[j];
	// 		if (j < pending[i].first.size() - 1)
	// 			std::cout << " ";
	// 	}
	// 	std::cout << "]," << pending[i].second << ")";
	// 	if (i < pending.size() - 1)
	// 		std::cout << " ";
	// }
	// std::cout << std::endl;

	// if (!nonParticipating.empty())
	// {
	// 	std::cout << "Non participating: ";
	// 	for (size_t i = 0; i < nonParticipating.size(); i++)
	// 	{
	// 		std::cout << nonParticipating[i];
	// 		if (i < nonParticipating.size() - 1)
	// 			std::cout << " ";
	// 	}
	// 	std::cout << std::endl;
	// }

	// std::cout << "After processing - main chain: ";
	// displayVector(vectorData);
	// std::cout << std::endl;
}



void PmergeMe::fordJohnsonDequeStep2(std::deque<int> &dequeData, size_t element_size)
{
	// std::cout << CYAN "Step 2 for element_size = " << element_size << COLOR_END << std::endl;

	std::deque<std::pair<std::deque<int>, int> > pending;
	std::deque<int> nonParticipating;
	size_t pair_size = element_size * 2;
	size_t complete_pairs = dequeData.size() / pair_size;

	size_t remaining_elements = dequeData.size() % pair_size;
	bool has_straggler = false;
	size_t straggler_start = 0;
	size_t np_start = dequeData.size();

	if (remaining_elements >= element_size)
	{
		has_straggler = true;
		straggler_start = complete_pairs * pair_size;
		np_start = straggler_start + element_size;

	}
	else if (remaining_elements > 0)
	{
		np_start = complete_pairs * pair_size;
	}
	// Extraire les NP d'abord
	for (size_t i = np_start; i < dequeData.size(); i++)
	{
		nonParticipating.push_back(dequeData[i]);
	}

	std::deque<int> main_chain;

	if (complete_pairs >= 1)
	{
		// jadd b1
		for (size_t i = 0; i < element_size; i++)
		{
			main_chain.push_back(dequeData[i]);
		}

		// j'add a1
		for (size_t i = element_size; i < pair_size; i++)
		{
			main_chain.push_back(dequeData[i]);
		}
		// juste les a
		for (size_t i = 1; i < complete_pairs; i++)
		{
			size_t pair_start = i * pair_size;
			size_t b_start = pair_start;
			size_t a_start = pair_start + element_size;

			// Ajouter A à main_chain
			for (size_t j = 0; j < element_size; j++)
			{
				main_chain.push_back(dequeData[a_start + j]);
			}
			// Ajouter B à pending avec bound = dernier élément de A
			std::deque<int> b_group;
			for (size_t j = 0; j < element_size; j++)
			{
				b_group.push_back(dequeData[b_start + j]);
			}
			int bound = dequeData[a_start + element_size - 1];

			pending.push_back(std::make_pair(b_group, bound));
		}
	}
	// Ajouter le straggler à pending s'il existe
	if (has_straggler)
	{
		std::deque<int> straggler_group;
		for (size_t i = straggler_start; i < straggler_start + element_size; i++)
		{
			straggler_group.push_back(dequeData[i]);
		}

		// bound = max de lui-même si pas de A correspondant
		int bound = *std::max_element(straggler_group.begin(), straggler_group.end());

		pending.push_back(std::make_pair(straggler_group, bound));
	}

	// std::cout << PINK "STEP 3: Binary search and insertion with Jacobsthal" COLOR_END << std::endl;
	fordJohnsonDequeStep3(main_chain, element_size, pending);

	dequeData = main_chain;
	for (size_t i = 0; i < nonParticipating.size(); i++)
	{
		dequeData.push_back(nonParticipating[i]);
	}

	// std::cout << "Main chain: ";
	// displayVector(vectorData);
	// std::cout << std::endl;

	// Affichage des pending - voyons à supprimer plus tard
	// std::cout << "Pending: ";
	// for (size_t i = 0; i < pending.size(); i++)
	// {
	// 	std::cout << "([";
	// 	for (size_t j = 0; j < pending[i].first.size(); j++)
	// 	{
	// 		std::cout << pending[i].first[j];
	// 		if (j < pending[i].first.size() - 1)
	// 			std::cout << " ";
	// 	}
	// 	std::cout << "]," << pending[i].second << ")";
	// 	if (i < pending.size() - 1)
	// 		std::cout << " ";
	// }
	// std::cout << std::endl;

	// if (!nonParticipating.empty())
	// {
	// 	std::cout << "Non participating: ";
	// 	for (size_t i = 0; i < nonParticipating.size(); i++)
	// 	{
	// 		std::cout << nonParticipating[i];
	// 		if (i < nonParticipating.size() - 1)
	// 			std::cout << " ";
	// 	}
	// 	std::cout << std::endl;
	// }

	// std::cout << "After processing - main chain: ";
	// displayVector(vectorData);
	// std::cout << std::endl;
}

void PmergeMe::displayVector(const std::vector<int> &seq) const
{
	for (size_t i = 0; i < seq.size(); i++)
	{
		std::cout << seq[i];
		if (i < seq.size() - 1)
			std::cout << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::displayDeque(const std::deque<int> &seq) const
{
	for (size_t i = 0; i < seq.size(); i++)
	{
		std::cout << seq[i];
		if (i < seq.size() - 1)
			std::cout << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::fordJohnsonVectorStep3(std::vector<int> &main_chain, size_t element_size, std::vector<std::pair<std::vector<int>, int> > &pending)
{
	size_t	Jacobsthal_idx = 1;
	size_t reinserted_b = 1;
	while (!pending.empty())
	{		
		++Jacobsthal_idx;
		size_t	Jacobsthal_nb = (pow(2, Jacobsthal_idx + 1) + pow(-1, Jacobsthal_idx)) / 3;
		
		size_t idx_to_reinsert = Jacobsthal_nb - reinserted_b - 1;

		if (idx_to_reinsert > pending.size() - 1)
			idx_to_reinsert = pending.size() - 1;

		binarysearchVector(idx_to_reinsert, main_chain, element_size, pending);

		++reinserted_b;
		while (idx_to_reinsert-- != 0)
		{
			binarysearchVector(idx_to_reinsert, main_chain, element_size, pending);
			++reinserted_b;
		}
	}
}
void PmergeMe::fordJohnsonDequeStep3(std::deque<int> &main_chain, size_t element_size, std::deque<std::pair<std::deque<int>, int> > &pending)
{
	size_t	Jacobsthal_idx = 1;
	size_t reinserted_b = 1;
	while (!pending.empty())
	{		
		++Jacobsthal_idx;
		size_t	Jacobsthal_nb = (pow(2, Jacobsthal_idx + 1) + pow(-1, Jacobsthal_idx)) / 3;
		
		size_t idx_to_reinsert = Jacobsthal_nb - reinserted_b - 1;

		if (idx_to_reinsert > pending.size() - 1)
			idx_to_reinsert = pending.size() - 1;

		binarysearchDeque(idx_to_reinsert, main_chain, element_size, pending);

		++reinserted_b;
		while (idx_to_reinsert-- != 0)
		{
			binarysearchDeque(idx_to_reinsert, main_chain, element_size, pending);
			++reinserted_b;
		}
	}
}

void PmergeMe::binarysearchVector(size_t idx_to_reinsert, std::vector<int> &main_chain, size_t element_size, std::vector<std::pair<std::vector<int>, int> > &pending)
{
	int to_compare = pending[idx_to_reinsert].first[element_size - 1];
	int bound = pending[idx_to_reinsert].second;
	size_t max = 0;
	size_t min = element_size - 1;

	if (bound == to_compare)
	{
		max = main_chain.size() + element_size - 1;
	}
	else
	{
		for(size_t i = 0; i < main_chain.size(); i++)
		{
			if (main_chain[i] == bound)
			{
				max = i;
				break;
			}
		}
	}
	while (min != max)
	{
		// on recalcule compos
		size_t	distance = (max - min) / 2;
		size_t	comp_pos = min + distance - (distance % element_size);
		if (to_compare > main_chain[comp_pos])
			min = comp_pos + element_size;
		else
		 	max = comp_pos;
		++_vectorComparisons;
	}
	std::vector<int>::iterator it = main_chain.begin() + (max - element_size + 1);
	std::vector<int> &to_copy = pending[idx_to_reinsert].first;
	for (size_t i = 0; i < element_size; i++)
	{
		it = main_chain.insert(it, to_copy[i]) + 1;
	}
	pending.erase(pending.begin() + idx_to_reinsert);
}


// DEQUE

void PmergeMe::binarysearchDeque(size_t idx_to_reinsert, std::deque<int> &main_chain, size_t element_size, std::deque<std::pair<std::deque<int>, int> > &pending)
{
	int to_compare = pending[idx_to_reinsert].first[element_size - 1];
	int bound = pending[idx_to_reinsert].second;
	size_t max = 0;
	size_t min = element_size - 1;

	if (bound == to_compare)
	{
		max = main_chain.size() + element_size - 1;
	}
	else
	{
		for(size_t i = 0; i < main_chain.size(); i++)
		{
			if (main_chain[i] == bound)
			{
				max = i;
				break;
			}
		}
	}
	while (min != max)
	{
		// on recalcule compos
		size_t	distance = (max - min) / 2;
		size_t	comp_pos = min + distance - (distance % element_size);
		if (to_compare > main_chain[comp_pos])
			min = comp_pos + element_size;
		else
		 	max = comp_pos;
		++_dequeComparisons;
	}
	std::deque<int>::iterator it = main_chain.begin() + (max - element_size + 1);
	std::deque<int> &to_copy = pending[idx_to_reinsert].first;
	for (size_t i = 0; i < element_size; i++)
	{
		it = main_chain.insert(it, to_copy[i]) + 1;
	}
	pending.erase(pending.begin() + idx_to_reinsert);
}