#include <iostream>

void hanoi(int n, int from, int to, int res);

int main(int argc, char* argv[])
{
	int n = 0;
	std::cin >> n;
	int from = 1;
	int to = 3;
	int res = 6 - from - to;
	hanoi(n, from, to, res);
	return 0;
}

void hanoi(int n, int from, int to, int res)
{
	if (n == 1)
	{
		printf("%d %d %d\n", n, from, res);
		printf("%d %d %d\n", n, res, to);
	}
	else
	{
		hanoi(n - 1, from, to, res);
		printf("%d %d %d\n", n, from, res);
		hanoi(n - 1, to, from, res);
		printf("%d %d %d\n", n, from, to);
		hanoi(n - 1, from, to, res);
	}
}