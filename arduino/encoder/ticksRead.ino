
#include "ticksRead.h"


// Rotary Encoder Inputs
//left
#define CLK 4
#define DT 5
//right
#define CLK2 2
#define DT2 3



void setup() {
  // Set encoder pins as inputs
  pinMode(CLK,INPUT);
  pinMode(CLK2, INPUT);
  pinMode(DT,INPUT);
  pinMode(DT2, INPUT);

  Serial.begin(9600);

  // Read the initial state of CLK
  rLastStateCLK = digitalRead(CLK);
  lLastStateCLK = digitalRead(CLK2);
}

void loop() {
  

  wheelLeft(CLK2, DT2);
  wheelRight(CLK, DT);

  Serial.print("Left Encoder current ticks: ");
  Serial.print(l.counter);
  Serial.print(" last tick: ");
  Serial.print(l.lastTick);
  Serial.print("     ");
  Serial.println("Right Encoder current ticks: ");
  Serial.print(r.counter);
  Serial.print(" last tick: ");
  Serial.print(r.lastTick);
  
  delay(1);
}
