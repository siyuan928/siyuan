#pragma once
#include<iostream>
#include"wall.h"
using namespace std;
#include"food.h"
class Snake
{
public:

	Snake(Wall& tempWall, Food& food);

	enum
	{
		UP = 'w',
		DOWN = 's',
		LEFT = 'a',
		RIGHT = 'd'
		
	};

	struct Point
	{
		//������
		int x;
		int y;

		//ָ����
		Point* next;
	};
	//��ʼ�����
	void InitSnake();
	//���ٽ��
	void destroyPoint();
	//��ӽ��
	void addPoint(int x, int y);
	//�ƶ�ʱɾ�����
	void delPoint();
	//�ƶ�����
	//����ֵ�����Ƿ�ɹ�
	bool move(char key);
	//�趨�Ѷ�
	//��ȡˢ��ʱ��
	int getSleepTime();
	int addSleepTime();
	//��ȡ�ߵ����
	int countList();
	//��ȡ����
	int getScore();


	Point* pHead;

	Wall& wall;

	Food& food;

	bool isRool;//ѭ���ı�ʶ
};
