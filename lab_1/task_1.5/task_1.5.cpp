#include "stdafx.h"
using namespace std;

void PrintRandomPermutation(const int max)
{
	vector<int> permutation(max);
	iota(permutation.begin(), permutation.end(), 1);

	for (int i = max - 1; i >= 0; --i)
	{
		int movingElementPosition = rand() % (i + 1);
		swap(permutation[i], permutation[movingElementPosition]);
	}
	copy(permutation.begin(), permutation.end(), ostream_iterator<int>(cout));

	cout << "\n";
}

int main(const int argc, char* argv[])
{
	if (argc != 2)
	{
		cout << "Invalid arguments count";
		return 1;
	}

	int max;
	try
	{
		max = stoi(argv[1]);
	}
	catch (const std::exception& e)
	{
		cout << e.what() << "\n";
		return 1;
	}

	PrintRandomPermutation(max);

    return 0;
}

