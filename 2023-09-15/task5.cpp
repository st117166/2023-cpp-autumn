#include <iostream>

int main(int argc, char* argv[]) 
{
	int a = 0;
        int b = 0;
        int c = 0;
        int d = 0;
        int l = 109;
	std::cin >> a;
        std::cin >> b;
	c = (a * b) % l;
	d = (l + c) % l + 1;
	std::cout << d;
	return EXIT_SUCCESS;
}
