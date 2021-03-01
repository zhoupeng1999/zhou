#pragma once
#include<Windows.h>
class map
{
public:
    static const int kleft=10;//隔开左边的距离
    static const int kup=3;//隔开上边的距离
    static const int kwidth=100;//地图宽
    static const int kheight=30;//地图长
    static int kscore;//得分
    static int klevel;//关卡
    void drawgamearea();//地图
    void drawgameinfo();//游戏信息
    void welcomegame();//欢迎界面
    static const int left = 40;//隔开左边
    static const int up = 8;//隔开上面
    static const int width = 40;//宽
    static const int height = 15;//长
};

