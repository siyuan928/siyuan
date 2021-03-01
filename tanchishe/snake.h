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
		//数据域
		int x;
		int y;

		//指针域
		Point* next;
	};
	//初始化结点
	void InitSnake();
	//销毁结点
	void destroyPoint();
	//添加结点
	void addPoint(int x, int y);
	//移动时删除结点
	void delPoint();
	//移动操作
	//返回值代表是否成功
	bool move(char key);
	//设定难度
	//获取刷屏时间
	int getSleepTime();
	int addSleepTime();
	//获取蛇的身段
	int countList();
	//获取分数
	int getScore();


	Point* pHead;

	Wall& wall;

	Food& food;

	bool isRool;//循环的标识
};
