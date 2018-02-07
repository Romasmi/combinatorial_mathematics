#include "stdafx.h"
#include <vector>
using namespace std;

void PrintArray(int* array, const int end = 0, const int start = 0)
{
	for (int i = start; i < end; i++)
	{
		cout << array[i];
	}
	cout << '\n';
}

int main(const int argc, const char** argv)
{
	if (argc < 2)
	{
		return 1;
	}
	const int SIZE = atoi(argv[1]);

	int *pi = new int[SIZE + 2];
	int *p = new int[SIZE + 2];
	int *d = new int[SIZE + 2];

	for (int i = 1; i <= SIZE; i++)
	{
		pi[i] = i;
		p[i] = i;
		d[i] = -1;
	}
	d[1] = 0;
	int m = SIZE + 1;
	pi[0] = m;
	pi[SIZE + 1] = m;

	while (m != 1) 
	{
		PrintArray(pi, SIZE + 1, 1);
		m = SIZE;

		while (pi[p[m] + d[m]] > m)
		{
			d[m] *= -1;
			m = m - 1;
		}

		swap(pi[p[m]], pi[p[m] + d[m]]);
		swap(p[pi[p[m]]], p[m]);
	}

	return 0;
}

