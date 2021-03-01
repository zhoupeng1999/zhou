#include "control.h"
#include<iostream>
#include<conio.h>
#include"cunit.h"
control::control()
{
	fd = new food;
	snake = new snakes;
}
control::~control()
{
	if (fd != NULL)
	{
		delete fd;
	}
	else fd = NULL;
	
	if (snake != NULL)
	{
		delete snake;
	}
	else snake = NULL;
}
void control::run()
{
	setcursur();//���ع��
	map m;
	m.drawgamearea();
	m.drawgameinfo();
	fd->show();
	backgroundbgm();//��������
	while (checkfailed())
	{
		snake->move();
		snake->snakeshow();
		snake->snakeerace();
		Sleep(snake->s_speed);
		if (snake->eating(fd))
		{
			snake->s_speed -= 30;
			gameinfo();//�ı���Ϸ��Ϣ���������ؿ�
			snake->group();//�߳���
			fd->erace();//����ʳ��
			fd->newfood();//��������ʳ��
			fd->show();//��ʾʳ��
		}
	}
	gamedata();
	gamearea();//ʧ�ܽ���
	cunit::gotoxy(59, 16);
	cin >> a;
	if (a ==1)
	{
		system("cls");//����
		control b;
		b.run();
	}
	else if(a==0)
	{
		
	}
}
bool control::checkfailed()//�ж���Ϸ�Ƿ�ʧ��
{
	if (snake->s_vec[0].m_x > map::kleft && snake->s_vec[0].m_x<(map::kleft + map::kwidth-1) && snake->s_vec[0].m_y>map::kup+2 && snake->s_vec[0].m_y < (map::kup + map::kheight-1))
	{
		for (int i = 1; i < snake->s_length; i++)
		{
			if (snake->s_vec[0].m_x == snake->s_vec[i].m_x && snake->s_vec[0].m_y == snake->s_vec[i].m_y)
			{
				return false;
			}
		}
		return true;
	}
	else
	{
		return false;
	}
}
void control::changeinfo()//�ı���Ϸ�ؿ����ٶ�
{
	if (map::kscore > 30 && map::kscore < 60)
	{
		map::klevel = 2;
	}
	else if (map::kscore >=60 && map::kscore < 90)
	{
		map::klevel = 3;
	}
	else if (map::kscore >=90 && map::kscore < 120)
	{
		map::klevel = 4;
	}
	else if (map::kscore >= 120 && map::kscore < 150)
	{
		map::klevel = 5;
	}
}
void control::gameinfo()//��Ϸ�������ؿ���Ϣ
{
	changeinfo();//�ı���Ϸ�ؿ���Ϣ
	map m;
	m.drawgameinfo();
}
void  control::setcursur()
{
	//���ù�겻�ɼ�
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = sizeof(cci);
	cci.bVisible = FALSE;//�ٲ��ɼ�   
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}
void control::showscore()//��ӡ����
{
	cout << "��ķ���:" << map::kscore<<"    "<<"�ؿ���"<<map::klevel<<endl;
}
void control::gamedata()//����Ϸ����
{
	ofstream ofs;
	ofs.open("game.txt", ios::out);
	ofs <<"������"<<map::kscore <<"     "<<"�ؿ�"<< map::klevel << endl;
	ofs.close();
}
void control::gamedate()//����Ϸ����
{
	ifstream ifs;
	ifs.open("game.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
	}
	//char date[1024] = { 0 };
	//while (ifs >> date)
	//{
	//	cout << date << endl;
	//}
	//while (ifs.getline(date, sizeof(date)))
	//{
	//	cout << date << endl;
	//}
	string date;
	while (getline(ifs, date))
	{
		cout << date << endl;
	}
	//char c;
	//while ((c = ifs.get()) != EOF)//EOF�ļ���β��
	//{
	//	cout << c << endl;
	//}
}
void control::backgroundbgm()//��������
{
	PlaySound(TEXT("D:\\music\\7874.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}
void control::gamearea()//��Ϸʧ�ܽ���
{
	int i, j;
	for (i = up; i < up + height; i++)
	{
		for (j = left; j < left + width; j++)
		{
			if (i==up+5&&j==49)
			{
				cunit::gotoxy(j, i);
				cout << "�Ƿ������Ϸ:";
			}
			if (i == up + 7 && j == 50)
			{
				cunit::gotoxy(j, i);
				cout << "��:1  ��:0";
			}
			if (i == up + 8 && j == 52)
			{
				cunit::gotoxy(j, i);
				cout << "��ѡ��";
			}
			if (i == up + 1 && j == 51)
			{
				cunit::gotoxy(j, i);
				cout << "��Ϸʧ��";
			}
			if (i == up+3 && j == 45)
			{
				cunit::gotoxy(j,i);
				showscore();
			}
			if ((i == up || i == up + 2 || i == up + height - 1)&&(j>left&&j<left+width-1))
			{
				cunit::gotoxy(j, i);
				cout << "�T";
			}
			if ((i > up + 2 && i < up + height - 1) && (j == left || j == left + width - 1))
			{
				cunit::gotoxy(j, i);
				cout << "�U";
			}
			if ((i == up + 1||i==up+2) && (j == left || j == left + width - 1))
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
			if (i == up +height - 1 && j == left + width - 1)
			{
				cunit::gotoxy(j, i);
				cout << "�a";
			}
		}
		cout << endl;
	}
}