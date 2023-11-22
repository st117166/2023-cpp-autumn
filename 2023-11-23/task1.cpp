#include <iostream>

void hanoi(int n, int from, int to);

int main(int argc, char* argv[])
{
	int n = 0;
	std::cin >> n;
	int from = 1;
	int to = 3;
	hanoi(n, from, to);
	return 0;
}

void hanoi(int n, int from, int to)
{
	if (n <= 0)
	{
		return;
	}
	int res = 6 - from - to;
	hanoi(n - 1, from, res);
	printf("%d %d %d\n", n, from, to);
	hanoi(n - 1, res, to);
}
