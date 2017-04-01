#include "shipmodulestatus.h"

#include "stdio.h"
#include "conio.h"
#include "windows.h"

using namespace std;

extern double entitymodule[13][1000];
extern bool menupause;

static int tempint = 0;
static int in = 0;

shipmodulestatus::shipmodulestatus()
{
    system("cls");
    printf("Hyperdrive: ");
    tempint = entitymodule[1][0];
    switch(tempint){
        case -1:
        printf("Not equipped\n");
        break;

        case 0:
        printf("Online\n");
        break;

        case 1:
        printf("Damaged\n");
        break;

        case 2:
        printf("Offline\n");
    }
    printf("Sublights: ");
    tempint = entitymodule[2][0];
    switch(tempint){
        case -1:
        printf("Not equipped\n");
        break;

        case 0:
        printf("Online\n");
        break;

        case 1:
        printf("Damaged\n");
        break;

        case 2:
        printf("Offline\n");
    }
    printf("Manuvering Thrusters: ");
    tempint = entitymodule[10][0];
    switch(tempint){
        case -1:
        printf("Not equipped\n");
        break;

        case 0:
        printf("Online\n");
        break;

        case 1:
        printf("Damaged\n");
        break;

        case 2:
        printf("Offline\n");
    }
    printf("Shields: ");
    tempint = entitymodule[3][0];
    switch(tempint){
        case -1:
        printf("Not equipped\n");
        break;

        case 0:
        printf("Online\n");
        break;

        case 1:
        printf("Damaged\n");
        break;

        case 2:
        printf("Offline\n");
    }
    printf("Reactor: ");
    tempint = entitymodule[4][0];
    switch(tempint){
        case -1:
        printf("Not equipped\n");
        break;

        case 0:
        printf("Online\n");
        break;

        case 1:
        printf("Damaged\n");
        break;

        case 2:
        printf("Offline\n");
    }
    printf("Capacitor: ");
    tempint = entitymodule[5][0];
    switch(tempint){
        case -1:
        printf("Not equipped\n");
        break;

        case 0:
        printf("Online\n");
        break;

        case 1:
        printf("Damaged\n");
        break;

        case 2:
        printf("Offline\n");
    }
    printf("Long-Range Sensors: ");
    tempint = entitymodule[6][0];
    switch(tempint){
        case -1:
        printf("Not equipped\n");
        break;

        case 0:
        printf("Online\n");
        break;

        case 1:
        printf("Damaged\n");
        break;

        case 2:
        printf("Offline\n");
    }
    printf("Short-Range Sensors: ");
    tempint = entitymodule[7][0];
    switch(tempint){
        case -1:
        printf("Not equipped\n");
        break;

        case 0:
        printf("Online\n");
        break;

        case 1:
        printf("Damaged\n");
        break;

        case 2:
        printf("Offline\n");
    }
    printf("Subspace Beacon: ");
    tempint = entitymodule[8][0];
    switch(tempint){
        case -1:
        printf("Not equipped\n");
        break;

        case 0:
        printf("Online\n");
        break;

        case 1:
        printf("Damaged\n");
        break;

        case 2:
        printf("Offline\n");
    }
    printf("Life Support: ");
    tempint = entitymodule[12][0];
    switch(tempint){
        case -1:
        printf("Not equipped\n");
        break;

        case 0:
        printf("Online\n");
        break;

        case 1:
        printf("Damaged\n");
        break;

        case 2:
        printf("Offline\n");
    }
    printf("Inertial Dampeners: ");
    tempint = entitymodule[9][0];
    switch(tempint){
        case -1:
        printf("Not equipped\n");
        break;

        case 0:
        printf("Online\n");
        break;

        case 1:
        printf("Damaged\n");
        break;

        case 2:
        printf("Offline\n");
    }
    /*
    printf("Cloak: ");
    tempint = entityinfo[40][0];
    switch(tempint){
        case -1:
        printf("Not equipped\n");
        break;

        case 0:
        printf("Online\n");
        break;

        case 1:
        printf("Damaged\n");
        break;

        case 2:
        printf("Offline\n");
    }
    */
    loop:
    in = getch();
    if(in == '0'){
        menupause = false;
    }
    else{
        goto loop;
    }
}

shipmodulestatus::~shipmodulestatus()
{
    //dtor
}
