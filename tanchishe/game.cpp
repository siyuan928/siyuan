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


//����������
void gotoxy(HANDLE hOut, int x, int y)
{
	COORD pos;
	pos.X = x; //������
	pos.Y = y; //������
	SetConsoleCursorPosition(hOut, pos);
}
HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);//������ʾ���������






void shuoming()
{

	int i;

	gotoxy(hOut, 50, 1);
	cout << "��Ϸ˵��" << endl;
	gotoxy(hOut, 25, 3);
	cout << "1.̰���ߵ�ͷ����������ǽ�ں�����" << endl;
	gotoxy(hOut, 25, 4);
	cout << "2.�տ�ʼ�й��оأ����������Լ��ĳ���" << endl;
	gotoxy(hOut,25, 7);
	cout << "1.�ص������棺" << endl;

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
			cout << "��������" << endl;
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
		cout << "������ѡ��" << endl;
		gotoxy(hOut, 50, 21);
		cout << "1 ��ʼ��Ϸ\n" << endl;
		gotoxy(hOut, 50, 22);
		cout << "2 ��Ϸ˵��\n" << endl;
		gotoxy(hOut, 35, 1);

		cout << "/^\\/^\\";      //���۾�

		gotoxy(hOut, 34, 2);
		cout << "|��|  ��|";      //���۾�

		gotoxy(hOut, 33, 2);
		cout << "_";

		gotoxy(hOut, 25, 3);
		cout << "\\/";      	//����

		gotoxy(hOut, 31, 3);
		cout << "/";

		gotoxy(hOut, 37, 3);
		cout << " \\_/";     	//���۾�

		gotoxy(hOut, 41, 3);
		cout << " \\";

		gotoxy(hOut, 26, 4);
		cout << "\\____";   	//��ͷ

		gotoxy(hOut, 32, 4);
		cout << "_________/";

		gotoxy(hOut, 31, 4);
		cout << "|";

		gotoxy(hOut, 43, 4);
		cout << "\\";

		gotoxy(hOut, 32, 5);
		cout << "\\_______";    //����

		gotoxy(hOut, 44, 5);
		cout << "\\";

		gotoxy(hOut, 39, 6);
		cout << "|     |                  \\";  //���涼�ǻ�����

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
		cout << "̰����" << endl;

		
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
	
	cout<<("�������������:");
	cin >> buf;

}

void voice()
{



	FILE* fq = fopen("zhang.vbs", "w");
	inputInfo();
	if (fq != NULL)
	{
		fprintf(fq, "CreateObject(\"SAPI.Spvoice\").Speak\"%s����ӭ������̰����\"", buf);
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











	//����������
	srand((unsigned int)time(NULL));

	//�Ƿ������ı�ʶ
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
	cout << "�÷֣�" << snake.getScore() << "��" << endl;
	//gotoxy(hOut, 10, 5);//y*2 x 
	//�����û�������

	while (!isDead)
	{
		char key = _getch();

		//�ж�����ǵ�һ�ΰ��ˣ�������Ų��ܼ�����Ϸ
		//�ж���һ���ƶ�����
		if (preKey == NULL && key == snake.LEFT)
		{
			continue;
		}


		do
		{
			if (key == snake.UP || key == snake.DOWN || key == snake.LEFT || key == snake.RIGHT)
			{
				//��Ȿ�ΰ����Ƿ����ϴγ�ͻ
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
					preKey = key;//���ǳ�ͻ���������Ը��°���
				}

				if (snake.move(key) == true)
				{
					//�ƶ��ɹ�
					//system("cls");
					//wall.drawWall();
					gotoxy(hOut, 0, Wall::ROW);

					cout << "�÷֣�" << snake.getScore() << "��" << endl;
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
				key = preKey;//ǿ�ƽ����󰴼���Ϊ��һ���ƶ��ķ���
			}

		} while (!_kbhit());//��û�м��������ʱ�򷵻�0

	}





	system("pause");
	return 0;

}
