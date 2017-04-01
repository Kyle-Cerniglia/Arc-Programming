#include "catalogship.h"

using namespace std;


char *f89xs = "F-89X";
double f89x[23];
char *astrixs = "Astrix";
double astrix[23];

//Density of steel is 8000 kg/m^3
catalogship::catalogship()//Catalog of ship data
{//[0]#id, [1]class(Fighter:0 Frig:1 dessie:2 cruiser:3 BC:4 BS:5 Carrier:6 Dread:7 Mining:8 Freight:9 Structure:10)
 //[2]module size (0=fighter 1=S 2=M 3=L), [3]mass, [4]length, [5]ammo size, [6]cargo size, [7]hull HP
 //[8]reactor slot, [9]capacitor slot, [10]shield slot,
 //[11]sublights slot, [12]manuvering slot, [13]hyperdrive slot, [14]lr sensors slot, [15]sr sensors slot
 //[16]subspace radio slot, [17]life support slot, [18]inertial dampeners slot, [19]weapon slots, [20]ammo slots
 //[21]armor slot

 //[22]reactor power bonus, [22]reactor EXP bonus, [23]capacitor bonus, [24]shield HP bonus, [24]shield regen bonus,
 //[24]shield cap bonus, [25]sublights bonus, [26]manuvering bonus, [27]hyperdrive speed bonus, [27]hyperdrive cap bonus
 //[28]lr sensors range bonus, [28]lr sensors ratio bonus, [29]sr sensors range bonus, [29]sr sensors target # bonus
 //[30]subspace radio bonus, [31]life support bonus, [32]inertial dampeners bonus,
 //[33]weapon damage bonus, [33]weapon range bonus, [33]weapon reload bonus, [33]weapon cap bonus
 //[35]armor bonus

 //[22]hitbox (m radius)

    f89x[0] = 1;        //id
    f89x[1] = 0;        //class
    f89x[2] = 0;        //module size
    f89x[3] = 169457;   //mass
    f89x[4] = 12.5;     //length
    f89x[5] = 3;        //ammo cap
    f89x[6] = 0.1;      //cargo cap
    f89x[7] = 200;      //hull hp's
    f89x[8] = 1;        //reactor slot
    f89x[9] = 1;        //capacitor slot
    f89x[10] = 1;       //shield slot
    f89x[11] = 0;       //sublights slot
    f89x[12] = 1;       //manuvering thruster slot
    f89x[13] = 0;       //hyperdrive slot
    f89x[14] = 0;       //lr sensors slot
    f89x[15] = 1;       //sr sensors slot
    f89x[16] = 0;       //subspace radio slot
    f89x[17] = 1;       //life support slot
    f89x[18] = 1;       //inertial dampeners slot
    f89x[19] = 2;       //weapons
    f89x[20] = 1;       //ammo slots
    f89x[21] = 0;       //armor slot

    f89x[22] = 6;       //hitbox radius


    astrix[0] = 2;        //id
    astrix[1] = 0;        //class
    astrix[2] = 0;        //module size
    astrix[3] = 0;   //mass
    astrix[4] = 0;     //length
    astrix[5] = 0;        //ammo cap
    astrix[6] = 0;      //cargo cap
    astrix[7] = 100;      //hull hp's
    astrix[8] = 1;        //reactor slot
    astrix[9] = 1;        //capacitor slot
    astrix[10] = 1;       //shield slot
    astrix[11] = 0;       //sublights slot
    astrix[12] = 1;       //manuvering thruster slot
    astrix[13] = 0;       //hyperdrive slot
    astrix[14] = 0;       //lr sensors slot
    astrix[15] = 1;       //sr sensors slot
    astrix[16] = 0;       //subspace radio slot
    astrix[17] = 1;       //life support slot
    astrix[18] = 1;       //inertial dampeners slot
    astrix[19] = 2;       //weapons
    astrix[20] = 0;       //ammo slots
    astrix[21] = 0;       //armor slot

    astrix[22] = 0;       //hitbox radius
}

catalogship::~catalogship()
{
    //dtor
}
