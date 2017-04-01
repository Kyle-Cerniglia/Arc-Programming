#include "catalogcelestialdisplay.h"
#include "catalogcelestial.h"

#include <iostream>
#include <stdio.h>
#include <strings.h>
#include <windows.h>
#include <conio.h>

using namespace std;

extern bool menupause;

static int in = 0;

//extern galaxy vars
extern char *milkyways;
extern int milkyway[4];
extern char *pegasuss;
extern int pegasus[4];

catalogcelestialdisplay::catalogcelestialdisplay()//Displays the celestial catalog
{
    system("cls");
    //Galaxy info display
    printf("ID, Galaxy Name, X, Y, Z\n");
    printf("\n");
    printf("Galaxies:\n");
    printf("%d", milkyway[0]);
    printf(" %s", milkyways);
    printf(" %d", milkyway[1]);
    printf(" %d", milkyway[2]);
    printf(" %d\n", milkyway[3]);
    printf("%d", pegasus[0]);
    printf(" %s", pegasuss);
    printf(" %d", pegasus[1]);
    printf(" %d", pegasus[2]);
    printf(" %d\n", pegasus[3]);
    printf("\n");

    loop:
    in = getch();
    if(in == '0'){
        menupause = false;
    }
    else{
        goto loop;
    }
}

catalogcelestialdisplay::~catalogcelestialdisplay()
{
    //dtor
}
