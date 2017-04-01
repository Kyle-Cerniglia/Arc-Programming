#include "gamemenu.h"
#include "hyperdrive.h"
#include "catalogcelestialdisplay.h"
#include "help.h"
#include "shipmodulestatus.h"

#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

using namespace std;

static int gamemenuin = 0;

extern bool M;
extern bool menupause;

gamemenu::gamemenu()//In game menu
{
    if(M == true){
        menupause = true;
        Sleep(10);
        system("cls");
        printf("Help: 1\n");
        printf("Planet Catalog: 2\n");
        printf("Hyperdrive: 3\n");
        printf("Ship module status: 4\n");

        m:
        gamemenuin = getch();

        switch(gamemenuin){
            case '1':
                help();
                break;

            case '2':
                catalogcelestialdisplay();
                break;

            case '3':
                hyperdrive();
                break;

            case '4':
                shipmodulestatus();
                break;

            case 'm':
                goto m;
                break;

            default:
                menupause = false;
                break;
        }
    }
}

gamemenu::~gamemenu()
{
    //dtor
}
