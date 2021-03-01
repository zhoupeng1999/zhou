#pragma once
#include "cunit.h"
class food :
    public cunit
{
public:
    food(int x=0, int y=0, char pic = '*');
    ~food();
    void newfood();
};