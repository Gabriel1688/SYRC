#include "Arduino.h"
#include "ticksRead.h"


void wheelRight(){

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

void wheelLeft(){


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
