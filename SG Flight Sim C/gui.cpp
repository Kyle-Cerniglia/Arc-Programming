#include "gui.h"
#include "catalogcelestial.h"

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

using namespace std;

static int tempint = 0;

extern double entitylocation[8][1000];
extern double entitystat[8][1000];
extern double entityvelocity[24][1000];
extern char *milkyways;
extern char *pegasuss;
extern char *shiptype;
extern bool menupause;
extern char *special1;

static int temp = 0;

gui::gui()
{
    if(menupause == false){
        system("cls");
        while(temp < 66){//66
            printf(" ");
            temp++;
        }
        temp = 0;
        printf("Pitch: %0.2f", entityvelocity[1][0]);//9
        printf(" Yaw: %0.2f", entityvelocity[3][0]);//11
        printf(" Speed: %0.1f\n", entityvelocity[7][0]);//10-12?
        printf("Shield: %0.1f\n", entitystat[18][0]);
        printf("Hull: %0.1f\n", entitystat[16][0]);
        printf("Power: %0.1f\n", entitystat[22][0]);
        printf("\n");
        while(temp < 149){//149
            printf(" ");
            temp++;
        }
        temp = 0;
        printf("%s\n", shiptype);//>10?
        while(temp < 149){//149
            printf(" ");
            temp++;
        }
        temp = 0;
        if(entitylocation[1][0] = 1){
            printf("%s\n", milkyways);
        }
        while(temp < 149){//149
            printf(" ");
            temp++;
        }
        temp = 0;
        printf("Galactic coords:\n");//16
        while(temp < 149){//149
            printf(" ");
            temp++;
        }
        temp = 0;
        printf("(%0.1f", entitylocation[2][0]);
        printf(",%0.1f", entitylocation[3][0]);
        printf(",%0.1f", entitylocation[4][0]);
        printf(")\n");//>13
        while(temp < 149){//149
            printf(" ");
            temp++;
        }
        temp = 0;
        printf("Coords:\n");//7
        while(temp < 149){//149
            printf(" ");
            temp++;
        }
        temp = 0;
        printf("(%0.0f", entitylocation[5][0]);
        printf(",%0.0f", entitylocation[6][0]);
        printf(",%0.0f", entitylocation[7][0]);
        printf(")\n");
        //big vertical space, then module info
        while(temp < 25){
            printf("\n");
            temp++;
        }
        temp = 0;
    }
}

gui::~gui()
{
    //dtor
}
