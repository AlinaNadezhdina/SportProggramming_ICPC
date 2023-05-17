#include <iostream>
#include <string.h>

int countEdges(int **graph, int count)
{
	int edges = 0;
	for (int i = 0; i < count; i++)
	{
		for (int j = i; j < count; j++)
		{
			if (graph[i][j])
				edges++;
		}
	}
	return (edges);
}

void dfs(int v, int **graph, int *visited, int count)
{
	if (visited[v])
		return;
	else
	{
		visited[v] = 1;
		for (int i = 0; i < count; i++)
		{
			if (graph[v][i])
				dfs(i, graph, visited, count);
		}
	}
}


int main()
{
	int count;
	std::cin >> count;

	int **graph = new int*[count];

	for (int i = 0; i < count; i++)
	{
		graph[i] = new int[count];
		for (int j = 0; j < count; j++)
		{
			std::cin >> graph[i][j];
		}
	}
	int edges = countEdges(graph, count);
	if (edges !=  count - 1)
	{
		std::cout << "NO" << std::endl;
		return 0;
	}
	int *visited = new int[count];
	memset(visited, 0, count);
	dfs(0, graph, visited, count);

	for (int i = 0; i < count; i++)
	{
		if (visited[i] != 1)
		{
			std::cout << "NO" << std::endl;
			return 0;
		}	
	}
	std::cout << "YES" << std::endl;
	return (0);
}