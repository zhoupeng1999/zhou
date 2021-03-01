#pragma once
#include"cunit.h"
#include"food.h"
#include"snakes.h"
#include"map.h"
#include<Windows.h>
#include<fstream>
#include<mmsystem.h>
#include<string>
#pragma comment(lib,"winmm.lib")
class control
{
public:
	control();
	~control();
	void gamearea();//失败界面
	void run();//游戏运行
	bool checkfailed();//判断游戏是否失败
	void changeinfo();//改变游戏关卡，速度
	void gameinfo();//游戏信息
	void setcursur();//设置光标为隐藏
	void showscore();//打印分数
	void backgroundbgm();//背景音乐
	static const int left = 40;//隔开左边
	static const int up = 8;//隔开上面
	static const int width = 30;//宽
	static const int height = 10;//长
	int a;
	food* fd;
	snakes* snake;
	void gamedata();//存游戏数据
	void gamedate();//读游戏数据
};