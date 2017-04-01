#include "console.h"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>

using namespace std;

extern char *console1;
extern double xent1;
extern double yent1;
extern double zent1;
extern double ent1distance;
extern double ent1yaw;
extern double ent1pitch;
extern double pitchspeed;
extern double truespeed;
extern bool menupause;
extern double entityvelocity[8][1000];
extern double entitylocation[8][1000];

console::console()//Displays system information
{
    if(menupause == false){
        system("cls");
        printf("Console: %s\n", console1);
        printf("Pitch: %f\n", entityvelocity[1][0]);
        printf("Yaw: %f\n", entityvelocity[3][0]);
        printf("X: %f\n", entitylocation[5][0]);
        printf("Y: %f\n", entitylocation[6][0]);
        printf("Z: %f\n", entitylocation[7][0]);
        printf("\n");
        /*
        printf("Entity 1:\n");
        printf("X: %f\n", xent1);
        printf("Y: %f\n", yent1);
        printf("Z: %f\n", zent1);
        printf("Distance: %f\n", ent1distance);
        printf("Yaw diff: %f\n", ent1yaw);
        printf("Pitch diff: %f\n", ent1pitch);
        printf("\n");
        printf("xent1 - x: %f\n", xent1 - x);
        printf("zent1 - z: %f\n", zent1 - z);
        printf("\n");
        */
        printf("xspeed: %f\n", entityvelocity[5][0]);
        printf("yspeed: %f\n", entityvelocity[6][0]);
        printf("zspeed: %f\n", entityvelocity[7][0]);
        printf("pitchspeed: %f\n", entityvelocity[2][0]);
        //printf("Truespeed: %f\n", truespeed);
        //printf("Rotationspeedaccel: %f\n", entityinfo[44][0]);
    }

}

console::~console()
{
    //dtor
}
