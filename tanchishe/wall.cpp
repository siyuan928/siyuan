#include<iostream>
#include"wall.h"
using namespace std;


void Wall::initWall() 
//初始化墙壁，用二维数组
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			//放墙壁的地方
			if (i == 0 || j == 0 || i == ROW - 1 || j == COL - 1)
			{
				gameArray[i][j] = '*';
			}
			//放地板的地方
			else
			{
				gameArray[i][j] = ' ';
			}
		}
	}
}

void Wall::drawWall()
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{

			cout << gameArray[i][j];
		}


		if (i == 8)
		{
			cout << "a:向左";

		}
		else if (i == 9)
		{
			cout << "d:向右";
		}
		else if (i == 10)
		{
			cout << "w:向上";
		}
		else if (i == 11)
		{
			cout << "s:向下";
		}
		cout << endl;
	}
}

void Wall::setWall(int x, int y, char c)
{
	gameArray[x][y] = c;
}

char Wall::getWall(int x, int y)
{
	return gameArray[x][y];
}
