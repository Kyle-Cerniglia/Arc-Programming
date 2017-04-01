#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "help.h"

using namespace std;

extern bool menupause;

static int in = 0;

help::help()
{
    system("cls");
    printf("Help\n");
    loop:
    in = getch();
    if(in == '0'){
        menupause = false;
    }
    else{
        goto loop;
    }
}

help::~help()
{
    //dtor
}
