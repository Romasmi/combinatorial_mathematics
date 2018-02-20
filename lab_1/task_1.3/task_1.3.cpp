#include "stdafx.h"
#include <boost/timer.hpp>
using namespace std;

bool PrintCombinations(const unsigned int k, const unsigned int n)
{
	if (k > n)
	{
		cout << "K must be less or equil to N" << endl;
		return false;
	}

	vector<int> combination(k + 1);

	combination[0] = -1;
	for (unsigned int i = 1; i <= k; ++i)
	{
		combination[i] = i;
	}

	unsigned int j = 1;
	while (j != 0)
	{
		//copy(combination.begin() + 1, combination.end(), ostream_iterator<int>(cout, " "));
		//cout << "\n";

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

	return true;
}

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << "Invalid  parameter count" << endl;
		return 1;
	}

	unsigned int k;
	unsigned int n;
	try 
	{
		k = stoi(argv[1]);
		n = stoi(argv[2]);
	}
	catch (exception &e)
	{
		cout << e.what() << endl;
		return 1;
	}

	if (k > n)
	{
		cout << "K must be less or equil to N" << endl;
		return 1;
	}

	boost::timer time;
	time.restart();

	PrintCombinations(k, n);

	printf("Time: %.2f \n", time.elapsed());
    return 0;
}

