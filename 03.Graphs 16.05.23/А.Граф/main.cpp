#include <iostream>
#include <vector>
#include <string.h>

int main()
{
	int start, finish, edgeCount, v1, v2, weight;
	std::cin >> start >> finish >> edgeCount;

	start--;
	finish--;

	int **graph = new int*[edgeCount];

	for (int i = 0; i < edgeCount; i++)
	{
		graph[i] = new int[edgeCount];
		std::fill_n(graph[i], edgeCount, 0);
	}
	for (int i = 0; i < edgeCount; i++)
	{
		std::cin >> v1 >> v2 >> weight;
		graph[v1 - 1][v2 - 1] = weight;
	}
	
	// for (int i = 0; i < edgeCount; i++)
	// {
	// 	for (int j = 0; j < edgeCount; j++)
	// 	{
	// 		std:: cout << graph[i][j] << " ";
	// 	}
	// 	std:: cout  << std::endl;
	// }
	// std:: cout << "======================="<< std::endl;


	std::vector<int> distance;
  	std::vector<bool> notVizited;
	for (size_t i = 0; i < edgeCount; i++) {
    distance.push_back(10000);
    notVizited.push_back(true);
  }
	std::fill_n(notVizited.begin(), edgeCount, true);

	int ret = 1;
	int minindex = 0;
  	int min;
	int tmp;
	distance[start] = 0;
	while (ret || minindex < 10000)
	{
		minindex = 10000;
		min = 10000;
		for (int i = 0; i < edgeCount; i++)
		{
			if (notVizited[i] == true && distance[i] < min)
			{
				min = distance[i];
				minindex = i;
			}
		}
		if (minindex != 10000)
		{
			for (int i = 0; i < edgeCount; i++)
			{
				if (graph[minindex][i] > 0)
				{
					tmp = min + graph[minindex][i];
					if (tmp < distance[i])
						distance[i] = tmp;
				}
			}
			notVizited[minindex] = false;
		}
		ret = 0;
	}
	if (distance[finish] == 10000)
		distance[finish] = 0;
	std::cout << distance[finish] << std::endl;
	return (0);
}