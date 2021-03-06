#include "stdafx.h"
using namespace std;

void Print(const vector<size_t>& v)
{
	copy(v.begin(), v.end(), ostream_iterator<size_t>(cout));
	cout << "\n";
}

int main(const size_t argc, const char** argv)
{
	if (argc < 2)
	{
		return 1;
	}
	const size_t arraySize = atoi(argv[1]);

	vector<size_t> permutation(arraySize);
	iota(permutation.begin(), permutation.end(), 1);

	boost::timer time;
	time.restart();
	do
	{
		//Print(permutation);
	} while (next_permutation(permutation.begin(), permutation.end()));
	printf("Time: %.2f \n", time.elapsed());
	return 0;
}