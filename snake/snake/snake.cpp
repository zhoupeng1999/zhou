#include <iostream>
#include "cunit.h"
#include"food.h"
#include"map.h"
#include"snakes.h"
#include"control.h"
using namespace std;
int main()
{
    map p;
    p.welcomegame();
    int a;
    cunit::gotoxy(51,15);
    cin >> a;
    if (a == 1)//是否进入游戏
    {
        system("cls");
        control c;
        c.run();
    }
    else
    {
        system("cls");
    }
    cunit::gotoxy(0, 35);
    return 0;
}