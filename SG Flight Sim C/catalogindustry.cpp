#include "catalogindustry.h"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

double asteroid[106][12];       //[0]type (Letter to #), [1]frequency, [2]size (XS:1,S,M,L,XL), [3]density, [4-105]element/minerals
double elementmineral[2][105];  //[0]size, [1]density
double alloy[104][9];           //[0]size, [1]density, [2-103]element/mineral
double part[104][30];           //[0]size, [1]weight, [2-103]element/mineral
double t1mod[134][48];          //[0]size, [1]weight, [2-103]element/mineral, [104-133]part
double t2mod[59][48];           //[0]size, [1]weight, [2-38]alloy, [39-47]t1mod
double t1ammo[104][18];         //[0]size, [1]weight, [2-103]element/mineral
double t2ammo[113][9];          //[0]size, [1]weight, [2-103]element/mineral, [104-112]alloy

double fighter[134][2];         //[0]size, [1]weight, [2-103]element/mineral, [104-133]part
double frigate[134][0];         //[0]size, [1]weight, [2-103]element/mineral, [104-133]part
double destroyer[134][0];       //[0]size, [1]weight, [2-103]element/mineral, [104-133]part
double cruiser[134][0];         //[0]size, [1]weight, [2-103]element/mineral, [104-133]part
double battlecruiser[134][2];   //[0]size, [1]weight, [2-103]element/mineral, [104-133]part
double battleship[134][0];      //[0]size, [1]weight, [2-103]element/mineral, [104-133]part
double carrier[134][0];         //[0]size, [1]weight, [2-103]element/mineral, [104-133]part
double dread[134][0];           //[0]size, [1]weight, [2-103]element/mineral, [104-133]part
double mining[134][0];          //[0]size, [1]weight, [2-103]element/mineral, [104-133]part
double freight[134][0];         //[0]size, [1]weight, [2-103]element/mineral, [104-133]part
double structure[0][0];         //***

static int loopcount = 0;
static int loopcount2 = 0;

catalogindustry::catalogindustry()
{
    //reset
    while(loopcount < 105){
        while(loopcount2 < 12){
            asteroid[loopcount][loopcount2] = 0;
            loopcount2++;
        }
        loopcount2 = 0;
        loopcount++;
    }
    loopcount = 0;
    loopcount2 = 0;

    while(loopcount < 2){
        while(loopcount2 < 105){
            elementmineral[loopcount][loopcount2] = 0;
            loopcount2++;
        }
        loopcount2 = 0;
        loopcount++;
    }
    loopcount = 0;
    loopcount2 = 0;

    while(loopcount < 104){
        while(loopcount2 < 9){
            alloy[loopcount][loopcount2] = 0;
            loopcount2++;
        }
        loopcount2 = 0;
        loopcount++;
    }
    loopcount = 0;
    loopcount2 = 0;

    while(loopcount < 104){
        while(loopcount2 < 30){
            part[loopcount][loopcount2] = 0;
            loopcount2++;
        }
        loopcount2 = 0;
        loopcount++;
    }
    loopcount = 0;
    loopcount2 = 0;

    while(loopcount < 134){
        while(loopcount2 < 48){
            t1mod[loopcount][loopcount2] = 0;
            loopcount2++;
        }
        loopcount2 = 0;
        loopcount++;
    }
    loopcount = 0;
    loopcount2 = 0;

    while(loopcount < 59){
        while(loopcount2 < 48){
            t2mod[loopcount][loopcount2] = 0;
            loopcount2++;
        }
        loopcount2 = 0;
        loopcount++;
    }
    loopcount = 0;
    loopcount2 = 0;

    while(loopcount < 104){
        while(loopcount2 < 18){
            t1ammo[loopcount][loopcount2] = 0;
            loopcount2++;
        }
        loopcount2 = 0;
        loopcount++;
    }
    loopcount = 0;
    loopcount2 = 0;

    while(loopcount < 113){
        while(loopcount2 < 9){
            t2ammo[loopcount][loopcount2] = 0;
            loopcount2++;
        }
        loopcount2 = 0;
        loopcount++;
    }
    loopcount = 0;
    loopcount2 = 0;

    while(loopcount < 134){
        while(loopcount2 < 2){
            fighter[loopcount][loopcount2] = 0;
            loopcount2++;
        }
        loopcount2 = 0;
        loopcount++;
    }
    loopcount = 0;
    loopcount2 = 0;

    while(loopcount < 134){
        while(loopcount2 < 0){
            frigate[loopcount][loopcount2] = 0;
            loopcount2++;
        }
        loopcount2 = 0;
        loopcount++;
    }
    loopcount = 0;
    loopcount2 = 0;

    while(loopcount < 134){
        while(loopcount2 < 0){
            destroyer[loopcount][loopcount2] = 0;
            loopcount2++;
        }
        loopcount2 = 0;
        loopcount++;
    }
    loopcount = 0;
    loopcount2 = 0;

    while(loopcount < 134){
        while(loopcount2 < 0){
            cruiser[loopcount][loopcount2] = 0;
            loopcount2++;
        }
        loopcount2 = 0;
        loopcount++;
    }
    loopcount = 0;
    loopcount2 = 0;

    while(loopcount < 134){
        while(loopcount2 < 2){
            battlecruiser[loopcount][loopcount2] = 0;
            loopcount2++;
        }
        loopcount2 = 0;
        loopcount++;
    }
    loopcount = 0;
    loopcount2 = 0;

    while(loopcount < 134){
        while(loopcount2 < 0){
            battleship[loopcount][loopcount2] = 0;
            loopcount2++;
        }
        loopcount2 = 0;
        loopcount++;
    }
    loopcount = 0;
    loopcount2 = 0;

    while(loopcount < 134){
        while(loopcount2 < 0){
            carrier[loopcount][loopcount2] = 0;
            loopcount2++;
        }
        loopcount2 = 0;
        loopcount++;
    }
    loopcount = 0;
    loopcount2 = 0;

    while(loopcount < 134){
        while(loopcount2 < 0){
            dread[loopcount][loopcount2] = 0;
            loopcount2++;
        }
        loopcount2 = 0;
        loopcount++;
    }
    loopcount = 0;
    loopcount2 = 0;

    while(loopcount < 134){
        while(loopcount2 < 0){
            mining[loopcount][loopcount2] = 0;
            loopcount2++;
        }
        loopcount2 = 0;
        loopcount++;
    }
    loopcount = 0;
    loopcount2 = 0;

    while(loopcount < 134){
        while(loopcount2 < 0){
            freight[loopcount][loopcount2] = 0;
            loopcount2++;
        }
        loopcount2 = 0;
        loopcount++;
    }
    loopcount = 0;
    loopcount2 = 0;

    while(loopcount < 134){
        while(loopcount2 < 0){
            structure[loopcount][loopcount2] = 0;
            loopcount2++;
        }
        loopcount2 = 0;
        loopcount++;
    }
    loopcount = 0;
    loopcount2 = 0;

    //asteroid
    //[0]type (Letter to #), [1]frequency, [2]size (XS:1,S,M,L,XL), [3]density, [4-105]element/minerals
    //C-Type
    asteroid[0][0] = 3;
    asteroid[1][0] = 0.5;
    asteroid[2][0] = 3;
    asteroid[3][0] = 10;

    asteroid[11][0] = 5;
    asteroid[6][0] = 1.5;
    asteroid[26][0] = 1;
    asteroid[13][0] = 1;
    asteroid[22][0] = 0.7;
    asteroid[100][0] = 0.5;
    asteroid[16][0] = 0.3;

}

catalogindustry::~catalogindustry()
{
    //dtor
}
