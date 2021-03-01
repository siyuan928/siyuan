#include"snake.h"
#include"wall.h"
#include<Windows.h>


char buf1[500] = "";


void voice2()
{



	FILE* fq = fopen("zhang.vbs", "w");
	if (fq != NULL)
	{
		fprintf(fq, "CreateObject(\"SAPI.Spvoice\").Speak\"%s，很遗憾，游戏结束\"", buf1);
		fclose(fq);
		system("zhang.vbs");
		system("del zhang.vbs");


	}

	fclose(fq);


}




void gotoxy1(HANDLE hOut1, int x, int y)
{
	COORD pos;
	pos.X = x; //横坐标
	pos.Y = y; //纵坐标
	SetConsoleCursorPosition(hOut1, pos);
}
HANDLE hOut1 = GetStdHandle(STD_OUTPUT_HANDLE);//定义显示器句柄变量



void end()
{

	system("cls");
	cout << "游戏结束" << endl;
	voice2();
	int j;
	cout << "你的选择是" << endl;
	cin >> j;
	switch (j)
	{
	case 1:

		system("cls");
		return;


	}
}




Snake::Snake(Wall& tempWall, Food& tempFood) : wall(tempWall), food(tempFood)
{
	pHead = NULL;
	isRool = false;
}
void Snake::destroyPoint()
{
	Point* pCur = pHead;
	while (pHead != NULL)
	{
		pCur = pHead->next;
		delete pHead;
		pHead = pCur;
	}
}

void Snake::addPoint(int x, int y)
{
	//创建新结点
	Point* newpoint = new Point;
	newpoint->x = x;
	newpoint->y = y;
	newpoint->next = NULL;

	//如果原来头不为空，改为身子
	if (pHead != NULL)
	{
		wall.setWall(pHead->x, pHead->y, '=');

		gotoxy1(hOut1, pHead->y * 2, pHead->x);
		cout << "=";
	}

	newpoint->next = pHead;
	pHead = newpoint;//更新头部
	wall.setWall(pHead->x, pHead->y, '@');
	gotoxy1(hOut1, pHead->y * 2, pHead->x);
	cout << "@";

}

void Snake::InitSnake()
{
	destroyPoint();
	addPoint(5, 3);
	addPoint(5, 4);
	addPoint(5, 5);
}

//移动时删除结点
void Snake::delPoint()
{
	//两个以上结点 才去做删除操作
	if (pHead == NULL || pHead->next == NULL)
	{
		return;
	}
	//当前结点
	Point* pCur = pHead->next;
	//上一个结点
	Point* pPre = pHead;

	while (pCur->next != NULL)
	{
		pPre = pPre->next;
		pCur = pCur->next;
	}
	//删除尾结点
	wall.setWall(pCur->x, pCur->y, ' ');
	gotoxy1(hOut1, pCur->y * 2, pCur->x);
	cout << " ";
	delete pCur;

	pCur = NULL;
	pPre->next = NULL;
}

bool Snake::move(char key)
{
	int x = pHead->x;
	int y = pHead->y;

	
	switch (key)
	{
	case UP:
		x--;
		break;
	case DOWN:
		x++;
		break;
	case LEFT:
		y--;
		break;
	case RIGHT:
		y++;
		break;

	default:
			break;
	}
	
	
	
		
	








	//判断 如果下一步碰到的是尾巴，不应该死亡
	Point* pCur = pHead->next;
	//上一个结点
	Point* pPre = pHead;

	while (pCur->next != NULL)
	{
		pPre = pPre->next;
		pCur = pCur->next;
	}
	if (pCur->x == x && pCur->y == y)
	{
		//碰到尾巴的循环
		isRool = true;
	}
	else
	{
		//判断用户要到达的位置是否成功
		if (wall.getWall(x, y) == '*' || wall.getWall(x, y) == '=')
		{
			addPoint(x, y);
			delPoint();
			system("cls");
			wall.drawWall();
			cout << "得分：" << getScore() << "分" << endl;
			end();
			system("cls");

			return false;
		}
	}



	//移动成功 分两种
	//吃到食物，未吃到食物
	if (wall.getWall(x, y) == '#')
	{
		addPoint(x, y);

		//重新设置食物
		food.setFood();
	}
	else
	{
		addPoint(x, y);
		delPoint();

		//if (isRool == true)
		//{
		//	wall.setWall(x, y, '@');
		//	gotoxy1(hOut1, y * 2, x);
		//	cout << "@";
		//}

	}

	return true;
}


int Snake::getSleepTime()
{
	
	int sleepTime = 0;
	int size = countList();
	if (size < 5)
	{
		sleepTime = 300;
	}
	else if (size >= 5 && size <= 10)
	{
		sleepTime = 200;
	}
	else
	{
		sleepTime = 100;
	}
	return sleepTime;
}

int Snake::addSleepTime()
{
	int sleepTime1=0;
	//sleepTime1 += 100;
	return sleepTime1;

}

int Snake::countList()
{
	int size = 0;
	Point* curPoint = pHead;
	while (curPoint != NULL)
	{
		size++;
		curPoint = curPoint->next;
	}
	return size;
}

int Snake::getScore()
{
	int size = countList();
	int score = (size - 3) * 100;
	return score;
}
