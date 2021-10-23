#include "Arduino.h"
#include "ticksRead.h"

int rLastStateCLK;// = digitalRead(CLK);
int lLastStateCLK;// = digitalRead(CLK2);
struct retVal r;
struct retVal l;
int lCurrentStateCLK;
int rCurrentStateCLK;
unsigned long secondCount = 0;
int lCounter =0;
int lLastTick =0;
int rCounter =0;
int rLastTick = 0;

void wheelRight(int CLK1, int DT1){

// handles ticks and counter
  rCurrentStateCLK = digitalRead(CLK1);

  if (rCurrentStateCLK != rLastStateCLK  && rCurrentStateCLK == 1){

    if (digitalRead(DT1) != rCurrentStateCLK) {
      rCounter --;
    } 
    else {

      rCounter ++;
    }
    //updates structs every second
    

    rLastStateCLK = rCurrentStateCLK; 
  }
  if(millis()-secondCount>1000){
      r.lastTick = rLastTick;
      r.counter = rCounter;
      rLastTick = rCounter;
      l.lastTick = lLastTick;
      l.counter = lCounter;
      lLastTick = lCounter;
      secondCount=millis();
    }
}

void wheelLeft(int CLK3, int DT3){


//handles counter and ticks
  lCurrentStateCLK = digitalRead(CLK3);

  if (lCurrentStateCLK != lLastStateCLK  && lCurrentStateCLK == 1){

    if (digitalRead(DT3) != lCurrentStateCLK) {
      lCounter --;
    } 
    else {

      lCounter ++;

    }

    lLastStateCLK = lCurrentStateCLK;  
  };
}
