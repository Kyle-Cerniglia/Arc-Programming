#include "keyinput.h"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include <windows.h>
#include <unistd.h>

using namespace std;

extern bool rLEFT;
extern bool rRIGHT;
extern bool rUP;
extern bool rDOWN;
extern bool W;
extern bool A;
extern bool S;
extern bool D;
extern bool Q;
extern bool E;
extern bool C;
extern bool M;
extern bool SPACE;

keyinput::keyinput()//Detects which keys are pressed
{
    if(GetAsyncKeyState(VK_LEFT)){
        rLEFT = true;
    }
    else{
        rLEFT = false;
    }

    if(GetAsyncKeyState(VK_RIGHT)){
        rRIGHT = true;
    }
    else{
        rRIGHT = false;
    }

    if(GetAsyncKeyState(VK_UP)){
        rUP = true;
    }
    else{
        rUP = false;
    }

    if(GetAsyncKeyState(VK_DOWN)){
        rDOWN = true;
    }
    else{
        rDOWN = false;
    }

    if(GetAsyncKeyState(0x57)){
        W = true;
    }
    else{
        W = false;
    }

    if(GetAsyncKeyState(0x41)){
        A = true;
    }
    else{
        A = false;
    }

    if(GetAsyncKeyState(0x53)){
        S = true;
    }
    else{
        S = false;
    }

    if(GetAsyncKeyState(0x44)){
        D = true;
    }
    else{
        D = false;
    }

    if(GetAsyncKeyState(0x51)){//Down
        Q = true;
    }
    else{
        Q = false;
    }

    if(GetAsyncKeyState(0x45)){//Up
        E = true;
    }
    else{
        E = false;
    }

    if(GetAsyncKeyState(0x43)){
        C = true;
    }
    else{
        C = false;
    }

    if(GetAsyncKeyState(0x4D)){
        M = true;
    }
    else{
        M = false;
    }

    if(GetAsyncKeyState(32)){
        SPACE = true;
    }
    else{
        SPACE = false;
    }
}

keyinput::~keyinput()
{
    //dtor
}
