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
	void gamearea();//ʧ�ܽ���
	void run();//��Ϸ����
	bool checkfailed();//�ж���Ϸ�Ƿ�ʧ��
	void changeinfo();//�ı���Ϸ�ؿ����ٶ�
	void gameinfo();//��Ϸ��Ϣ
	void setcursur();//���ù��Ϊ����
	void showscore();//��ӡ����
	void backgroundbgm();//��������
	static const int left = 40;//�������
	static const int up = 8;//��������
	static const int width = 30;//��
	static const int height = 10;//��
	int a;
	food* fd;
	snakes* snake;
	void gamedata();//����Ϸ����
	void gamedate();//����Ϸ����
};