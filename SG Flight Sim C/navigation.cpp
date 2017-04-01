#include "navigation.h"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include <windows.h>

using namespace std;


extern bool W;
extern bool S;
extern bool A;
extern double pi;
extern bool D;
extern bool E;
extern bool Q;
extern bool C;
extern bool rUP;
extern bool rDOWN;
extern bool rLEFT;
extern bool rRIGHT;
extern double timewait;
extern double speeddeccel;
extern double rotationspeeddeccel;
extern bool locreset;
extern double thetaxz;
extern double thetay;
extern bool menupause;
extern double entitylocation[8][1000];
extern double entityvelocity[8][1000];
extern double entitystat[24][1000];

static double temphypox = 0;
static double temphypoy = 0;
static double temphypoz = 0;
static double xnew = 0;
static double ynew = 0;
static double znew = 0;
static double xpitch = 0;
static double xyaw = 0;
static double ypitch = 0;
static double yyaw = 0;

navigation::navigation()//Motion control of your ship
{
    if(menupause == false){
        if(C){//Reset
            entitylocation[5][0] = 0;
            entitylocation[6][0] = 0;
            entitylocation[7][0] = 0;
            entityvelocity[1][0] = 0;
            entityvelocity[3][0] = 0;
            entityvelocity[5][0] = 0;
            entityvelocity[6][0] = 0;
            entityvelocity[7][0] = 0;
            entityvelocity[2][0] = 0;
            entityvelocity[4][0] = 0;
        }

        if(locreset){
            entitylocation[5][0] = 0;
            entitylocation[6][0] = 0;
            entitylocation[7][0] = 0;
            entityvelocity[1][0] = thetay;
            entityvelocity[3][0] = thetaxz;
            entityvelocity[5][0] = 0;
            entityvelocity[6][0] = 0;
            entityvelocity[7][0] = entitystat[3][0] / 10;
            entityvelocity[2][0] = 0;
            entityvelocity[4][0] = 0;
            locreset = false;
        }

        //Speed acceleration
        if(W && entityvelocity[7][0] <= entitystat[3][0]){//Forward
            entityvelocity[7][0] = entityvelocity[7][0] + entitystat[7][0] * timewait;
        }
        else if(entityvelocity[7][0] > 0 && !S){//Drift forward
            entityvelocity[7][0] = entityvelocity[7][0] - speeddeccel * timewait;
        }

        if(A && entityvelocity[5][0] >= -entitystat[5][0]){//Left
            entityvelocity[5][0] = entityvelocity[5][0] - entitystat[9][0] * timewait;
        }
        else if(entityvelocity[5][0] < 0 && !D){//Drift left
            entityvelocity[5][0] = entityvelocity[5][0] + speeddeccel * timewait;
        }

        if(S && entityvelocity[7][0] >= entitystat[4][0]){//Backward
            entityvelocity[7][0] = entityvelocity[7][0] - entitystat[8][0] * timewait;
        }
        else if(entityvelocity[7][0] < 0 && !W){//Backward drift
            entityvelocity[7][0] = entityvelocity[7][0] + speeddeccel * timewait;
        }

        if(D && entityvelocity[5][0] <= entitystat[5][0]){//Right
            entityvelocity[5][0] = entityvelocity[5][0] + entitystat[9][0] * timewait;
        }
        else if(entityvelocity[5][0] > 0 && !A){//Right drift
            entityvelocity[5][0] = entityvelocity[5][0] - speeddeccel * timewait;
        }

        if(Q && entityvelocity[6][0] >= -entitystat[5][0]){//Up
            entityvelocity[6][0] = entityvelocity[6][0] - entitystat[9][0] * timewait;
        }
        else if(entityvelocity[6][0] < 0 && !E){//Drift up
            entityvelocity[6][0] = entityvelocity[6][0] + speeddeccel * timewait;
        }

        if(E && entityvelocity[6][0] <= entityvelocity[5][0]){//Down
            entityvelocity[6][0] = entityvelocity[6][0] + entitystat[9][0] * timewait;
        }
        else if(entityvelocity[6][0] > 0 && !Q){//Drift down
            entityvelocity[6][0] = entityvelocity[6][0] - speeddeccel * timewait;
        }

        //Temp var resets
        xnew = 0;
        ynew = 0;
        znew = 0;

        //Near zero speed reset
        if(entityvelocity[5][0] < 0.01 && entityvelocity[5][0] > -0.01 && !D && !A){
            entityvelocity[5][0] = 0;
        }
        if(entityvelocity[6][0] < 0.01 && entityvelocity[6][0] > -0.01 && !E && !Q){
            entityvelocity[6][0] = 0;
        }
        if(entityvelocity[7][0] < 0.01 && entityvelocity[7][0] > -0.01 && !W && !S){
            entityvelocity[7][0] = 0;
        }

        //Rotation speed acceleration
        if(rUP && entityvelocity[2][0] <= entitystat[6][0]){
            entityvelocity[2][0] = entityvelocity[2][0] + entitystat[10][0] * timewait;
        }
        else if(entityvelocity[2][0] > 0 && !rDOWN){
            entityvelocity[2][0] = entityvelocity[2][0] - rotationspeeddeccel * timewait;
        }

        if(rDOWN && entityvelocity[2][0] >= -entitystat[6][0]){
            entityvelocity[2][0] = entityvelocity[2][0] - entitystat[10][0] * timewait;
        }
        else if(entityvelocity[2][0] < 0 && !rUP){
            entityvelocity[2][0] = entityvelocity[2][0] + rotationspeeddeccel * timewait;
        }

        if(rLEFT && entityvelocity[4][0] >= -entitystat[6][0]){
            entityvelocity[4][0] = entityvelocity[4][0] - entitystat[10][0] * timewait;
        }
        else if(entityvelocity[4][0] < 0 && !rRIGHT){
            entityvelocity[4][0] = entityvelocity[4][0] + rotationspeeddeccel * timewait;
        }

        if(rRIGHT && entityvelocity[4][0] <= entitystat[6][0]){
            entityvelocity[4][0] = entityvelocity[4][0] + entitystat[10][0] * timewait;
        }
        else if(entityvelocity[4][0] > 0 && !rLEFT){
            entityvelocity[4][0] = entityvelocity[4][0] - rotationspeeddeccel * timewait;
        }

        //Near zero rotation speed reset
        if(entityvelocity[2][0] < 0.0001 && entityvelocity[2][0] > -0.0001 && !rUP && !rDOWN){
            entityvelocity[2][0] = 0;
        }
        if(entityvelocity[4][0] < 0.0001 && entityvelocity[4][0] > -0.0001 && !rLEFT && !rRIGHT){
            entityvelocity[4][0] = 0;
        }

        //Rotation change
        entityvelocity[1][0] = entityvelocity[1][0] + entityvelocity[2][0] * timewait;
        if(entityvelocity[1][0] > pi){
            entityvelocity[1][0] = -pi;
        }
        if(entityvelocity[1][0] < -pi){
            entityvelocity[1][0] = pi;
        }

        entityvelocity[3][0] = entityvelocity[3][0] + entityvelocity[4][0] * timewait;
        if(entityvelocity[3][0] < -pi){
            entityvelocity[3][0] = pi;
        }
        if(entityvelocity[3][0] > pi){
            entityvelocity[3][0] = -pi;
        }

        //X coord change
        xyaw = entityvelocity[3][0] + pi / 2;
        if(xyaw > pi){
            xyaw = -pi + (xyaw - pi);
        }
        temphypox = entityvelocity[5][0] * cos(entityvelocity[1][0]);
        xnew = xnew + temphypox * cos(entityvelocity[3][0]);
        znew = znew - temphypox * sin(entityvelocity[3][0]);

        //Y coord change
        ypitch = entityvelocity[1][0] + pi / 2;
        if(ypitch > pi){
            ypitch = -pi + (ypitch - pi);
        }
        temphypoy = entityvelocity[6][0] * cos(ypitch);
        xnew = xnew + temphypoy * sin(entityvelocity[3][0]);
        ynew = ynew + entityvelocity[6][0] * cos(entityvelocity[1][0]);
        znew = znew + temphypoy * cos(entityvelocity[3][0]);

        //Z coord change
        temphypoz = entityvelocity[7][0] * cos(entityvelocity[1][0]);
        xnew = xnew + temphypoz * sin(entityvelocity[3][0]);
        ynew = ynew + entityvelocity[7][0] * sin(entityvelocity[1][0]);
        znew = znew + temphypoz * cos(entityvelocity[3][0]);

        //Coord write
        entityvelocity[5][0] = entityvelocity[5][0] + xnew * timewait;
        entityvelocity[6][0] = entityvelocity[6][0] + ynew * timewait;
        entityvelocity[7][0] = entityvelocity[7][0] + znew * timewait;
    }
}

navigation::~navigation()
{
    //dtor
}
