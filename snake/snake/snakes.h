#pragma once
#include"food.h"
#include<vector>
enum directions{ sup, sdown, sleft, sright };
class snakes
{
public:
    snakes(int x=40,int y=10,int length=4,int speed=300,directions dir=sright,char pic='*');
    ~snakes();
    void snakeshow();//��ʾ��
    bool eating(food *fd);//��ʳ��
    void snakeerace();//����
    void move();//���ƶ�
    void group();//�߳���
    int s_x;
    int s_y;
    int s_length;
    int s_speed;
    char s_pic;
    directions dirs;
    char key = 'd';
    vector<cunit>s_vec;
    int kx, ky, lastX, lastY;
};

