#include "raycasting1.h"
#include "ent1position.h"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include <windows.h>

using namespace std;

extern double xraymin;
extern double ent1yaw;
extern double ent1hitbox;
extern double ent1distance;
extern double xraymax;
extern double yaw;
extern double ent1pitch;
extern double yraymin;
extern double yraymax;
extern double pi;
extern char *console1;
extern double pitch;


raycasting1::raycasting1()//Casts a ray from your front outward with hitbox detection on the target
{
    xraymin = ent1yaw - atan(ent1hitbox / ent1distance);
    xraymax = ent1yaw + atan(ent1hitbox / ent1distance);
    if(yaw > xraymin && yaw < xraymax){//Yaw check
        //console1 = "Hit";
        yraymin = ent1pitch - atan(ent1hitbox / ent1distance);
        yraymax = ent1pitch + atan(ent1hitbox / ent1distance);
        if(pitch > yraymin && pitch < yraymax){//Pitch check
            if((yaw >= (-1) * pi / 2 && ent1yaw >= (-1) * pi / 2) && (yaw <= pi / 2 && ent1yaw <= pi / 2)){//Yaw positive direction check
                console1 = "Hit";
            }
            else{//Yaw positive direction check
                if((yaw <= (-1) * pi / 2 && ent1yaw <= (-1) * pi / 2) && (yaw >= pi / 2 && ent1yaw >= pi / 2)){//Yaw negative direction check
                    console1 = "Hit";
                }
                else{//Yaw negative direction check
                    console1 = "Miss";
                }
            }
        }
        else{//Pitch check
            console1 = "Miss";
        }
    }
    else{//Yaw check
        console1 = "Miss";
    }
}

raycasting1::~raycasting1()
{
    //dtor
}
