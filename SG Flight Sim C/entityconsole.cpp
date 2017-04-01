#include "entityconsole.h"

#include <stdio.h>
#include <windows.h>

using namespace std;

extern int railsmentityv[7][100];

entityconsole::entityconsole()
{

    system("cls");
    printf("Test\n");
    printf("%d\n", railsmentityv[0][1]);
    printf("%d\n", railsmentityv[1][1]);
    printf("%d\n", railsmentityv[2][1]);
    printf("%d\n", railsmentityv[3][1]);
    printf("%d\n", railsmentityv[4][1]);
    printf("%d\n", railsmentityv[5][1]);
    printf("%d\n", railsmentityv[6][1]);
}

entityconsole::~entityconsole()
{
    //dtor
}
