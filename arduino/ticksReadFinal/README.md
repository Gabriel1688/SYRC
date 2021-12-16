**Formatting will be corrected**

This is the final code responsible for reading directly from rotary encoders. 

First, I referred to the two sets of Pulse Width Square Wave outputs from our rotary encoder(A/B or CLK/DT). 
If I split the waves into 4 seperate states, I can make a table of values that continously repeat when the encoder recieves ticks in a any certain direction:

CCW rotation:

A | B
-----
0 | 0
1 | 0
1 | 1
0 | 1

CW rotation:

A | B
-----
0 | 0
0 | 1
1 | 1
1 | 0

If you notice, in each table, signals from waves A and B can be taken as Binary values, with 01 being 1, or 11 being 3. When I recieve signals from both, I can use binary arithmetic to create an equivalent Binary value to represent the state. The tables re-written would be:

CCW
A | B
-----
  0
  2
  3
  1

CW
A | B
-----
  0
  1
  3
  2

The integer counter will be printed any time I reviece an increase or decrease in movement, and counter will be incremented accordingly. However, for every signal, counter can only be increased or decreased by one at the most. Therefore, I can create a 2-dimensional array of either, 1, -1, 0 for values to add to counter. 
Before explaining the array, however, the logic used to determine whether or not to emply the array in any instance must be explained. For A and B, i record the last values, and keep them in account when considering current values. For example, first i recieve a 0, the last value has been initialized to 0, so 0 to 0 is +0, therefore 0,0 in the array stores val 0. Next i get 1, so 0,1 is a CW increase so 0,1 in the array stores +1, etc . . . 
These can be organized under the binary values 0,1,2,3 to pick the correct increment accoring to the current state ; each column under last recorded values & each row under current values. CCW movement indicated subtraction, CW indicated positive increment. The array can be represented as follows:

    | 0 | 1 | 2 | 3 |
   -|----------------
   0| 0 | -1| 1 | x |
   1| 1 | 0 | x | -1| 
   2| -1| x | 0 | 1 |   
   3| x | 1 | -1| 0 |
   
 When get values, i take my last vals and my current vals, plug them into the array, and recieve the appropriate increment. I then print out the counter whenever i recieve an increment (not equal to the last recorded counter value, same logic).
 
