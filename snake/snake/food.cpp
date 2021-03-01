#include "food.h"
#include<time.h>
food::food(int x,int y,char pic)
{
	srand((unsigned)time(NULL));
	this->m_x = (rand()%(109-11+1))+11;
	this->m_y = (rand()%(31-5+1))+5;
	this->m_pic = pic;
}
food::~food()
{

}
void food::newfood()
{
	this->m_x = (rand() % (109 - 11 + 1)) + 11;
	this->m_y = (rand() % (31 - 5 + 1)) + 5;
}