#include "stdafx.h"
using namespace std;

vector<size_t> GetRandomPermutation(const size_t size)
{
	srand(static_cast<int>(time(NULL)));
	vector<size_t> permutation(size);
	iota(permutation.begin(), permutation.end(), 1);

	for (size_t i = 0; i < size; ++i)
	{
		const int randomPosition = rand() % size;
		swap(permutation[i], permutation[randomPosition]);
	}

	return permutation;
}

void Print(const vector<size_t>& v)
{
	copy(v.begin(), v.end(), ostream_iterator<size_t>(cout));
	cout << "\n";
}

int main(const int argc, const char* argv[])
{
	if (argc != 2)
	{
		cout << "Invalid count  of arguments";
		return 1;
	}

	const size_t arraySize = atoi(argv[1]);
	Print(GetRandomPermutation(arraySize));
	return 0;
}
