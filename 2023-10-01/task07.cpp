#include <iostream>

int main(int argc, char* argv[])
{
	int n = 0;
	int k = 0;
	std::cin >> n;
	while (n > 1) {
		++k;
		n = (n + 1) / 2;
	}
	std::cout << k;
	return 0;
}
