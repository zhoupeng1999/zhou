#include "map.h"
#include<iostream>
#include"cunit.h"
using namespace std;
int map::kscore = 0;
int map::klevel = 1;
void map::drawgamearea()
{
	int i, j;
	for (i = kup; i < kheight+kup; i++)
	{
		
		for (j = kleft; j < kwidth+kleft; j++)
		{
			if (i == kup && j ==kleft)
			{
				cunit::gotoxy(j, i);
				cout << "╔";
			}
			if (i == kup && j == kleft+kwidth-1)
			{
				cunit::gotoxy(j, i);
				cout << "╗";
			}
			if (i == kup+kheight-1 && j == kleft)
			{
				cunit::gotoxy(j, i);
				cout << "╚";
			}
			if (i == kup+kheight-1 && j == kleft+kwidth-1)
			{
				cunit::gotoxy(j, i);
				cout << "╝";
			}
			if ((i == kup || i == kup+2 || i == kup+kheight-1)&&(j>kleft&&j<kleft+kwidth-1))
			{
				cunit::gotoxy(j, i);
				cout <<"═";
			}
			if ((i > kup+2 && i < kup+kheight-1) && (j ==kleft || j == kwidth+kleft-1))
			{
				cunit::gotoxy(j, i);
				cout <<"║";
			}
			if ((i == kup+1||i==kup+2) && (j == kleft || j == kwidth+kleft-1))
			{
				cunit::gotoxy(j, i);
				cout <<"║";
			}
		}
		cout << endl;
	}
}
void map::drawgameinfo()
{
	cunit::gotoxy(kleft+1,kup+1);
	cout << "          " << "游戏名称：贪吃蛇" << "       " << "编写者：周鹏" << "       " << "当前的分：" << kscore << "       " << "当前关卡：" << klevel;

}
void map::welcomegame()//欢迎界面
{
	{
		int i, j;
		for (i = up; i < up + height; i++)
		{
			for (j = left; j < left + width; j++)
			{
				if ((i>10&&i<24)&&j==57)
				{
					cunit::gotoxy(j, i);
					cout << "║";
				}
				if (i == up + 3 && j == 42)
				{
					cunit::gotoxy(j, i);
					cout << "是否进入游戏:" <<"\t\t"<< "游戏说明：";
				}
				if (i == up + 5 && j == 43)
				{
					cunit::gotoxy(j, i);
					cout << "是:1  否:0"<<"\t   "<<"w:上 a:左 s:下 d:右";
				}
				if (i == up + 7 && j == 64)
				{
					cunit::gotoxy(j, i);
					cout << "游戏规则：";
				}
				if (i == up + 9 && j == 59)
				{
					cunit::gotoxy(j, i);
					cout << "吃到食物加分，加速";
				}
				if (i == up + 11 && j == 60)
				{
					cunit::gotoxy(j, i);
					cout << "撞墙死，撞到自己死";
				}
				if (i == up + 7 && j == 44)
				{
					cunit::gotoxy(j, i);
					cout << "请选择：";
				}
				if (i == up + 7 && j == 48)
				{
					cunit::gotoxy(j, i);
				}
				if (i == up + 1 && j == 51)
				{
					cunit::gotoxy(j, i);
					cout << "欢迎来到贪吃蛇游戏";
				}
				if ((i == up || i == up + 2 || i == up + height - 1) && (j > left && j < left + width - 1))
				{
					cunit::gotoxy(j, i);
					cout << "═";
				}
				if ((i > up + 2 && i < up + height - 1) && (j == left || j == left + width - 1))
				{
					cunit::gotoxy(j, i);
					cout << "║";
				}
				if ((i == up + 1 || i == up + 2) && (j == left || j == left + width - 1))
				{
					cunit::gotoxy(j, i);
					cout << "║";
				}
				if (i == up && j == left)
				{
					cunit::gotoxy(j, i);
					cout << "╔";
				}
				if (i == up && j == left + width - 1)
				{
					cunit::gotoxy(j, i);
					cout << "╗";
				}
				if (i == up + height - 1 && j == left)
				{
					cunit::gotoxy(j, i);
					cout << "╚";
				}
				if (i == up + height - 1 && j == left + width - 1)
				{
					cunit::gotoxy(j, i);
					cout << "╝";
				}
			}
			cout << endl;
		}
	}
}