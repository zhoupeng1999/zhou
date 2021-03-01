#include "cunit.h"
cunit::cunit(int x, int y, char pic)
{
	m_x = x;
	m_y = y;
	m_pic = pic;
}
cunit::~cunit()
{

}
void cunit::show()
{
	gotoxy(m_x,m_y);
	cout << m_pic;
}
void cunit::erace()
{
	gotoxy(m_x, m_y);
	cout << " ";
}
void cunit::gotoxy(int  x, int  y)
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
