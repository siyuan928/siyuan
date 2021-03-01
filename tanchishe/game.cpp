#include<iostream>
using namespace std;
#include"wall.h"
#include"snake.h"
#include"food.h"
#include<ctime>
#include<conio.h>
#include<Windows.h>
#include"game.h"

void show(int b);
void voice2();
char buf[500] = "";


//解决光标问题
void gotoxy(HANDLE hOut, int x, int y)
{
	COORD pos;
	pos.X = x; //横坐标
	pos.Y = y; //纵坐标
	SetConsoleCursorPosition(hOut, pos);
}
HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);//定义显示器句柄变量






void shuoming()
{

	int i;

	gotoxy(hOut, 50, 1);
	cout << "游戏说明" << endl;
	gotoxy(hOut, 25, 3);
	cout << "1.贪吃蛇的头部不能碰到墙壁和身体" << endl;
	gotoxy(hOut, 25, 4);
	cout << "2.刚开始中规中矩，慢慢增加自己的长度" << endl;
	gotoxy(hOut,25, 7);
	cout << "1.回到主界面：" << endl;

	gotoxy(hOut, 0, 23);
flag:
	cin >> i;
	switch (i)
	{
	case 1:
		system("cls");
		return;
		break;

	default:
		while (1)
		{
			system("cls");
			cout << "输入有误" << endl;
			goto flag;
		}
		break;






	}

}




void show(int b)
{


	while (1)
	{
		
		gotoxy(hOut, 50, 20);
		cout << "请输入选项" << endl;
		gotoxy(hOut, 50, 21);
		cout << "1 开始游戏\n" << endl;
		gotoxy(hOut, 50, 22);
		cout << "2 游戏说明\n" << endl;
		gotoxy(hOut, 35, 1);

		cout << "/^\\/^\\";      //蛇眼睛

		gotoxy(hOut, 34, 2);
		cout << "|★|  ★|";      //蛇眼睛

		gotoxy(hOut, 33, 2);
		cout << "_";

		gotoxy(hOut, 25, 3);
		cout << "\\/";      	//蛇信

		gotoxy(hOut, 31, 3);
		cout << "/";

		gotoxy(hOut, 37, 3);
		cout << " \\_/";     	//蛇眼睛

		gotoxy(hOut, 41, 3);
		cout << " \\";

		gotoxy(hOut, 26, 4);
		cout << "\\____";   	//舌头

		gotoxy(hOut, 32, 4);
		cout << "_________/";

		gotoxy(hOut, 31, 4);
		cout << "|";

		gotoxy(hOut, 43, 4);
		cout << "\\";

		gotoxy(hOut, 32, 5);
		cout << "\\_______";    //蛇嘴

		gotoxy(hOut, 44, 5);
		cout << "\\";

		gotoxy(hOut, 39, 6);
		cout << "|     |                  \\";  //下面都是画蛇身

		gotoxy(hOut, 38, 7);
		cout << "/      /                   \\";

		gotoxy(hOut, 37, 8);
		cout << "/      /                    \\ \\";

		gotoxy(hOut, 35, 9);
		cout << "/      /                       \\ \\";

		gotoxy(hOut, 34, 10);
		cout << "/     /                          \\  \\";

		gotoxy(hOut, 33, 11);
		cout << "/     /             _----_         \\   \\";

		gotoxy(hOut, 32, 12);
		cout << "/     /           _-~      ~-_         |  |";

		gotoxy(hOut, 31, 13);
		cout << "(      (        _-~    _--_    ~-_     _/  |";

		gotoxy(hOut, 32, 14);
		cout << "\\     ~-____-~    _-~    ~-_    ~-_-~    /";

		gotoxy(hOut, 33, 15);
		cout << "~-_           _-~          ~-_       _-~";

		gotoxy(hOut, 35, 16);
		cout << "~--______-~                ~-___-~";
		gotoxy(hOut, 50, 10);
		cout << "贪吃蛇" << endl;

		
		void voice();

		int n;
		gotoxy(hOut, 50, 25);
		cin >> n;

		switch (n)
		{

		case 1:
	
			system("cls");
			return;
			break;
		case 2:
			system("cls");
			shuoming();



		}

	}
}


void inputInfo()
{
	memset(buf, 0, 100);
	
	cout<<("请输入玩家名字:");
	cin >> buf;

}

void voice()
{



	FILE* fq = fopen("zhang.vbs", "w");
	inputInfo();
	if (fq != NULL)
	{
		fprintf(fq, "CreateObject(\"SAPI.Spvoice\").Speak\"%s，欢迎你来到贪吃蛇\"", buf);
		fclose(fq);
		system("zhang.vbs");
		system("del zhang.vbs");
		


	}
	
	fclose(fq);
	system("cls");


}


























int main()
{
	voice(); 

	show(1);











	//添加随机种子
	srand((unsigned int)time(NULL));

	//是否死亡的标识
	bool isDead = false;

	char preKey = NULL;
	Wall wall;
	wall.initWall();
	wall.drawWall();

	Food food(wall);
	food.setFood();

	Snake snake(wall, food);
	snake.InitSnake();



	gotoxy(hOut, 0, Wall::ROW);
	cout << "得分：" << snake.getScore() << "分" << endl;
	//gotoxy(hOut, 10, 5);//y*2 x 
	//接受用户的输入

	while (!isDead)
	{
		char key = _getch();

		//判断如果是第一次按了，左键，才不能激活游戏
		//判断上一次移动方向
		if (preKey == NULL && key == snake.LEFT)
		{
			continue;
		}


		do
		{
			if (key == snake.UP || key == snake.DOWN || key == snake.LEFT || key == snake.RIGHT)
			{
				//检测本次按键是否与上次冲突
				if ((key == snake.LEFT && preKey == snake.RIGHT) ||
					(key == snake.RIGHT && preKey == snake.LEFT) ||
					(key == snake.UP && preKey == snake.DOWN) ||
					(key == snake.DOWN && preKey == snake.UP)
					)
				{
					key = preKey;
				}
				else
				{
					preKey = key;//不是冲突按键，可以更新按键
				}

				if (snake.move(key) == true)
				{
					//移动成功
					//system("cls");
					//wall.drawWall();
					gotoxy(hOut, 0, Wall::ROW);

					cout << "得分：" << snake.getScore() << "分" << endl;
					Sleep(snake.getSleepTime());
				}
				else
				{
					isDead = true;
					break;
				}
			}
			else if (key == '1')
			{
				Sleep(1);
				
			}
			else if (key == '2')
			{
				return 0;

			}
			else
			{
				key = preKey;//强制将错误按键变为上一次移动的方向
			}

		} while (!_kbhit());//当没有键盘输入的时候返回0

	}





	system("pause");
	return 0;

}
