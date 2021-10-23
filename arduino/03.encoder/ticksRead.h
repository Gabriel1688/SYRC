#include "Arduino.h"

#ifndef TICKSREAD_H
#define TICKSREAD_H



int rLastStateCLK;
int lLastStateCLK;
int lCounter = 0;
int lLastTick = 0;
int rCounter = 0;
int rLastTick = 0;
int rCurrentStateCLK;
unsigned long secondCount = 0;
int lCurrentStateCLK;


struct retVal {

  int lastTick;
  int counter;
  
};
struct retVal r;
struct retVal l;

void wheelRight(int CLK1, int DT1){
  

  };

void wheelLeft(int CLK3, int DT3){
  

  };

#endif
