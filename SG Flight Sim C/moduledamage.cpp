#include "moduledamage.h"

#include <iostream>
#include <stdlib.h>
#include <windows.h>

using namespace std;

extern double entitymodule[13][1000];

static int y = 0;

moduledamage::moduledamage()//ratio 5% good to offline (within) 10%, 10% good to damaged, 20% damaged to offline
{
    while(y <= 220){
        if(entitymodule[1][y] == 0){//Hyperdrive damaged
            if(rand() % 100 < 10){//10%
                entitymodule[1][y] = 1;
                if(y == 0){
                    PlaySound("C:\\Users\\Kyle\\Documents\\Programming\\C programs\\SG Flight Sim C++\\audio\\HYPERDRIVEDAMAGED.WAV", NULL, SND_ASYNC);
                }
                if(rand() % 100 < 5){//Hyperdrive offline
                    entitymodule[1][y] = 2;//5%
                    if(y == 0){
                        PlaySound("C:\\Users\\Kyle\\Documents\\Programming\\C programs\\SG Flight Sim C++\\audio\\HYPERDRIVEOFFLINE.WAV", NULL, SND_ASYNC);
                    }
                }
            }
            y++;
        }
        else if(entitymodule[1][y] == 1){//Damaged hyperdrive offline
            if(rand() % 100 < 20){//20%
               entitymodule[1][y] = 2;
               if(y == 0){
                    PlaySound("C:\\Users\\Kyle\\Documents\\Programming\\C programs\\SG Flight Sim C++\\audio\\HYPERDRIVEOFFLINE.WAV", NULL, SND_ASYNC);
               }
            }
            y++;
        }
        if(entitymodule[2][y] == 0){//Sublights damaged
            if(rand() % 100 < 1){//1%
                entitymodule[2][y] = 1;
                if(y == 0){
                    PlaySound("C:\\Users\\Kyle\\Documents\\Programming\\C programs\\SG Flight Sim C++\\audio\\SUBLIGHTSDAMAGED.WAV", NULL, SND_ASYNC);
                }
                if(rand() % 1000 < 5){//Sublights offline
                    entitymodule[2][y] = 2;//0.5%
                    if(y == 0){
                        PlaySound("C:\\Users\\Kyle\\Documents\\Programming\\C programs\\SG Flight Sim C++\\audio\\SUBLIGHTSOFFLINE.WAV", NULL, SND_ASYNC);
                    }
                }
            }
            y++;
        }
        else if(entitymodule[2][y] == 1){//Damaged Sublights offline
            if(rand() % 100 < 2){//2%
                entitymodule[2][y] = 2;
                if(y == 0){
                    PlaySound("C:\\Users\\Kyle\\Documents\\Programming\\C programs\\SG Flight Sim C++\\audio\\SUBLIGHTSOFFLINE.WAV", NULL, SND_ASYNC);
                }
            }
            y++;
        }
        if(entitymodule[10][y] == 0){//Manuvering damaged
            if(rand() % 100 < 1){//1%
                entitymodule[10][y] = 1;
                if(y == 0){
                    PlaySound("C:\\Users\\Kyle\\Documents\\Programming\\C programs\\SG Flight Sim C++\\audio\\MANUVERINGDAMAGED.WAV", NULL, SND_ASYNC);
                }
                if(rand() % 1000 < 5){//Manuvering offline
                    entitymodule[10][y] = 2;//0.5%
                    if(y == 0){
                        PlaySound("C:\\Users\\Kyle\\Documents\\Programming\\C programs\\SG Flight Sim C++\\audio\\MANUVERINGOFFLINE.WAV", NULL, SND_ASYNC);
                    }
                }
            }
            y++;
        }
        else if(entitymodule[10][y] == 1){//Damaged manuvering offline
            if(rand() % 100 < 2){//2%
                entitymodule[10][y] = 2;
                if(y == 0){
                    PlaySound("C:\\Users\\Kyle\\Documents\\Programming\\C programs\\SG Flight Sim C++\\audio\\MANUVERINGOFFLINE.WAV", NULL, SND_ASYNC);
                }
            }
            y++;
        }
        if(entitymodule[3][y] == 0){//Shield damaged
            if(rand() % 100 < 10){//10%
                entitymodule[3][y] = 1;
                if(y == 0){
                    //PlaySound("C:\\Users\\Kyle\\Documents\\Programming\\C programs\\SG Flight Sim C++\\audio\\REACTORDAMAGED.WAV", NULL, SND_ASYNC);
                }
                if(rand() % 100 < 5){//Shield offline
                    entitymodule[3][y] = 2;//5%
                    if(y == 0){
                        //PlaySound("C:\\Users\\Kyle\\Documents\\Programming\\C programs\\SG Flight Sim C++\\audio\\REACTOROFFLINE.WAV", NULL, SND_ASYNC);
                    }
                }
            }
            y++;
        }
        else if(entitymodule[3][y] == 1){//Damaged shield offline
            if(rand() % 100 < 20){//20%
                entitymodule[3][y] = 2;
                if(y == 0){
                    PlaySound("C:\\Users\\Kyle\\Documents\\Programming\\C programs\\SG Flight Sim C++\\audio\\REACTOROFFLINE.WAV", NULL, SND_ASYNC);
                }
            }
            y++;
        }
        if(entitymodule[4][y] == 0){//Reactor damaged
            if(rand() % 10000 < 5){//0.05%
                entitymodule[4][y] = 1;
                if(y == 0){
                    PlaySound("C:\\Users\\Kyle\\Documents\\Programming\\C programs\\SG Flight Sim C++\\audio\\REACTORDAMAGED.WAV", NULL, SND_ASYNC);
                }
                if(rand() % 100000 < 25){//Reactor offline
                    entitymodule[4][y] = 2;//0.025%
                    if(y == 0){
                        PlaySound("C:\\Users\\Kyle\\Documents\\Programming\\C programs\\SG Flight Sim C++\\audio\\REACTOROFFLINE.WAV", NULL, SND_ASYNC);
                    }
                }
            }
            y++;
        }
        else if(entitymodule[4][y] == 1){//Damaged reactor offline
            if(rand() % 1000 < 1){//0.1%
                entitymodule[4][y] = 2;
                if(y == 0){
                    PlaySound("C:\\Users\\Kyle\\Documents\\Programming\\C programs\\SG Flight Sim C++\\audio\\REACTOROFFLINE.WAV", NULL, SND_ASYNC);
                }
            }
            y++;
        }
        if(entitymodule[5][y] == 0){//Capacitor damaged
            if(rand() % 10000 < 5){//0.05%
                entitymodule[5][y] = 1;
                if(y == 0){
                    PlaySound("C:\\Users\\Kyle\\Documents\\Programming\\C programs\\SG Flight Sim C++\\audio\\CAPACITORDAMAGED.WAV", NULL, SND_ASYNC);
                }
                if(rand() % 100000 < 25){//Capacitor offline
                    entitymodule[5][y] = 2;//0.025%
                    if(y == 0){
                        PlaySound("C:\\Users\\Kyle\\Documents\\Programming\\C programs\\SG Flight Sim C++\\audio\\CAPACITOROFFLINE.WAV", NULL, SND_ASYNC);
                    }
                }
            }
            y++;
        }
        else if(entitymodule[5][y] == 1){//Damaged capacitor offline
            if(rand() % 1000 < 1){//0.1%
                entitymodule[5][y] = 2;
                if(y == 0){
                    PlaySound("C:\\Users\\Kyle\\Documents\\Programming\\C programs\\SG Flight Sim C++\\audio\\CAPACITOROFFLINE.WAV", NULL, SND_ASYNC);
                }
            }
            y++;
        }
        if(entitymodule[6][y] == 0){//LRsensors damaged
            if(rand() % 1000 < 1){//0.1%
                entitymodule[6][y] = 1;
                if(y == 0){
                    PlaySound("C:\\Users\\Kyle\\Documents\\Programming\\C programs\\SG Flight Sim C++\\audio\\LRSENSORSDAMAGED.WAV", NULL, SND_ASYNC);
                }
                if(rand() % 10000 < 5){//LRsensors offline
                    entitymodule[6][y] = 2;//0.05%
                    if(y == 0){
                        PlaySound("C:\\Users\\Kyle\\Documents\\Programming\\C programs\\SG Flight Sim C++\\audio\\LRSENSORSOFFLINE.WAV", NULL, SND_ASYNC);
                    }
                }
            }
            y++;
        }
        else if(entitymodule[6][y] == 1){//Damaged LRsensors offline
            if(rand() % 1000 < 2){//0.2%
                entitymodule[6][y] = 2;
                if(y == 0){
                    PlaySound("C:\\Users\\Kyle\\Documents\\Programming\\C programs\\SG Flight Sim C++\\audio\\LRSENSORSOFFLINE.WAV", NULL, SND_ASYNC);
                }
            }
            y++;
        }
        if(entitymodule[7][y] == 0){//SRsensors damaged
            if(rand() % 1000 < 1){//0.1%
                entitymodule[7][y] = 1;
                if(y == 0){
                    PlaySound("C:\\Users\\Kyle\\Documents\\Programming\\C programs\\SG Flight Sim C++\\audio\\SRSENSORSDAMAGED.WAV", NULL, SND_ASYNC);
                }
                if(rand() % 10000 < 5){//SRsensors offline
                    entitymodule[7][y] = 2;//0.05%
                    if(y == 0){
                        PlaySound("C:\\Users\\Kyle\\Documents\\Programming\\C programs\\SG Flight Sim C++\\audio\\SRSENSORSOFFLINE.WAV", NULL, SND_ASYNC);
                    }
                }
            }
            y++;
        }
        else if(entitymodule[7][y] == 1){//Damaged SRsensors offline
            if(rand() % 1000 < 2){//0.2%
                entitymodule[7][y] = 2;
                if(y == 0){
                    PlaySound("C:\\Users\\Kyle\\Documents\\Programming\\C programs\\SG Flight Sim C++\\audio\\SRSENSORSOFFLINE.WAV", NULL, SND_ASYNC);
                }
            }
            y++;
        }
        if(entitymodule[8][y] == 0){//Radio damaged
            if(rand() % 1000 < 1){//0.1%
                entitymodule[8][y] = 1;
                if(y == 0){
                    PlaySound("C:\\Users\\Kyle\\Documents\\Programming\\C programs\\SG Flight Sim C++\\audio\\RADIODAMAGED.WAV", NULL, SND_ASYNC);
                }
                if(rand() % 10000 < 5){//Radio offline
                    entitymodule[8][y] = 2;//0.05%
                    if(y == 0){
                        PlaySound("C:\\Users\\Kyle\\Documents\\Programming\\C programs\\SG Flight Sim C++\\audio\\RADIOOFFLINE.WAV", NULL, SND_ASYNC);
                    }
                }
            }
            y++;
        }
        else if(entitymodule[8][y] == 1){//Damaged Radio offline
            if(rand() % 1000 < 2){//0.2%
                entitymodule[8][y] = 2;
                if(y == 0){
                    PlaySound("C:\\Users\\Kyle\\Documents\\Programming\\C programs\\SG Flight Sim C++\\audio\\RADIOOFFLINE.WAV", NULL, SND_ASYNC);
                }
            }
            y++;
        }
        if(entitymodule[12][y] == 0){//Life support damaged
            if(rand() % 10000 < 5){//0.05%
                entitymodule[12][y] = 1;
                if(y == 0){
                    PlaySound("C:\\Users\\Kyle\\Documents\\Programming\\C programs\\SG Flight Sim C++\\audio\\LIFESUPPORTFAILING.WAV", NULL, SND_ASYNC);
                }
                if(rand() % 100000 < 25){//Life support offline
                    entitymodule[12][y] = 2;//0.025%
                    if(y == 0){
                        PlaySound("C:\\Users\\Kyle\\Documents\\Programming\\C programs\\SG Flight Sim C++\\audio\\LIFESUPPORTOFFLINE.WAV", NULL, SND_ASYNC);
                    }
                }
            }
            y++;
        }
        else if(entitymodule[12][y] == 1){//Damaged life support offline
            if(rand() % 1000 < 1){//0.1%
                entitymodule[12][y] = 2;
                if(y == 0){
                    PlaySound("C:\\Users\\Kyle\\Documents\\Programming\\C programs\\SG Flight Sim C++\\audio\\LIFESUPPORTOFFLINE.WAV", NULL, SND_ASYNC);
                }
            }
            y++;
        }
        if(entitymodule[9][y] == 0){//Inertial dampeners damaged
            if(rand() % 10000 < 5){//0.05%
                entitymodule[9][y] = 1;
                if(y == 0){
                    PlaySound("C:\\Users\\Kyle\\Documents\\Programming\\C programs\\SG Flight Sim C++\\audio\\INERTIADAMAGED.WAV", NULL, SND_ASYNC);
                }
                if(rand() % 100000 < 25){//Inertial dampeners offline
                    entitymodule[9][y] = 2;//0.025%
                    if(y == 0){
                        PlaySound("C:\\Users\\Kyle\\Documents\\Programming\\C programs\\SG Flight Sim C++\\audio\\INERTIAOFFLINE.WAV", NULL, SND_ASYNC);
                    }
                }
            }
            y++;
        }
        else if(entitymodule[9][y] == 1){//Damaged inertial dampeners offline
            if(rand() % 1000 < 1){//0.1%
                entitymodule[9][y] = 2;
                if(y == 0){
                    PlaySound("C:\\Users\\Kyle\\Documents\\Programming\\C programs\\SG Flight Sim C++\\audio\\INERTIAOFFLINE.WAV", NULL, SND_ASYNC);
                }
            }
            y++;
        }
        /*
        if(entityinfo[40][y] == 0){//Cloak damaged
            if(rand() % 1000 < 1){//0.1%
                entityinfo[40][y] = 1;
                if(y == 0){
                    PlaySound("C:\\Users\\Kyle\\Documents\\Programming\\C programs\\SG Flight Sim C++\\audio\\CLOAKDAMAGED.WAV", NULL, SND_ASYNC);
                }
                if(rand() % 10000 < 5){//Cloak offline
                    entityinfo[40][y] = 2;//0.05%
                    if(y == 0){
                        PlaySound("C:\\Users\\Kyle\\Documents\\Programming\\C programs\\SG Flight Sim C++\\audio\\CLOAKOFFLINE.WAV", NULL, SND_ASYNC);
                    }
                }
            }
            y++;
        }
        else if(entityinfo[40][y] == 1){//Damaged cloak offline
            if(rand() % 1000 < 2){//0.2%
                entityinfo[40][y] = 2;
                if(y == 0){
                    PlaySound("C:\\Users\\Kyle\\Documents\\Programming\\C programs\\SG Flight Sim C++\\audio\\CLOAKOFFLINE.WAV", NULL, SND_ASYNC);
                }
            }
            y++;
        }
        */
    }
    y = 0;
}

moduledamage::~moduledamage()
{
    //dtor
}
