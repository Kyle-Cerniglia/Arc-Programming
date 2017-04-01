#include "hyperdrive.h"
#include "main.h"

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

using namespace std;

static int hypx = 0;       //Hyperdrive destination coordinate X
static int hypy = 0;       //Hyperdrive destination coordinate Y
static int hypz = 0;       //Hyperdrive destination coordinate Z
double tempx = 0;
double tempy = 0;
double tempz = 0;
double temphypo = 0;
double hyperdrivedistance = 0;
double hyperdrivetime = 0;
double hyperdrivetimeinitial = 0;
int tempin = 0;
double thetaxz = 0;
double thetay = 0;
int distancecount;
double galxinitial = 0;
double galyinitial = 0;
double galzinitial = 0;
double xin = 0;
double yin = 0;
double zin = 0;

extern double entitylocation[8][1000];
extern double entitymodule[13][1000];
extern double entitystat[24][1000];
extern double timewait;
extern double pi;
extern double massenergy;
extern bool D;
extern bool locreset;
extern bool menupause;

static int input = 0;

hyperdrive::hyperdrive()//Hyperdrive control
{
    system("cls");
    printf("1: Interstellar Hyperdrive\n");
    printf("2: Intrastellar Hyperdrive\n");

    input = getch();
    system("cls");
    switch(input){
        case '1':
        printf("Current Galactic coords: (%f", entitylocation[2][0]);
        printf(",%f", entitylocation[3][0]);
        printf(",%f", entitylocation[4][0]);
        printf(")\n");

        printf("Hyperdrive Control\n");
        printf("Enter desired coordinates (AU): (X,Y,Z)\n");
        scanf("%d", &hypx);
        scanf("%d", &hypy);
        scanf("%d", &hypz);
        system("cls");
        printf("Hyperdrive Control\n");
        printf("Coordnates (");
        printf("%d", hypx);
        printf(",%d", hypy);
        printf(",%d", hypz);
        printf(") inputed!\n");

        xin = hypx;
        yin = hypy;
        zin = hypz;

        //Calculate temporary distances
        tempx = hypx - entitylocation[2][0];
        tempy = hypy - entitylocation[3][0];
        tempz = hypz - entitylocation[4][0];
        galxinitial = entitylocation[2][0];
        galyinitial = entitylocation[3][0];
        galzinitial = entitylocation[4][0];

        //Calculate straight line distance and angles
        thetaxz = atan(tempx/tempz);//Calculate the xz thets
        if(tempx == 0 && tempz <= (-1)){//Theta mod for negative z axis
            thetaxz = pi * (-1);
        }
        if(tempx != abs(tempx) && tempz != abs(tempz) && tempx != 0){//Theta mod for quadrant 3
            thetaxz = (thetaxz + pi / 2) * (-1);
        }
        if(tempx == abs(tempx) && tempz != abs(tempz) && tempx != 0){//Theta mod for quadrant 4
            thetaxz = (thetaxz  - pi / 2) * (-1);
        }
        temphypo = sqrt(pow(abs(tempx), 2) + pow(abs(tempz), 2));//Calculate the temp xz hypo
        thetay = atan(tempy/temphypo);

        if((tempy != abs(tempy)) && (thetaxz > (pi / 2) || thetaxz < (pi / -2))){//Theta mod for below and behind
            thetay = (pi + thetay) * (-1);
        }
        if((tempy == abs(tempy)) && (thetaxz > (pi / 2) || thetaxz < (pi / -2)) && (tempy != 0)){//Theta mod for above and behind
            thetay = pi - thetay;
        }
        hyperdrivedistance = sqrt(pow(temphypo, 2) + pow(abs(tempy), 2));//Calculate the jump distance
        printf("Distance: %f\n", hyperdrivedistance);

        //Calculate travel time
        hyperdrivetime = hyperdrivedistance / entitystat[1][0];
        hyperdrivetimeinitial = hyperdrivetime;
        printf("Travel time: %f", hyperdrivetime);
        printf(" seconds\n");

        printf("thetay %f\n", thetay);
        printf("thetaxz %f\n", thetaxz);
        printf("tempx %f\n", tempx);
        printf("tempy %f\n", tempy);
        printf("tempz %f\n", tempz);

        printf("Procede to hyperspace jump?\n");
        tempin = getch();
        system("cls");

    switch(tempin){
        case '1':
        if(entitymodule[1][0] == -1){//Deny jump if no hyperdrive is present
            printf("Ship does not have a hyperdrive installed!\n");
            Sleep(2000);
            break;
        }
        if(entitymodule[1][0] == 2){//Deny jump if no hyperdrive is present
            printf("Hyperdrive is offline!\n");
            Sleep(2000);
            break;
        }
        if(entitystat[22][0] < (sqrt(3) / entitystat[1][0]) * (entitystat[11][0] * massenergy)){//Deny jump is there is not enough power
            printf("Not enough power!\n");
            Sleep(2000);
            break;
        }

        PlaySound("C:\\Users\\Kyle\\Documents\\Programming\\C programs\\SG Flight Sim C++\\audio\\HYPERDRIVE_WINDOW.WAV", NULL, SND_ASYNC);

        while(hyperdrivetime > 0){
            system("cls");
            Sleep(timewait);
            hyperdrivetime = hyperdrivetime - timewait;
            distancecount++;

            //Coord change
            if(thetaxz > pi / 2){
                entitylocation[2][0] = galxinitial - ((((entitystat[1][0] * timewait * distancecount) * cos(thetay))) * sin(pi - thetaxz));//X coord update on quad IV xz
            }
            else if(thetaxz < pi / (-2)){
                entitylocation[2][0] = (((entitystat[1][0] * timewait * distancecount) * cos(thetay)) * sin(pi * (-1) + thetaxz)) + galxinitial;//X coord update on quad III xz
            }
            else{
                entitylocation[2][0] = (((entitystat[1][0] * timewait * distancecount) * cos(thetay)) * sin(thetaxz)) + galxinitial;//X coord update on quad I and II xz and x axis
            }

            entitylocation[3][0] = ((entitystat[1][0] * timewait * distancecount) * sin(thetay)) + galyinitial;//Y coord update

            if((thetaxz == pi || thetaxz == pi * (-1)) && thetay == 0){//Z coord update -z axis
                entitylocation[4][0] = galzinitial - (entitystat[1][0] * timewait * distancecount);
            }
            else if(thetaxz == 0 && thetay == 0){//Z coord update z axis
                entitylocation[4][0] = (entitystat[1][0] * timewait * distancecount) + galzinitial;
            }
            else if(thetaxz > pi / 2){//Z coord update quad IV xz
                entitylocation[4][0] = ((((entitystat[1][0] * timewait * distancecount) * cos(thetay))) * cos(pi - thetaxz)) + galzinitial;//Z coord update
            }
            else if(thetaxz < pi / (-2)){//Z coord update quad III xz
                entitylocation[4][0] = ((((entitystat[1][0] * timewait * distancecount) * cos(thetay))) * cos(pi * (-1) + thetaxz)) + galzinitial;//Z coord update
            }
            else{//Z coord update
                entitylocation[4][0] = ((((entitystat[1][0] * timewait * distancecount) * cos(thetay))) * cos(thetaxz)) + galzinitial;//Z coord update
            }

            if(!(thetaxz >= pi * (-1))){//Vertical undefined xz patch
                entitylocation[2][0] = 0;
                entitylocation[4][0] = 0;
            }

            //hyperdrive power consumption
            entitystat[22][0] = entitystat[22][0] - (entitystat[23][0] * massenergy) * timewait;//Use power
            if(entitystat[22][0] < (sqrt(3) / entitystat[1][0]) * (entitystat[11][0] * massenergy)){//Early dropout due to power failure
                entitylocation[2][0] = round(entitylocation[2][0]);
                entitylocation[3][0] = round(entitylocation[3][0]);
                entitylocation[4][0] = round(entitylocation[4][0]);
                locreset = true;
                hyperdrivetime = 0;
                PlaySound("C:\\Users\\Kyle\\Documents\\Programming\\C programs\\SG Flight Sim C++\\audio\\HYPERDRIVE_WINDOW.WAV", NULL, SND_ASYNC);
                printf("Power failure!\n");
                Sleep(2000);
                break;
            }
//gal coord glitch on early dropouts, not rounding
            if(GetAsyncKeyState(0x44)){//Early dropout
                entitylocation[2][0] = round(entitylocation[2][0]);
                entitylocation[3][0] = round(entitylocation[3][0]);
                entitylocation[4][0] = round(entitylocation[4][0]);
                locreset = true;
                hyperdrivetime = 0;
                PlaySound("C:\\Users\\Kyle\\Documents\\Programming\\C programs\\SG Flight Sim C++\\audio\\HYPERDRIVE_WINDOW.WAV", NULL, SND_ASYNC);
                break;
            }

            printf("Hyperdrive Control\n");
            printf("Jumping!\n");
            printf("Time until arrival(s): ");
            printf("%f\n", hyperdrivetime);
            printf("Destination: (%f", xin);
            printf(",%f", yin);
            printf(",%f", zin);
            printf(")\n");
            printf("Current location: (%f", entitylocation[2][0]);
            printf(",%f", entitylocation[3][0]);
            printf(",%f", entitylocation[4][0]);
            printf(")\n");
            printf("Power: %f\n", entitystat[22][0]);
        }
        locreset = true;
        PlaySound("C:\\Users\\Kyle\\Documents\\Programming\\C programs\\SG Flight Sim C++\\audio\\HYPERDRIVE_WINDOW.WAV", NULL, SND_ASYNC);
        break;

        default:
        printf("Hyperdrive Control\n");
        printf("Jump aborted!\n");
        break;
    }

    //Set new gal coords
    entitylocation[2][0] = round(entitylocation[2][0]);
    entitylocation[3][0] = round(entitylocation[3][0]);
    entitylocation[4][0] = round(entitylocation[4][0]);

    //Value resets
    distancecount = 0;
    tempx = 0;
    tempy = 0;
    tempz = 0;
    hyperdrivetime = 0;
    temphypo = 0;
    galxinitial = 0;
    galyinitial = 0;
    galzinitial = 0;
    menupause = false;
    break;

        case '2'://--------------------------------------------------------------------------------------------------------------
            printf("Current Local coords (km): (%f", entitylocation[5][0]);
            printf(",%f", entitylocation[6][0]);
            printf(",%f", entitylocation[7][0]);
            printf(")\n");

            printf("Hyperdrive Control\n");
            printf("Enter desired coordinates (km): (X,Y,Z)\n");
            scanf("%d", &hypx);
            scanf("%d", &hypy);
            scanf("%d", &hypz);
            system("cls");
            printf("Hyperdrive Control\n");
            printf("Coordnates (");
            printf("%d", hypx);
            printf(",%d", hypy);
            printf(",%d", hypz);
            printf(") inputed!\n");

            xin = hypx;
            yin = hypy;
            zin = hypz;

            //Calculate temporary distances
            tempx = hypx - (entitylocation[5][0] / 1000);
            tempy = hypy - (entitylocation[6][0] / 1000);
            tempz = hypz - (entitylocation[7][0] / 1000);
            galxinitial = entitylocation[5][0] / 1000;
            galyinitial = entitylocation[6][0] / 1000;
            galzinitial = entitylocation[7][0] / 1000;

            //Calculate straight line distance and angles
            thetaxz = atan(tempx/tempz);//Calculate the xz thets
            if(tempx == 0 && tempz <= (-1)){//Theta mod for negative z axis
                thetaxz = pi * (-1);
            }
            if(tempx != abs(tempx) && tempz != abs(tempz) && tempx != 0){//Theta mod for quadrant 3
                thetaxz = (thetaxz + pi / 2) * (-1);
            }
            if(tempx == abs(tempx) && tempz != abs(tempz) && tempx != 0){//Theta mod for quadrant 4
                thetaxz = (thetaxz  - pi / 2) * (-1);
            }
            temphypo = sqrt(pow(abs(tempx), 2) + pow(abs(tempz), 2));//Calculate the temp xz hypo
            thetay = atan(tempy/temphypo);

            if((tempy != abs(tempy)) && (thetaxz > (pi / 2) || thetaxz < (pi / -2))){//Theta mod for below and behind
                thetay = (pi + thetay) * (-1);
            }
            if((tempy == abs(tempy)) && (thetaxz > (pi / 2) || thetaxz < (pi / -2)) && (tempy != 0)){//Theta mod for above and behind
                thetay = pi - thetay;
            }
            hyperdrivedistance = sqrt(pow(temphypo, 2) + pow(abs(tempy), 2));//Calculate the jump distance
            printf("Distance: %f\n", hyperdrivedistance);

            //Calculate travel time
            hyperdrivetime = hyperdrivedistance / ((entitystat[1][0] *9460000000000) / 100000);
            hyperdrivetimeinitial = hyperdrivetime;
            printf("Travel time: %f", hyperdrivetime);
            printf(" seconds\n");

            printf("thetay %f\n", thetay);
            printf("thetaxz %f\n", thetaxz);
            printf("tempx %f\n", tempx);
            printf("tempy %f\n", tempy);
            printf("tempz %f\n", tempz);

            printf("Procede to hyperspace jump?\n");
            tempin = getch();
            system("cls");

            switch(tempin){
                case '1':
                if(entitymodule[1][0] == -1){//Deny jump if no hyperdrive is present
                    printf("Ship does not have a hyperdrive installed!\n");
                    Sleep(2000);
                    break;
                }
                if(entitymodule[1][0] == 2){//Deny jump if no hyperdrive is present
                    printf("Hyperdrive is offline!\n");
                    Sleep(2000);
                    break;
                }
                if(entitymodule[1][0] < (sqrt(3) / ((entitystat[1][0] * 9460000000000) / 100000)) * (entitystat[11][0] * massenergy)){//Deny jump is there is not enough power
                    printf("Not enough power!\n");
                    Sleep(2000);
                    break;
                }

                PlaySound("C:\\Users\\Kyle\\Documents\\Programming\\C programs\\SG Flight Sim C++\\audio\\HYPERDRIVE_WINDOW.WAV", NULL, SND_ASYNC);

                while(hyperdrivetime > 0){
                    system("cls");
                    Sleep(timewait);
                    hyperdrivetime = hyperdrivetime - timewait;
                    distancecount++;

                    //Coord change
                    if(thetaxz > pi / 2){
                        entitylocation[5][0] = galxinitial - (((((((entitystat[1][0] * 9460000000000) / 100000)) * timewait * distancecount) * cos(thetay))) * sin(pi - thetaxz));//X coord update on quad IV xz
                    }
                    else if(thetaxz < pi / (-2)){
                        entitylocation[5][0] = ((((((entitystat[1][0] * 9460000000000) / 100000)) * timewait * distancecount) * cos(thetay)) * sin(pi * (-1) + thetaxz)) + galxinitial;//X coord update on quad III xz
                    }
                    else{
                        entitylocation[5][0] = ((((((entitystat[1][0] * 9460000000000) / 100000)) * timewait * distancecount) * cos(thetay)) * sin(thetaxz)) + galxinitial;//X coord update on quad I and II xz and x axis
                    }

                    entitylocation[6][0] = (((((entitystat[1][0] * 9460000000000) / 100000)) * timewait * distancecount) * sin(thetay)) + galyinitial;//Y coord update

                    if((thetaxz == pi || thetaxz == pi * (-1)) && thetay == 0){//Z coord update -z axis
                        entitylocation[7][0] = galzinitial - ((((entitystat[1][0] * 9460000000000) / 100000)) * timewait * distancecount);
                    }
                    else if(thetaxz == 0 && thetay == 0){//Z coord update z axis
                        entitylocation[7][0] = (entitystat[1][0] * timewait * distancecount) + galzinitial;
                    }
                    else if(thetaxz > pi / 2){//Z coord update quad IV xz
                        entitylocation[7][0] = (((((((entitystat[1][0] * 9460000000000) / 100000)) * timewait * distancecount) * cos(thetay))) * cos(pi - thetaxz)) + galzinitial;//Z coord update
                    }
                    else if(thetaxz < pi / (-2)){//Z coord update quad III xz
                        entitylocation[7][0] = (((((((entitystat[1][0] * 9460000000000) / 100000)) * timewait * distancecount) * cos(thetay))) * cos(pi * (-1) + thetaxz)) + galzinitial;//Z coord update
                    }
                    else{//Z coord update
                        entitylocation[7][0] = (((((((entitystat[1][0] * 9460000000000) / 100000)) * timewait * distancecount) * cos(thetay))) * cos(thetaxz)) + galzinitial;//Z coord update
                    }

                    if(!(thetaxz >= pi * (-1))){//Vertical undefined xz patch
                        entitylocation[5][0] = 0;
                        entitylocation[7][0] = 0;
                    }

                    //hyperdrive power consumption
                    entitystat[22][0] = entitystat[22][0] - (entitystat[11][0] * massenergy) * timewait;//Use power
                    if(entitystat[22][0] < (sqrt(3) / (((entitystat[22][0] * 9460000000000) / 100000))) * (entitystat[11][0] * massenergy)){//Early dropout due to power failure
                        entitylocation[5][0] = round(entitylocation[5][0]);
                        entitylocation[6][0] = round(entitylocation[6][0]);
                        entitylocation[7][0] = round(entitylocation[7][0]);
                        locreset = true;
                        hyperdrivetime = 0;
                        PlaySound("C:\\Users\\Kyle\\Documents\\Programming\\C programs\\SG Flight Sim C++\\audio\\HYPERDRIVE_WINDOW.WAV", NULL, SND_ASYNC);
                        printf("Power failure!\n");
                        Sleep(2000);
                        break;
                    }
        //gal coord glitch on early dropouts, not rounding
                    if(GetAsyncKeyState(0x44)){//Early dropout
                        entitylocation[5][0] = round(entitylocation[5][0]);
                        entitylocation[6][0] = round(entitylocation[6][0]);
                        entitylocation[7][0] = round(entitylocation[7][0]);
                        locreset = true;
                        hyperdrivetime = 0;
                        PlaySound("C:\\Users\\Kyle\\Documents\\Programming\\C programs\\SG Flight Sim C++\\audio\\HYPERDRIVE_WINDOW.WAV", NULL, SND_ASYNC);
                        break;
                    }

                    printf("Hyperdrive Control\n");
                    printf("Jumping!\n");
                    printf("Time until arrival(s): ");
                    printf("%f\n", hyperdrivetime);
                    printf("Destination: (%f", xin);
                    printf(",%f", yin);
                    printf(",%f", zin);
                    printf(")\n");
                    printf("Current location (km): (%f", entitylocation[5][0]);
                    printf(",%f", entitylocation[6][0]);
                    printf(",%f", entitylocation[7][0]);
                    printf(")\n");
                    printf("Power: %f\n", entitylocation[22][0]);
                }
                locreset = true;
                PlaySound("C:\\Users\\Kyle\\Documents\\Programming\\C programs\\SG Flight Sim C++\\audio\\HYPERDRIVE_WINDOW.WAV", NULL, SND_ASYNC);
                break;

                default:
                printf("Hyperdrive Control\n");
                printf("Jump aborted!\n");
                break;
            }

            //Set new gal coords
            entitylocation[5][0] = round(entitylocation[5][0]);
            entitylocation[6][0] = round(entitylocation[6][0]);
            entitylocation[7][0] = round(entitylocation[7][0]);

            //Value resets
            distancecount = 0;
            tempx = 0;
            tempy = 0;
            tempz = 0;
            hyperdrivetime = 0;
            temphypo = 0;
            galxinitial = 0;
            galyinitial = 0;
            galzinitial = 0;
            menupause = false;
            break;
    }
}

hyperdrive::~hyperdrive()
{
    //dtor
}
