// Rotary Encoder Inputs
//CLKs attatched to pins 2 and 3 for interrupts
//right
#define CLK_2 2
#define DT_2 5
//left
#define CLK 3
#define DT 6
//#define SW 6

int counterL = 0;
int counterR = 0;
int currentStateCLK;
int currentStateCLKR;
int currentDT;
int currentDTR;
//int lastStateCLK;
//String currentDir ="";
//unsigned long lastButtonPress = 0;
//unsigned long secondCount=0;
//int lastTick=0;
//int totalDistance=0;

void setup() {
  // Set encoder pins as inputs
  pinMode(CLK_2,INPUT);
  pinMode(CLK, INPUT);
  pinMode(DT_2, INPUT);
  pinMode(DT,INPUT);
//  pinMode(SW, INPUT_PULLUP);
  //for left
  attachInterrupt(digitalPinToInterrupt(CLK), outP,CHANGE);
  attachInterrupt(digitalPinToInterrupt(CLK_2), outP, CHANGE);
  //for left
//  attachInterrupt(digitalPinToInterrupt(DT_2), outR, CHANGE);
  Serial.begin(9600);

  // Read the initial state of CLK
//  lastStateCLK = digitalRead(CLK);
}

//left
void outP() {
  currentStateCLK = digitalRead(CLK);
  currentStateCLKR = digitalRead(CLK_2);
  currentDT = digitalRead(DT);
  currentDTR = digitalRead(DT_2);
  if(currentStateCLK == 1) {
    if(currentDT != currentStateCLK) {
      counterL --;
    }
    else {
      counterL ++;
    }
  }
  if(currentStateCLKR == 1){
    if(currentDTR != currentStateCLKR) {
      counterR --;
    }
    else {
      counterR ++;
    }
  }
  
  Serial.print(counterL);
  Serial.print(" ");
  Serial.print(counterR);
  Serial.println();
}

////right
//void outR() {
//  currentStateCLK = digitalRead(CLK_2);
//  currentDT = digitalRead(DT_2);
//  if(currentStateCLK == 1) {
//    if(currentDT != currentStateCLK) {
//      counterR --;
//    }
//    else {
//      counterR ++;
//    }
//  }
//  Serial.print(counterL);
//  Serial.print(counterR);
//  Serial.println();
//}


void loop() {
// 
//  // Read the current state of CLK
//  currentStateCLK = digitalRead(CLK);
//
//  // If last and current state of CLK are different, then pulse occurred
//  // React to only 1 state change to avoid double count
//  if (currentStateCLK != lastStateCLK  && currentStateCLK == 1){
//
//    // If the DT state is different than the CLK state then
//    // the encoder is rotating CCW so decrement
//    if (digitalRead(DT) != currentStateCLK) {
//      counter --;
//      currentDir ="CCW";
//    } else {
//      // Encoder is rotating CW so increment
//      counter ++;
//      currentDir ="CW";
//    }
//    Serial.println(counter);
//  }
//  if(millis()-secondCount>1000){
//    Serial.print(counter);
//    Serial.print("\t");
//    Serial.println(lastTick);
//    Serial.print(secondCount);
//    Serial.print("\t");
//    Serial.println(millis());
//    totalDistance+=counter;
//    lastTick=counter;
//    secondCount=millis();
//  }
//  // Remember last CLK state
//  lastStateCLK = currentStateCLK;
//
//  // Read the button state
//  int btnState = digitalRead(SW);
//
//  //If we detect LOW signal, button is pressed
//  if (btnState == LOW) {
//    //if 50ms have passed since last LOW pulse, it means that the
//    //button has been pressed, released and pressed again
//    if (millis() - lastButtonPress > 50) {
//      Serial.println("Button pressed!");
//    }
//
//    // Remember last button press event
//    lastButtonPress = millis();
//  }
//
//  // Put in a slight delay to help debounce the reading
//  delay(1);
}
