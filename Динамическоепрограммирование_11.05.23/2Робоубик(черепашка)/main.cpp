#include <iostream>
#include <algorithm>

int main()
{
	int roomSize;
	std::cin >> roomSize;
	int **data = new int *[roomSize];
	for (int i = 0; i < roomSize; i++)
	{
		data[i] = new int[roomSize];
		for (int j = 0; j < roomSize; j++)
		{
			std::cin >> data[i][j];
		}
	}

	int **dynamic = new int *[roomSize + 1];
	for (int i = 0; i < roomSize + 1; i++)
	{
		dynamic[i] = new int[roomSize + 1];
		for (int j = 0; j < roomSize + 1; j++)
		{
			if (i == 0 || j == 0)
			{
				dynamic[i][j] = 0;
			}
			else
			{
				dynamic[i][j] = std::max(dynamic[i - 1][j], dynamic[i][j - 1]) + data[i - 1][j - 1];
			}
		}
	}

	// for (int i = 0; i < roomSize + 1; i++)
	// {
	// 	for (int j = 0; j < roomSize + 1; j++)
	// 	{
	// 		std:: cout << dynamic[i][j] << " ";
	// 	}
	// 	std:: cout  << std::endl;
	// }

	//std:: cout << "======================="<< std::endl;

	std:: cout << dynamic[roomSize][roomSize] << std::endl;
	
}