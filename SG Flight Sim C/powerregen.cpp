#include "powerregen.h"

using namespace std;

extern double entityinfo[59][220];
extern double timewait;

static int y;

powerregen::powerregen()
{
    while(y <= 220){
        if(entityinfo[33][y] == 0 && entityinfo[34][y] == 0 && entityinfo[26][y] < entityinfo[58][y]){//Recharge cap
            entityinfo[26][y] = entityinfo[26][y] + entityinfo[33][y] * timewait;
            y++;
        }
        if(entityinfo[33][y] == 0 && entityinfo[34][y] == 1 && entityinfo[26][y] < (entityinfo[58][y] / 2)){//Recharge damaged cap
            entityinfo[26][y] = entityinfo[26][y] + entityinfo[33][y] * timewait;
            y++;
        }
        if(entityinfo[33][y] == 1 && entityinfo[34][y] == 0 && entityinfo[26][y] < entityinfo[58][y]){//Recharge cap
            entityinfo[26][y] = entityinfo[26][y] + (entityinfo[33][y] / 2) * timewait;
            y++;
        }
        if(entityinfo[33][y] == 1 && entityinfo[34][y] == 2 && entityinfo[26][y] < (entityinfo[58][y] / 2)){//Recharge cap
            entityinfo[26][y] = entityinfo[26][y] + (entityinfo[33][y] / 2) * timewait;
            y++;
        }
        else{
            y++;
        }
    }
    y = 0;
}

powerregen::~powerregen()
{
    //dtor
}
