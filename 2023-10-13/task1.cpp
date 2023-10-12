#include <iostream>

int main(int argc, char argv[])
{
	int n = 0;
	std::cin >> n;
	int d = 0;

	for (int i = 0; i < 32; ++i) {
		d += (n >> (31 - i) & 1);
	}
	std::cout << d;
	return 0;
}
