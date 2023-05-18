#include <iostream>
#include <algorithm>


typedef struct s_shop
{
	int pricePerMetr;//цена за метр ткани
	int countMateria;//количество метров в магазине, которое можно купить без скидки
	int salePrice;//цена со скидкой при покупке от countMateria ткани
	int maxMateriaPerShop;// максимальное количество ткани в магазине
}t_shop;

int main()
{
	int shopCount, totalMaterials;//количество магазинов и количество метров ткани
	std::cin >> shopCount >> totalMaterials;

	t_shop *shops= new t_shop[shopCount];
	for (int i = 0; i < shopCount; i++)
	{
		std::cin >> shops[i].pricePerMetr >> shops[i].countMateria >> shops[i].salePrice >> shops[i].maxMateriaPerShop;
	}

	int **dynamic = new int *[shopCount + 1];
	int cost = 0;
	for (int i = 0; i < shopCount + 1; i++)
	{
		dynamic[i] = new int[totalMaterials + 1];
		for (int j = 0; j < totalMaterials + 1; j++)
		{
			if (i == 0 || j == 0)
			{
				dynamic[i][j] = 10000;
			}
			else
			{
				if (j <= shops[i - 1].maxMateriaPerShop) 
				{
					if (j < shops[i - 1].countMateria)
					{
						cost = j * shops[i - 1].pricePerMetr;
					}
					else
					{
						cost = j * shops[i - 1].salePrice;
					}
				}
				else // расчет стоимости ткани после "выхода" за максимальное кол-во ткани в магазине
					cost = dynamic[i][shops[i - 1].maxMateriaPerShop] + dynamic[i - 1][j - shops[i - 1].maxMateriaPerShop];

				//dynamic[i][j] = std::min(dynamic[i - 1][j], cost);
			}
		//	std::cout << dynamic[i][j] << " ";
		}
		std::cout << std::endl;
	}
	if (dynamic[shopCount][totalMaterials] >= 10000)
		std::cout << -1 << std::endl;
	else
		std::cout << dynamic[shopCount][totalMaterials]<< std::endl;
	return (0);
}