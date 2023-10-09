#include <iostream>
#include <cstdlib>

int main(int argc, char**)
{
	int n = 0;
	std::cin >> n;
	int d = 0;
	int *a = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; ++i) {
		std::cin >> *(a + i);
		if (d <= *(a + i)) {
			d = *(a + i);
		}
	}
	free(a);
	std::cout << d;
}
