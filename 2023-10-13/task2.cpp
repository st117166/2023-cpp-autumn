#include <iostream>

typedef unsigned int uint;

int main(int argc, char* argv[])
{
	const int b = sizeof(uint) * 4;

	uint a = 0;
	std::cin >> a;
	std::cout << "0b ";
	for (int i = b - 1; i >= 0; --i) {
		std::cout << ((a >> i) & 1);
	}
	std::cout << std::endl;
	if (a == 0) {
		a = ~a;
	}
	else {
		int s = b - 1;
		int e = 0;
		while ((a >> s & 1) == 0) {
			--s;
		}
		while ((a >> e & 1) == 0) {
			++e;
		}
		uint mask = 0;
		mask = ~mask;
		mask = (mask >> (s - e));
		mask = ~mask;
		mask = (mask >> (b - s));
		a = a ^ mask;
		{
			std::cout << "0b ";
			for (int i = b - 1; i >= 0; --i) {
				std::cout << ((a >> i) & 1);
			}
		}
	}

}
