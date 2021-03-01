#pragma once
#include"food.h"
#include<vector>
enum directions{ sup, sdown, sleft, sright };
class snakes
{
public:
    snakes(int x=40,int y=10,int length=4,int speed=300,directions dir=sright,char pic='*');
    ~snakes();
    void snakeshow();//显示蛇
    bool eating(food *fd);//吃食物
    void snakeerace();//擦除
    void move();//蛇移动
    void group();//蛇长大
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

