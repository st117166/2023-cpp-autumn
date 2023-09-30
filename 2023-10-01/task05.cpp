#include <iostream>

int main(int argc, char* argv[])
{
	int a = 1;
	int b = 1;
	int i = 0;
	int c = 0;
	int y = 0;
	std::cin >> a;
	while (b <= a) {
		while (b != 0) {
			c = b % 10;
			y = y * 10 + c;
			b = b / 10;
		}
		if (y == b) {
			std::cout << ++i;
			}
		++b;
	}
	return 0;
}
