// Rotary Encoder Inputs
//CLKs attatched to pins 2 and 3 for interrupts
//right
#define CLK_2 2
#define DT_2 5
//left
#define CLK 3
#define DT 6

int counterL = 0;
int counterR = 0;
int currentStateCLK;
int currentStateCLKR;
int currentDT;
int currentDTR;

void setup() {
  // Set encoder pins as inputs
  pinMode(CLK_2,INPUT);
  pinMode(CLK, INPUT);
  pinMode(DT_2, INPUT);
  pinMode(DT,INPUT);


  attachInterrupt(digitalPinToInterrupt(CLK), outP,CHANGE);
  attachInterrupt(digitalPinToInterrupt(CLK_2), outP, CHANGE);


  Serial.begin(9600);

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
    else if(currentDT == currentStateCLK){
      counterL ++;
    }
  }

  
  Serial.print(counterL);
  Serial.print(" ");
  Serial.print(counterR*-1);
  Serial.println();
}

//right
void outR() {
  currentStateCLK = digitalRead(CLK_2);
  currentDT = digitalRead(DT_2);
  if(currentStateCLK == 1) {
    if(currentDT != currentStateCLK) {
      counterR --;
    }
    else if(currentDTR == currentStateCLKR){
      counterR ++;
    }
  }
  Serial.print(counterL);
  Serial.print(counterR);
  Serial.println();
}


void loop() {
}
