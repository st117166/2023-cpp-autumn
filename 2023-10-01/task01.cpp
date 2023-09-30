#include <iostream>

int main(int argc, char* argv[])
{
	int a = 0;
	int i = 0;
	int b = 1;
	int j = 0;
	std::cin >> a;
	for (i = 1; b <= a; ++i) {
		for (j = 1; j <= i && b <= a; ++j) {
			std::cout << i << " ";
			++b;
		}
	}
	return 0;
}