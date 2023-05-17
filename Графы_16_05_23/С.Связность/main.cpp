#include <iostream>
#include <string.h>


void dfs(int v, int **graph, int *visited, int count)
{
	if (visited[v])
		return;
	else
	{
		visited[v] = 1;
		for (int i = 0; i < count; i++)
		{
			//graph[v][i] || graph[i][v] - если граф ориентированный, нужна проверка на соединение хотя бы в vi или iv
			if ((graph[v][i] || graph[i][v])  && visited[i] == 0)
			{
				dfs(i, graph, visited, count);
			}
		}
	}
}

int main()
{
	int vertCount, edgeCount, v1, v2;
	std::cin >> vertCount >> edgeCount;

	int **graph = new int*[vertCount];

	for (int i = 0; i < vertCount; i++)
	{
		graph[i] = new int[vertCount];
		for (int j = 0; j < vertCount; j++)
		{
			std::fill_n(graph[i], vertCount, 0);
		}
	}
	for (int i = 0; i < edgeCount; i++)
	{
		std::cin >> v1 >> v2;
		graph[v1 - 1][v2 - 1] = 1;
	}
	int *visited = new int[vertCount];
	memset(visited, 0, vertCount);

	int count = 0;
	for(int i = 0; i < vertCount; i++)
	{
		if(visited[i] == 0)
		{	
			dfs(i, graph, visited, vertCount);
			count++;
		}
	}
	std::cout << count << std::endl;
	return (0);
}