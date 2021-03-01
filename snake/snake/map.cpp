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
				cout << "�X";
			}
			if (i == kup && j == kleft+kwidth-1)
			{
				cunit::gotoxy(j, i);
				cout << "�[";
			}
			if (i == kup+kheight-1 && j == kleft)
			{
				cunit::gotoxy(j, i);
				cout << "�^";
			}
			if (i == kup+kheight-1 && j == kleft+kwidth-1)
			{
				cunit::gotoxy(j, i);
				cout << "�a";
			}
			if ((i == kup || i == kup+2 || i == kup+kheight-1)&&(j>kleft&&j<kleft+kwidth-1))
			{
				cunit::gotoxy(j, i);
				cout <<"�T";
			}
			if ((i > kup+2 && i < kup+kheight-1) && (j ==kleft || j == kwidth+kleft-1))
			{
				cunit::gotoxy(j, i);
				cout <<"�U";
			}
			if ((i == kup+1||i==kup+2) && (j == kleft || j == kwidth+kleft-1))
			{
				cunit::gotoxy(j, i);
				cout <<"�U";
			}
		}
		cout << endl;
	}
}
void map::drawgameinfo()
{
	cunit::gotoxy(kleft+1,kup+1);
	cout << "          " << "��Ϸ���ƣ�̰����" << "       " << "��д�ߣ�����" << "       " << "��ǰ�ķ֣�" << kscore << "       " << "��ǰ�ؿ���" << klevel;

}
void map::welcomegame()//��ӭ����
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
					cout << "�U";
				}
				if (i == up + 3 && j == 42)
				{
					cunit::gotoxy(j, i);
					cout << "�Ƿ������Ϸ:" <<"\t\t"<< "��Ϸ˵����";
				}
				if (i == up + 5 && j == 43)
				{
					cunit::gotoxy(j, i);
					cout << "��:1  ��:0"<<"\t   "<<"w:�� a:�� s:�� d:��";
				}
				if (i == up + 7 && j == 64)
				{
					cunit::gotoxy(j, i);
					cout << "��Ϸ����";
				}
				if (i == up + 9 && j == 59)
				{
					cunit::gotoxy(j, i);
					cout << "�Ե�ʳ��ӷ֣�����";
				}
				if (i == up + 11 && j == 60)
				{
					cunit::gotoxy(j, i);
					cout << "ײǽ����ײ���Լ���";
				}
				if (i == up + 7 && j == 44)
				{
					cunit::gotoxy(j, i);
					cout << "��ѡ��";
				}
				if (i == up + 7 && j == 48)
				{
					cunit::gotoxy(j, i);
				}
				if (i == up + 1 && j == 51)
				{
					cunit::gotoxy(j, i);
					cout << "��ӭ����̰������Ϸ";
				}
				if ((i == up || i == up + 2 || i == up + height - 1) && (j > left && j < left + width - 1))
				{
					cunit::gotoxy(j, i);
					cout << "�T";
				}
				if ((i > up + 2 && i < up + height - 1) && (j == left || j == left + width - 1))
				{
					cunit::gotoxy(j, i);
					cout << "�U";
				}
				if ((i == up + 1 || i == up + 2) && (j == left || j == left + width - 1))
				{
					cunit::gotoxy(j, i);
					cout << "�U";
				}
				if (i == up && j == left)
				{
					cunit::gotoxy(j, i);
					cout << "�X";
				}
				if (i == up && j == left + width - 1)
				{
					cunit::gotoxy(j, i);
					cout << "�[";
				}
				if (i == up + height - 1 && j == left)
				{
					cunit::gotoxy(j, i);
					cout << "�^";
				}
				if (i == up + height - 1 && j == left + width - 1)
				{
					cunit::gotoxy(j, i);
					cout << "�a";
				}
			}
			cout << endl;
		}
	}
}