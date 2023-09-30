#include <iostream>

int main(int argc, char* argv[])
{
	int a = 0;
	int i = 0;
	int b = 1;
	std::cin >> a;
	while (b * b <= a) {
		if (a % b == 0) {
			if (b == a / b) {
				++i;
			}
			else {
				i = i + 2;
			}
		}
		++b;
	}
	std::cout << i;
	return 0;
}