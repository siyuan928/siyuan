#include"food.h"
#include<Windows.h>

void gotoxy2(HANDLE hOut2, int x, int y)
{
	COORD pos;
	pos.X = x; //������
	pos.Y = y; //������
	SetConsoleCursorPosition(hOut2, pos);
}
HANDLE hOut2 = GetStdHandle(STD_OUTPUT_HANDLE);//������ʾ���������

Food::Food(Wall& tempwall) :wall(tempwall)
{

}

void Food::setFood()
{

	while (true)
	{
		FoodX = rand() % (Wall::ROW - 2) + 1;
		FoodY = rand() % (Wall::COL - 2) + 1;
		//��������λ������ͷ���������������������
		if (wall.getWall(FoodX, FoodY) == ' ')
		{
			wall.setWall(FoodX, FoodY, '#');
			gotoxy2(hOut2, FoodY * 2, FoodX);
			cout << '#';
			break;
		}

	}

}
