#include "stdafx.h"
using namespace std;

void Print(const vector<size_t>& v)
{
	copy(v.begin(), v.end(), ostream_iterator<size_t>(cout));
	cout << "\n";
}

int main(const int argc, char* argv[])
{
	if (argc != 2)
	{
		cout << "Invalid count of arguments";
		return 1;
	}

	const int additionCellsCount = 2;
	const size_t arraySize = atoi(argv[1]);
	vector<size_t> pi(arraySize + additionCellsCount);
	iota(pi.begin(), pi.end(), 0);

	vector<size_t> p(arraySize + additionCellsCount);
	p = pi;

	vector<int> d(arraySize + additionCellsCount);
	fill(d.begin() + 1, d.end() - 1, -1);

	const int borderNumber = arraySize + 1;
	d[1] = 0;
	pi[0] = borderNumber;
	pi[arraySize + 1] = borderNumber;
	int m = borderNumber;
	int n = arraySize;

	boost::timer time;
	time.restart();
	while (m != 1)
	{
		m = n;
		while ((pi[p[m] + d[m]]) > m)
		{
			d[m] = -d[m];
			--m;
		}
		swap(pi[p[m]], pi[p[m] + d[m]]);
		swap(p[pi[p[m]]], p[m]);
	}
	printf("Time: %.2f \n", time.elapsed());

    return 0;
}

