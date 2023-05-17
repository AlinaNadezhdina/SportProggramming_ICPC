#include <iostream>


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
		std::cin >> shops[i].pricePerMetr >> shops[i].countMateria >> shops[i].salePrice >> shops->maxMateriaPerShop;
	}
	

}