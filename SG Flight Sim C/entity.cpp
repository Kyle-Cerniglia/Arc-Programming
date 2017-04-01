#include "entity.h"

using namespace std;

double entityinfo[43][100];//[0]typeid, [1]id, [2]galaxy, [3]galx, [4]galy, [5]galz, [6]x, [7]y, [8]z, [9]pitch, [10]yaw,
//[11]xspeed, [12]yspeed, [13]zspeed, [14]targetable?, [15]maxspeed(m/s), [16]accel(m/sec^2), [17]mass(kg), [18]gun, [19]missile,
//[20]ammo1, [21]ammo2, [22]hitbox(m(radius)), [23]shieldhp, [24]shieldregen, [25]hullhp, [26]power(GJ), [27]powerregen(GJ/sec),
//[28]hyperdrivespeed(LY/s), module status (-1 no drive, 0 good, 1 damaged, 2 broken), [29]hyperdrive, [30]sublights,
//[31]manuvering, [32]shields, [33]reactor, [34]capacitor, [35]longrange sensors, [36]shortrange sensors, [37]subspace radio,
//[38]lifesupport, [39]inertial dampeners, [40]cloak, [41]dmg(weapon), [42]range(m weapon)

//typeid: 0=ship, 1=stationary, 2=missile, 3=round
//y slots: 0-9=ships, 10-19= stationary, 20-119=missile, 120=219=round,

entity::entity()
{
    entityinfo[0][0] = 0;
    entityinfo[1][0] = 0;
    entityinfo[2][0] = 0;
    entityinfo[3][0] = 0;
    entityinfo[4][0] = 0;
    entityinfo[5][0] = 0;
    entityinfo[6][0] = 0;
    entityinfo[7][0] = 0;
    entityinfo[8][0] = 0;
    entityinfo[9][0] = 0;
    entityinfo[10][0] = 0;
    entityinfo[11][0] = 0;
    entityinfo[12][0] = 0;
    entityinfo[13][0] = 0;
    entityinfo[14][0] = 0;
    entityinfo[15][0] = 0;
    entityinfo[16][0] = 0;
    entityinfo[17][0] = 0;
    entityinfo[18][0] = 0;
    entityinfo[19][0] = 0;
    entityinfo[20][0] = 0;
    entityinfo[21][0] = 0;
    entityinfo[22][0] = 0;
    entityinfo[23][0] = 0;
    entityinfo[24][0] = 0;
    entityinfo[25][0] = 0;
    entityinfo[26][0] = 0;
    entityinfo[27][0] = 0;
    entityinfo[28][0] = 0;
    entityinfo[29][0] = 0;
    entityinfo[30][0] = 0;
    entityinfo[31][0] = 0;
    entityinfo[32][0] = 0;
    entityinfo[33][0] = 0;
    entityinfo[34][0] = 0;
    entityinfo[35][0] = 0;
    entityinfo[36][0] = 0;
    entityinfo[37][0] = 0;
    entityinfo[38][0] = 0;
    entityinfo[39][0] = 0;
    entityinfo[40][0] = 0;
    entityinfo[41][0] = 0;
    entityinfo[42][0] = 0;

    /*
    entityinfo[0][] = 0;
    entityinfo[1][] = 0;
    entityinfo[2][] = 0;
    entityinfo[3][] = 0;
    entityinfo[4][] = 0;
    entityinfo[5][] = 0;
    entityinfo[6][] = 0;
    entityinfo[7][] = 0;
    entityinfo[8][] = 0;
    entityinfo[9][] = 0;
    entityinfo[10][] = 0;
    entityinfo[11][] = 0;
    entityinfo[12][] = 0;
    entityinfo[13][] = 0;
    entityinfo[14][] = 0;
    entityinfo[15][] = 0;
    entityinfo[16][] = 0;
    entityinfo[17][] = 0;
    entityinfo[18][] = 0;
    entityinfo[19][] = 0;
    entityinfo[20][] = 0;
    entityinfo[21][] = 0;
    entityinfo[22][] = 0;
    entityinfo[23][] = 0;
    entityinfo[24][] = 0;
    entityinfo[25][] = 0;
    entityinfo[26][] = 0;
    entityinfo[27][] = 0;
    entityinfo[28][] = 0;
    entityinfo[29][] = 0;
    entityinfo[30][] = 0;
    entityinfo[31][] = 0;
    entityinfo[32][] = 0;
    entityinfo[33][] = 0;
    entityinfo[34][] = 0;
    entityinfo[35][] = 0;
    entityinfo[36][] = 0;
    entityinfo[37][] = 0;
    entityinfo[38][] = 0;
    entityinfo[39][] = 0;
    entityinfo[40][] = 0;
    entityinfo[41][] = 0;
    entityinfo[42][] = 0;
    */
}

entity::~entity()
{
    //dtor
}
