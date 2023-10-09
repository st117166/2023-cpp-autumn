#include <iostream>
#include <cstdlib>

int main(int argc, char**)
{
	int n = 0;
	int d = 0;
	int f = 0;
	std::cin >> n;
	int *a = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; ++i) {
		std::cin >> *(a + i);
		if (*(a + d) > *(a + i)) {
			d = i;
			if (*(a + d) == *(a + i)) {
				d = d;
			}
		}
		if (*(a + f) <= *(a + i)) {
			f = i;
		}
	}
	int c = 0;
	c = *(a + f);
	*(a + f) = *(a + d);
	*(a + d) = c;
	for (int i = 0; i < n; ++i) {
		std::cout << *(a + i) << " ";
	}
	return 0;
}