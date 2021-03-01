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
	setcursur();//隐藏光标
	map m;
	m.drawgamearea();
	m.drawgameinfo();
	fd->show();
	backgroundbgm();//背景音乐
	while (checkfailed())
	{
		snake->move();
		snake->snakeshow();
		snake->snakeerace();
		Sleep(snake->s_speed);
		if (snake->eating(fd))
		{
			snake->s_speed -= 30;
			gameinfo();//改变游戏信息：分数，关卡
			snake->group();//蛇长大
			fd->erace();//擦除食物
			fd->newfood();//重新生成食物
			fd->show();//显示食物
		}
	}
	gamedata();
	gamearea();//失败界面
	cunit::gotoxy(59, 16);
	cin >> a;
	if (a ==1)
	{
		system("cls");//清屏
		control b;
		b.run();
	}
	else if(a==0)
	{
		
	}
}
bool control::checkfailed()//判断游戏是否失败
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
void control::changeinfo()//改变游戏关卡，速度
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
void control::gameinfo()//游戏分数，关卡信息
{
	changeinfo();//改变游戏关卡信息
	map m;
	m.drawgameinfo();
}
void  control::setcursur()
{
	//设置光标不可见
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = sizeof(cci);
	cci.bVisible = FALSE;//假不可见   
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}
void control::showscore()//打印分数
{
	cout << "你的分数:" << map::kscore<<"    "<<"关卡："<<map::klevel<<endl;
}
void control::gamedata()//存游戏数据
{
	ofstream ofs;
	ofs.open("game.txt", ios::out);
	ofs <<"分数："<<map::kscore <<"     "<<"关卡"<< map::klevel << endl;
	ofs.close();
}
void control::gamedate()//读游戏数据
{
	ifstream ifs;
	ifs.open("game.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
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
	//while ((c = ifs.get()) != EOF)//EOF文件的尾部
	//{
	//	cout << c << endl;
	//}
}
void control::backgroundbgm()//背景音乐
{
	PlaySound(TEXT("D:\\music\\7874.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}
void control::gamearea()//游戏失败界面
{
	int i, j;
	for (i = up; i < up + height; i++)
	{
		for (j = left; j < left + width; j++)
		{
			if (i==up+5&&j==49)
			{
				cunit::gotoxy(j, i);
				cout << "是否继续游戏:";
			}
			if (i == up + 7 && j == 50)
			{
				cunit::gotoxy(j, i);
				cout << "是:1  否:0";
			}
			if (i == up + 8 && j == 52)
			{
				cunit::gotoxy(j, i);
				cout << "请选择：";
			}
			if (i == up + 1 && j == 51)
			{
				cunit::gotoxy(j, i);
				cout << "游戏失败";
			}
			if (i == up+3 && j == 45)
			{
				cunit::gotoxy(j,i);
				showscore();
			}
			if ((i == up || i == up + 2 || i == up + height - 1)&&(j>left&&j<left+width-1))
			{
				cunit::gotoxy(j, i);
				cout << "═";
			}
			if ((i > up + 2 && i < up + height - 1) && (j == left || j == left + width - 1))
			{
				cunit::gotoxy(j, i);
				cout << "║";
			}
			if ((i == up + 1||i==up+2) && (j == left || j == left + width - 1))
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
			if (i == up +height - 1 && j == left + width - 1)
			{
				cunit::gotoxy(j, i);
				cout << "╝";
			}
		}
		cout << endl;
	}
}