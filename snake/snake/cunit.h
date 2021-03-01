#pragma once
#include<iostream>
#include<Windows.h>
using namespace std;
class cunit
{
public:
	cunit(int x = 0, int y = 0, char pic = '*');
	~cunit();
	void show();
	void erace();
	static void gotoxy(int x, int y);//光标定位函数
	int m_x;
	int m_y;
	char m_pic;
};