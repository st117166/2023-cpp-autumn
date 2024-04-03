#include <iostream>
#include <fstream>

int main(int argc, char* argv[])
{
	std::ifstream fin;
	fin.open("INPUT.TXT");
	std::ofstream fout;
	fout.open("OUTPUT.TXT");
	int n = 0;
	int k = 0;
	fin >> n;
	for (int i = 0; i < n * n; ++i) 
	{
		int m = 0;
		fin >> m;
		k += m;
	}
	fout << k / 2;
	fin.close();
	fout.close();

	return 0;
}