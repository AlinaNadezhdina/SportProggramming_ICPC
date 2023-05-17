#include <iostream>
#include <vector>

void fillDynamicAndPrev(int *coins, int *dynamic, int *prevColumn, int columns, int step)
{
	dynamic[0] = 0;
	dynamic[1] = coins[1];
	prevColumn[0] = -1; // начальное значение как бы ниоткуда не прискакал
	prevColumn[1] = 0; //с какого столбика прискакал кузнечик

	int numMax = -1;
	int max = 0;
	for (size_t i = 2; i < columns; i++)
	{
		max = -1;
		int j = i > step ? i - step : 1;
		for ( ; j < i; j++) //нужно найти максимальное число от j до i не включая i
		{
			if (dynamic[j] > max)
			{
				max = dynamic[j];
				numMax = j;
			}
		}
		dynamic[i] = dynamic[numMax] + coins[i];
		prevColumn[i] = numMax;
	}
	// for (size_t i = 0; i < columns; i++)
	// 	std::cout << "dynamic[" << i << "] = "  << dynamic[i] << std::endl;
	// for (size_t i = 0; i < columns; i++)
	// 	std::cout << "prevColumn[" << i << "] = " << prevColumn[i] + 1 << std::endl;
}

void	makeAnswer(int *prevColumn, int columns)
{
	std::vector<int> res;
	res.push_back(0);
	for (size_t i = 1; i < columns; i++)
	{
		
		if (prevColumn[i] != res.back())
			res.push_back(prevColumn[i]);
	}
	res.push_back(columns - 1);
//std::cout << "======" << std::endl;
	std::cout << res.size() - 1 << std::endl;
//	std::cout << "======" << std::endl;
	std::vector<int>::iterator it = res.begin();
	for (; it != res.end();it++)
	{
		std::cout << *it + 1 << " ";
	}
	std::cout << std::endl;
//	std::cout << "======" << std::endl;
	
}

int main()
{
	int columns, step;
	std::cin >> columns >> step;
	int *coins = new int[columns];
	coins[0] = coins[columns - 1] = 0;
	for (size_t i = 1; i < columns - 1; i++)
	{
		std::cin >> coins[i];
	}
	int *dynamic = new int[columns];
	int *prevColumn = new int[columns];

	fillDynamicAndPrev(coins, dynamic, prevColumn, columns, step);
//	std::cout << "======" << std::endl;
	std::cout << dynamic[columns - 1] << std::endl;
	makeAnswer(prevColumn, columns);
}

/*Входные данные
5 3				
2 -3 5
Выходные данные	
7
3
1 2 4 5*/