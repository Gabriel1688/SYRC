// Rotary Encoder Inputs
//CLKs attatched to pins 2 and 3 for interrupts
//right
#define CLK_2 2
#define DT_2 3

int counter = 0;
int lasCount = 0;
int currentCLK;
int currentDT;
int CLK;
int DT;
byte last;
bool skip_val = true;
// [cur][las]
const int dirMap[4][4] = {{0,-1,1,0},
                          {1,0,0,-1},
                          {-1,0,0,1},
                          {0,1,-1,0}};
//0 is CW


void setup() {
  // Set encoder pins as inputs
  pinMode(CLK_2,INPUT);
  pinMode(DT_2, INPUT);
  
  Serial.begin(9600);

}

//left
void outP() {
  lasCount = counter;
  byte current;
  currentCLK = digitalRead(CLK_2);
  currentDT = digitalRead(DT_2);
  current = (currentCLK << 1) | (currentDT);
  last = (CLK << 1) | (DT);
  counter += dirMap[current][last];
  CLK = currentCLK;
  DT = currentDT;
  if (counter != lasCount) {
    Serial.println(counter);
    Serial.println();
  }
  
}

void loop() {
   outP();
 
}
