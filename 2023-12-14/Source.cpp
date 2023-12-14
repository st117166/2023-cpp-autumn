#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>

int main(int argc, char** argv)
{
	FILE* f = fopen("in.txt", "r");
	f = fopen("in.txt", "r");
	int sum = 1;
	while (!feof(f)) {
		char c = 0;
		fscanf(f, "%c", &c);
		if (c == ' ' | c == '\n')
		{
			sum += 1;
		}
	}
	fclose(f);
	printf("%d\n", sum);
	return 0;
}