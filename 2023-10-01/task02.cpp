#include <iostream>
int main(int argc, char* argv[])
{
	int x = 0;
	int y = 0;
	int a = 0;
	std::cin >> x;
	while (x != 0) {
		a = x % 10;
		y = y * 10 + a;
		x = x / 10;
	}
    std::cout << y;
	return 0;
}
