#include <iostream>
#include <cstdlib>

int main(int argc, char**)
{
	int n = 0;
	int d = 0;
	std::cin >> n;
	int *a = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; ++i) {
		std::cin >> *(a + i);
	    if (*(a + i) > 0) {
		    ++d;
	    }
    }
	free(a);
    std::cout << d;
    return 0;
}
