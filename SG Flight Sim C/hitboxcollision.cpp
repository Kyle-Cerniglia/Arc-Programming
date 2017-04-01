#include "hitboxcollision.h"

#include <stdlib.h>
#include <math.h>

using namespace std;

extern double entitylocation[8][1000];
extern double pi;

static int y = 0;
static double thetaxz = 0;
static double thetay = 0;
static double tempx = 0;
static double tempy = 0;
static double tempz = 0;
static double temphypo = 0;
static double distance = 0;


hitboxcollision::hitboxcollision()
{
    while(y <= 59){
        tempx = abs(entitylocation[5][y] - entitylocation[5][y + 1]);
        tempy = abs(entitylocation[6][y] - entitylocation[6][y + 1]);
        tempz = abs(entitylocation[7][y] - entitylocation[7][y + 1]);

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
        distance = sqrt(pow(temphypo, 2) + pow(abs(tempy), 2));//Calculate the jump distance


        //exclude a collision if the distance is zero
    }
}

hitboxcollision::~hitboxcollision()
{
    //dtor
}
