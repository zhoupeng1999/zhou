#pragma once
#include<Windows.h>
class map
{
public:
    static const int kleft=10;//������ߵľ���
    static const int kup=3;//�����ϱߵľ���
    static const int kwidth=100;//��ͼ��
    static const int kheight=30;//��ͼ��
    static int kscore;//�÷�
    static int klevel;//�ؿ�
    void drawgamearea();//��ͼ
    void drawgameinfo();//��Ϸ��Ϣ
    void welcomegame();//��ӭ����
    static const int left = 40;//�������
    static const int up = 8;//��������
    static const int width = 40;//��
    static const int height = 15;//��
};

