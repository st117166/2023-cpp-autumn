#include <iostream>

int main(int argc, char* argv[])
{
	int n = 0;
	int a = 0;
	int b = 1;
	int i = 0;
	std::cin >> n;
	while (i < n) {
		++i;
		b = a + b;
		a = b - a;
	}
	std::cout << a;
	return 0;
}