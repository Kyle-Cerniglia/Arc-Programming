#include "railsmentity.h"
#include "weaponfire.h"

#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

extern int railsmentityv[7][100];//[0]existance, [1]x, [2]y, [3]z, [4]pitch, [5]yaw, [6]truespeed, [7]maxspeed

railsmentity::railsmentity()
{
    printf("%d\n", railsmentityv[0][0]);
}

railsmentity::~railsmentity()
{
    //dtor
}
