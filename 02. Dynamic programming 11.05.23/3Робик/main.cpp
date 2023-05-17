#include <iostream>

//Алгори́тм волново́й трассиро́вки (волновой алгоритм, алгоритм Ли)
int main()
{
	int roomSize;
	std::cin >> roomSize;
	int blanc = -2;
	int wall =  -1;
	int **data = new int *[roomSize + 2];
	for (int i = 0; i < roomSize + 2; i++)
	{
		data[i] = new int[roomSize + 2];
		for (int j = 0; j < roomSize + 2; j++)
		{
			if (j == 0 || j == roomSize + 1 || i == 0 || i == roomSize + 1)
				data[i][j] = -1;
			else
			{
				int t;
				std::cin >> t;
				if (t == 1)
					data[i][j] = -1;
				else if (t == 0)
					data[i][j] = -2;
			}
		}
	}
	int ax, ay, bx, by;// x1 - стоблец, y1 - строка
  	std::cin >> ax >> ay >> bx >> by;
	if (data[ay][ax] == -1 || data[by][bx] == -1)
	{  
		std::cout << "0" << std::endl;
		return (0);
	}
	int dx[4] = {1, 0, -1, 0};   // смещения, соответствующие соседям ячейки
	int dy[4] = {0, 1, 0, -1};   // справа, снизу, слева и сверху
	int d;
	bool stop = false;
	d = 0;
  	data[ay][ax] = 0; 
	while (data[by][bx] == blanc && stop == false)
	{
		stop = true;
		for (int y = 0; y < roomSize + 2; y++)
		{
			for (int x = 0; x < roomSize + 2; x++)
			{
				if (data[y][x] == d)
				{
					for (int k = 0; k < 4; k++)
					{
						int iy = y + dy[k];
						int ix = x + dx[k];
						if (iy >= 0 && iy < roomSize + 2 && ix >= 0 && ix < roomSize + 2 && data[iy][ix] == blanc)
						{
							data[iy][ix] = d + 1;
							stop = false;
						}
					}
				}
			}
		}
		d++;
	}
	if (data[by][bx] == blanc)
	{	
		std::cout << "0" << std::endl;
		return (0);
	}
	std::cout << data[by][bx] << std::endl; 
}