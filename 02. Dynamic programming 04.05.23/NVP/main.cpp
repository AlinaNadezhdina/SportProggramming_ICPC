#include <iostream>
#include <vector>

void calculateResult(int *numbers, int *last, int maxIndx)
{
	std::vector<int> res;
	res.push_back(numbers[maxIndx]);
	while(last[maxIndx] != -1)
	{
		res.push_back(numbers[last[maxIndx]]);
		maxIndx = last[maxIndx];
	}
	std::vector<int>::iterator it = res.end();
	for (int i = res.size() - 1; i >= 0; i--)
	{
		std::cout << res[i] << " ";
	}
	std::cout << std::endl;
	std::cout << res.size() << std::endl;
}

void calculateMaxNVP(int *numbers, int *dynamic, int count, int *last)
{
	dynamic[0] = 1;
	last[0] =  -1;
	int max;
	for (int i = 1; i < count; i++)
	{
		max = 0;
		last[i] = -1;
		for (int k = i - 1; k >= 0; k--)
		{
			if (dynamic[k] > max && numbers[k] < numbers[i])
			{
				max = dynamic[k];
				last[i] = k;
			}
		}
		dynamic[i] = max + 1;	
	}
	max = 0;
	int maxIndx = 0;
	for (int i = 0; i < count; i++)
	{
		if (dynamic[i] > max)
		{
			max = dynamic[i];
			maxIndx = i;
		}
	}
	// сборка результата
	calculateResult(numbers, last, maxIndx);
}


//Наибольшая возрастающая последовательность
int main()
{
	int count;
	std::cin >> count;
	int *numbers = new int[count];
	for (int i = 0; i < count; i++)
	{
		std::cin >> numbers[i];
	}
	int *dynamic = new int[count];
	int *last = new int[count];
	calculateMaxNVP(numbers, dynamic, count, last);
}

/*
Входные данные1	
7
1 4 2 5 6 3 7
Выходные данные1	
1 2 5 6 7
5
Входные данные2
5
7 5 4 2 1
Выходные данные2
7
1
*/