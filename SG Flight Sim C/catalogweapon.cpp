#include "catalogweapon.h"

using namespace std;

char *railsms = "Small Railgun";
int railsm[8];
char *aim120as = "AIM 120A";
int aim120a[8];

catalogweapon::catalogweapon()
{//[0]#id, [1]dmg/round or second, [2]speedmax(m/s), [3]accel(m/sec^2), [4]mass(kg), [5]range(m), [6]rnds/sec, [7]power(GJ/round or second)
    railsm[0] = 1;
    railsm[1] = 5;
    railsm[2] = 1600;
    railsm[3] = 160000;
    railsm[4] = 1;
    railsm[5] = 50000;
    railsm[6] = 8;
    railsm[7] = 10;

    aim120a[0] = 2;
    aim120a[1] = 100;
    aim120a[2] = 600;
    aim120a[3] = 40;
    aim120a[4] = 50;
    aim120a[5] = 2000;
    aim120a[6] = 1;
    aim120a[7] = 1;
}

catalogweapon::~catalogweapon()
{
    //dtor
}
