#include "Arduino.h"

#ifndef TICKSREAD_H
#define TICKSREAD_H

#define CLK 4
#define DT 5
//right
#define CLK2 2
#define DT2 3







struct retVal {

  int lastTick;
  int counter;
  
};



void wheelRight(int CLK1, int DT1);

void wheelLeft(int CLK3, int DT3);

#endif
