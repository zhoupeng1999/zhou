#include "snakes.h"
#include"control.h"
#include<conio.h>
#include"map.h"
snakes::snakes(int x, int y, int length , int speed ,directions dir, char pic )
{
	this->s_x = x;
	this->s_y = y;
	this->s_length = length;
	this->s_speed = speed;
	this->dirs = dir;
	this->s_pic = pic;
	for (int i = 0; i < length; i++)
	{
		cunit c;
		if (i == 0)
		{
			c.m_x = s_x;
			c.m_y = s_y;
			s_vec.push_back(c);
		}
		else
		{
			c.m_x = s_x - i;
			c.m_y = s_y;
			s_vec.push_back(c);
		}
	}
}

snakes::~snakes()
{
	//todo
}

void snakes::move()//���ƶ�
{
	//�����û��������� asdw  _kbhit()�������ж��û����� _getch()�����û�����
	if (_kbhit())  //������ ������ 
	{
		key = _getch();
	}
	switch (key)
	{
	case'w': if (dirs != sdown) { kx = 0; ky = -1; dirs = sup; }; break;
	case'a': if (dirs != sright) { kx = -1; ky = 0; dirs = sleft; };  break;
	case's': if (dirs != sup) { kx = 0; ky = 1; dirs = sdown; };  break;
	case'd': if (dirs != sleft) { kx = 1; ky = 0; dirs = sright; };  break;

	default:break;
	}
	//��¼��β����
	lastX = s_vec[s_length - 1].m_x;
	lastY = s_vec[s_length - 1].m_y;
	//���ƶ� ǰһ���������һ�����帳ֵ
	for (int i = s_length - 1; i > 0; i--)
	{
		s_vec[i].m_x = s_vec[i - 1].m_x;
		s_vec[i].m_y = s_vec[i - 1].m_y;
	}
	//��ͷ�ƶ� ����
	s_vec[0].m_x += kx;
	s_vec[0].m_y += ky;
}
bool  snakes::eating(food *fd) //ʳ��
{
	if (s_vec[0].m_x == fd->m_x && s_vec[0].m_y == fd->m_y)
	{
		//�ӷ�
		map::kscore += 5;
		return TRUE;
	}
	else
	{
		return FALSE;
	}

}
void snakes::snakeshow()//����
{
	for (int i = 0; i < s_length; i++)
	{
		cunit::gotoxy(s_vec[i].m_x, s_vec[i].m_y);
		if (i == 0)
		{
			putchar('@');
		}
		else
		{
			putchar('o');
		}
	}

}
void snakes::snakeerace()
{
	cunit::gotoxy(lastX, lastY);//��β����
	cout << " ";
}
void snakes::group()//������
{
	cunit c;
	c.m_x = lastX;
	c.m_y = lastY;
	s_vec.push_back(c);
	s_length++;
}

