#include <iostream>

const int v = 100; 
class Graph
{
private:
	int** matrix;
	int vertexes;
public:
	Graph(int a) : vertexes(a) 
	{
		int** matrix = new int* [vertexes];
		for (int i = 0; i < vertexes; ++i)
		{
			matrix[i] = new int[vertexes]();
		}
	}
	~Graph()
	{
		for (int i = 0; i < vertexes; ++i) 
		{
			delete[] matrix[i];
		}
		delete[] matrix;
	}
	void Edge(int from, int to)
	{
		matrix[from - 1][to - 1] = 1;
		matrix[to - 1][from - 1] = 1;
	}
	
	void Array()
	{
		int* array = new int[vertexes]();
		for (int i = 0; i < vertexes; ++i)
		{
			for (int j = 0; j < vertexes; ++j)
			{
				if (matrix[i][j] == 1)
				{
					++array[i];
				}
			}
		}
		for (int i = 0; i < vertexes; ++i)
		{
			std::cout << array[i] << " ";
		}
		std::cout << std::endl;
		delete[] array;
	}
};

int main(int argc, char* argv[])
{
	int n = 0;
	int m = 0;
	std::cin >> n;
	std::cin >> m;
	Graph graph(n);
	for (int i = 0; i < m; ++i)
	{
		int from = 0;
		int to = 0;
		std::cin >> from;
		std::cin >> to;
		graph.Edge(from, to);
	}
	graph.Array();

	return 0;
}