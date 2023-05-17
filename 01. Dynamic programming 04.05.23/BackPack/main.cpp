#include <iostream>
#include <algorithm>

typedef struct s_item
{
	int weight;//вес предмета в рюкзаке
	int price;//стоимость предмета
}t_item;


int main()
{
	int itemCount, weight;
	std::cin >> itemCount >> weight;

	t_item *items = new t_item[itemCount];
	for (int i = 0; i < itemCount; i++)
		std::cin >> items[i].weight;
	for (int i = 0; i < itemCount; i++)
		std::cin >> items[i].price;

	int **dynamic = new int *[itemCount + 1];
	for (int i = 0; i < itemCount + 1; i++)
	{
		dynamic[i] = new int[weight + 1];
		for (int j = 0; j < weight + 1; j++)
		{
			if (i == 0 || j == 0)
			{
				dynamic[i][j] = 0;
			}
			else
			{	//если текущий размер рюкзака больше или равен размеру текущего предмета
				if (j >= items[i - 1].weight)
				{
					//dynamic[i - 1][j] - стоимость без учета i-го предмета
					dynamic[i][j] = std::max(dynamic[i - 1][j], dynamic[i - 1][j - items[i - 1].weight] + items[i - 1].price);
				}
				else //стоимость рюкзака без этого предмета
				{
					dynamic[i][j] = dynamic[i - 1][j];
				}
			}
		}
	}

	std:: cout << dynamic[itemCount][weight] << std::endl;
}
