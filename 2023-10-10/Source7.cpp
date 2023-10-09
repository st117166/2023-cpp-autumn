#include <iostream>
#include <cstdlib>

int main(int, char**)
{
	int n = 0;
	std::cin >> n;
	int d = 0;
	int i = 0;
	int **a = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; ++i) {
		*a = (int*)malloc(sizeof(int*) * n);
		if (*(a + i) <= 0) {
			for (int j = i; j < n - 1; ++j) {
				*(a + j) = *(a + j + 1);
				++d;
			}
		}
	}
	n = n - d;
	for (int i = 0; i < n; ++i) {
		std::cout << *(a + i) << " ";
	}
	for (int i = 0; i < n; ++i) {
		free(*(a + i));
	}
	free(a);
	return 0;
}