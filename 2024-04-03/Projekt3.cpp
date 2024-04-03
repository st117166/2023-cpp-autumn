#include <iostream>
#include <fstream>

int main(int argc, char* argv[])
{
	std::ifstream fin;
	fin.open("INPUT.TXT");
	std::ofstream fout;
	fout.open("OUTPUT.TXT");
	int n = 0; 
	int j = 0;
	int i = 0;
	fin >> n;
	int** a = new int*[n];
	int* b = new int[n];
	for (int i = 0; i < n; ++i)
	{
		a[i] = new int[n];
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			fin >> a[i][j];
		}
	}
	for (int i = 0; i < n; ++i)
	{
		fin >> b[i];
	}
	int k = 0;
	for (int i = 0; i < n; ++i)
	{
		for (j = i + 1; j < n; ++j)
		{
			if (a[i][j] == 1)
			{
				if (b[i] != b[j])
				{
					++k;
				}
			}
		}
	}
	fout << k;
	delete[] a;
	delete[] b;

	return 0;
}