#include<iostream>
#include"wall.h"
using namespace std;


void Wall::initWall() 
//��ʼ��ǽ�ڣ��ö�ά����
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			//��ǽ�ڵĵط�
			if (i == 0 || j == 0 || i == ROW - 1 || j == COL - 1)
			{
				gameArray[i][j] = '*';
			}
			//�ŵذ�ĵط�
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
			cout << "a:����";

		}
		else if (i == 9)
		{
			cout << "d:����";
		}
		else if (i == 10)
		{
			cout << "w:����";
		}
		else if (i == 11)
		{
			cout << "s:����";
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
