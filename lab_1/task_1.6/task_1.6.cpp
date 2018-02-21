#include "stdafx.h"
using namespace std;

struct Cargo
{
	int number;
	double weight;
	double price;
};

struct PrintCargo
{
	void operator() (Cargo item)
	{
		cout << item.number << ": "
			<< "weight " << item.weight << ", "
			<< "price " << item.price << "\n";
	}
} printCargo;

void PrintCargoVector(vector<Cargo> &array)
{
	for_each(array.begin(), array.end(), printCargo);
}

bool GetCargoFromFile(vector<Cargo> &cargoArray, const string fileName)
{
	ifstream inputFile(fileName);
	if (!inputFile.is_open())
	{
		return false;
	}

	string inputString;
	Cargo currentCargo;
	currentCargo.number = 0;
	while (!inputFile.eof())
	{
		try
		{
			++currentCargo.number;
			inputFile >> currentCargo.weight;
			inputFile >> currentCargo.price;
			cargoArray.push_back(currentCargo);
		}
		catch (exception &e)
		{
			cout << e.what() << "\n";
			cout << "Invalid wight or price value for cargo number " << currentCargo.number << "\n";
		}
	}

	return true;
}

Cargo GetBackpackInformation(vector<Cargo> &suggestedCargo, vector<int> positionsVector)
{
	Cargo backpack;
	backpack.weight = 0;
	backpack.price = 0;

	for (size_t i = 1; i < positionsVector.size(); ++i)
	{
		backpack.price += suggestedCargo[positionsVector[i]].price;
		backpack.weight += suggestedCargo[positionsVector[i]].weight;
	}

	return backpack;
}

void PrintBestCargoSuggestion(vector<Cargo> &suggestedCargo, const double maxWeidht)
{
	float maxTotalPrice = 0;

	size_t k = 1;
	size_t n = suggestedCargo.size() - 1;
	vector<int> bestCombination;
	Cargo backpack;

	while (k <= n)
	{
		vector<int> combination(k + 1);

		combination[0] = -1;
		for (unsigned int i = 1; i <= k; ++i)
		{
			combination[i] = i;
		}

		size_t j = 1;
		while (j != 0)
		{
			backpack = GetBackpackInformation(suggestedCargo, combination);

			if (backpack.weight < maxWeidht && backpack.price > maxTotalPrice)
			{
				maxTotalPrice = backpack.price;
				bestCombination = combination;
			}

			j = k;
			while (combination[j] == n - k + j)
			{
				--j;
			}
			++combination[j];

			for (unsigned int i = j + 1; i <= k; ++i)
			{
				combination[i] = combination[i - 1] + 1;
			}
		}
		++k;
	}

	copy(bestCombination.begin() + 1, bestCombination.end(), ostream_iterator<int>(cout, " "));
	cout << "\n";
}


int main(const int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << "Invalid parameters count" << endl;
		return 1;
	}

	double maxWeight;
	try
	{
		maxWeight = stod(argv[1]);
	}
	catch (const std::exception& e)
	{
		cout << e.what() << "\n";
		return 1;
	}

	vector<Cargo> suggestedCargo;
	if (!GetCargoFromFile(suggestedCargo, argv[2]))
	{
		cout << "File not found" << endl;
	}

	PrintBestCargoSuggestion(suggestedCargo, maxWeight);

    return 0;
}

