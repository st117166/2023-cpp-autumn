#include <iostream>

typedef unsigned short ush;

int main(int argc, char* argv[])
{
	const int m = sizeof(ush) * 8;
	ush a = 0;
	ush b = 0;
	ush c = 0;
	std::cin >> a;
	std::cin >> b;
	bool up = 0;
	for (int i = 0; i < m; ++i) {
		bool bita = (a >> i & 1);
		bool bitb = (b >> i & 1);
		bool d = bita ^ bitb ^ up;
		c = c | ((int)d << i);
	}
	std::cout << c;
    return 0;
}