#include "shieldregen.h"

using namespace std;

extern double entitymodule[13][1000];
extern double entitystat[24][1000];
extern double timewait;

static int y = 0;

shieldregen::shieldregen()//Regen at 0.25GJ/hp
{
    while(y <= 220){
        if(entitymodule[3][y] == 0 && entitystat[18][y] < entitystat[17][y] && entitystat[22][y] >= 0.25){
            entitystat[18][y] = entitystat[18][y] + entitystat[19][y] * timewait;
            entitystat[22][y] = entitystat[22][y] - entitystat[19][y] * timewait * 0.25;
            y++;
        }
        if(entitymodule[3][y] == 1 && entitystat[18][y] < entitystat[17][y] && entitystat[22][y] >= 0.25){
            entitystat[18][y] = entitystat[18][y] + (entitystat[19][y] / 2) * timewait;
            entitystat[22][y] = entitystat[22][y] - (entitystat[19][y] / 2) * timewait * 0.25;
            y++;
        }
        else{
            y++;
        }
    }
    y = 0;
}

shieldregen::~shieldregen()
{
    //dtor
}
