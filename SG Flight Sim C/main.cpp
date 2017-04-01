#include "console.h"
#include "ent1position.h"
#include "raycasting1.h"
#include "navigation.h"
#include "keyinput.h"
#include "catalogcelestial.h"
#include "gamemenu.h"
#include "catalogship.h"
#include "entityconsole.h"
#include "shipload.h"
#include "hyperdrive.h"
#include "catalogweapon.h"
#include "weaponfire.h"
#include "railsmentity.h"
#include "gui.h"
#include "shieldregen.h"
#include "testsettings.h"
#include "powerregen.h"
#include "shipmodulestatus.h"
#include "hitboxcollision.h"
#include "catalogindustry.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include <windows.h>
#include <iostream>
#include <unistd.h>

using namespace std;


//Location variables
double x = 0;           //X position
double y = 0;           //Y position
double z = 0;           //Z position
double pitch = 0;       //Pitch
double yaw = 0;         //Yaw
double galx = 0;        //Galactic X
double galy = 0;        //Galactic Y
double galz = 0;        //Galactic Z
int galaxy = 0;         //Galaxy

double xent1 = 0;       //X loc of ent1
double yent1 = 0;       //Y loc of ent1
double zent1 = 2;       //Z loc of ent1

double ent1distance = 0;//Distance to ent1
double ent1yaw = 0;     //Yaw angle to ent1
double ent1pitch = 0;   //Pitch angle to ent1

//Key var's
bool W = false;
bool A = false;
bool S = false;
bool D = false;
bool Q = false;
bool E = false;
bool C = false;
bool M = false;
bool rUP = false;
bool rDOWN = false;
bool rLEFT = false;
bool rRIGHT = false;
bool SPACE = false;

//Velocity variables
bool xspeedcheck = false;//X speed check for current tick
bool yspeedcheck = false;//Y speed check for current tick
bool zspeedcheck = false;//Z speed check for current tick
bool yawspeedcheck = false;//Yaw speed check for current tick
bool pitchspeedcheck = false;//Pitch speed check for current tick
double speeddeccel = 1;
double rotationspeeddeccel = 0.01;

//Time variables
double timeref = 0;     //Time reference point
double timewait = 0.01;  //Amount of time to wait, sysclock 0.01

//Raycasting variables
double xray = 0;
double xraymin = 0;
double xraymax = 0;
double yray = 0;
double yraymin = 0;
double yraymax = 0;
double ent1hitbox = 1;

//Ship and module common variables
char *shiptype;
int shipid = 0;
double shipmaxspeed = 0;
double shipaccel = 0;
double shipmass = 0;
int shipgun = 0;
int shipmissile = 0;
int shipgunammo = 0;
int shipmissileammo = 0;
double shiphitbox = 0;
double shipshieldhp = 0;
double shipshieldregen = 0;
double shiphullhp = 0;
double shippower = 0;
double shippowerregen = 0;
double shiphyperdrivespeed = 0;
double shiphyperdrive = 0;
double massenergy = .0000000434;//Mass to energy ratio for hyperdrive
double xshipaccel = 0;
double yshipaccel = 0;
double bshipaccel = 0;
double xshipmaxspeed = 0;
double yshipmaxspeed = 0;
double bshipmaxspeed = 0;
double rotationmaxspeed;

//GUI
char *special1;


        double missilex = 0;
        double missiley = 0;
        double missilez = 0;
        double missilepitch = 0;
        double missileyaw = 0;
        double missilespeed = 0;
        double missilespeedmax = 0;

//Entities
double entitylocation[8][1000];//gal are in LY, local are in km
//[0]id, [1]galaxy [2]galx, [3]galy, [4]galz, [5]x, [6]y, [7]z

double entityvelocity[8][1000];//Angles are in rad, speed is in m/s
//[0]id, [1]pitch, [2]pitch speed, [3]yaw, [4]yaw speed, [5]xspeed, [6]yspeed, [7]zspeed

double entitymodule[13][1000];//module status (-1 no mod, 0 online, 1 damaged, 2 offline)
//[0]id, [1]hyperdrive, [2]sublights, [3]shields, [4]reactor, [5]capacitor, [6]LR sensors, [7]SR sensors
//[8]beacon, [9]inertial, [10]manuvering, [11]ammo, [12]life

double entityhitbox[2][1000];
//[0]id, [1]HB radius (m)

double entityinfo[4][1000];
//[0]id, [1]typeid (1=PShip 2=AIShip 3=Static 4=charge 5=missile), [2]targetable?, [3]dmg receive

double entitystat[24][1000];//normal speed are in m/s, normal accel is in m/s^2, rotation is in rad/s, and rotational
//accel is in rad/s^2
//[0]id, [1]hyperdrive speed (LY/s), [2]hyperdrive cap use (GJ/s), [3]max +Z speed, [4]max -Z speed, [5]max strafe speed
//[6]max rotation speed, [7]+Z accel, [8]-Z accel, [9]strafe accel, [10]rotation speed accel
//[11]mass (kg), [12]volume(m^3), [13]cargo (m^3), [14]ammo cargo (m^3), [15]hull HP max, [16]hull HP, [17]shield HP max
//[18]shield HP, [19]shield regen (HP/s), [20]shield regen cap (GJ/use), [21]power max (GJ), [22]power (GJ)
//[23]power regen (GJ/s),

double entityweapon[11][1000];
//[0]id, [1]weapon id, [2]weapon type (1=projectile 2=laser 3=missile, [3]tracking? ,[4]weapon slot, [5]damage modifier
//[6]range modifier, [7]reload time (s), [8]cap use (GJ), [9]tracking speed (rad/s), [10]module damage modifier

//Other variables
double pi = 3.14159265359;//Value of pi
char *console1;         //Generic char output to console
double abstemp1 = 0;    //Temp double var for abs calc
double abstemp2 = 0;    //Temp double var for abs calc
double temp1 = 0;       //Temp double var
double temp2 = 0;       //Temp double var
char *tempa;            //Temp char var
char *tempb;            //Temp char var
int testvar = 0;        //Troubleshooting variable
bool menupause = false; //Menu pause
int random = 0;
bool locreset = false;


int main()//Executes all of the classes
{
    system("mode 650");
    catalogcelestial();
    catalogweapon();
    catalogship();
    shipload();
    menupause = false;
    while(1){
        random = rand();
        Sleep(timewait);
        keyinput();
        gamemenu();
        navigation();
        shieldregen();
        testsettings();
        gui();
    }
    return 0;
}
