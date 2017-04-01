#include "ent1position.h"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include <windows.h>

using namespace std;

extern double ent1distance;
extern double yent1;
extern double y;
extern double zent1;
extern double z;
extern double ent1yaw;
extern double xent1;
extern double x;
extern double yaw;
extern double abstemp1;
extern double abstemp2;
extern char *tempa;
extern char *tempb;
extern double pi;


ent1position::ent1position()//Calculations to a theoretical point relative to yourself
{
    ent1distance = sqrt(pow((yent1 - y),2) + pow((zent1 - z),2));//Calculates straight line distance to ent1
    //Test if zent - z is negative
    ent1yaw = atan((xent1 - x) / (zent1 - z)) + yaw;//Calculates the yaw to ent1

    abstemp1 = zent1 - z;//Used to check if the value is negative
    abstemp2 = xent1 - x;//Used to check if the value is negative

    if(abstemp1 != fabs(zent1 - z)){//Yaw: Z is negative
        if(abstemp2 != fabs(xent1 - x)){//Yaw: Z is negative and X is negative
            ent1yaw = (-1) * pi + ent1yaw;
        }
        else{//Yaw: Z is negative and X is positive
            ent1yaw = pi - ent1yaw * (-1);
        }
    }
    /*
    else{//Yaw: Z is positive
        if(abstemp2 != fabs(xent1 - x)){//Yaw: Z is positive and X is negative
            //entyaw = entyaw - entyaw * pi;
            tempa = "F";
            tempb = "L";
        }
        else{//Z is positive and on the right
            //entyaw = entyaw + entyaw * pi;
            tempa = "F";
            tempb = "R";
        }
    }*/
}

ent1position::~ent1position()
{
    //dtor
}
