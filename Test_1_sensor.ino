/*************************************************
 *  This program is written for controlling      * 
 *  of traffic lights, according to the vehicle  *
 *  density on each road, towards specific       *
 *  direction.                                   *
 *************************************************/

/* Assigning names to analog pins. They are going to be used as inputs. */
const int R1_A1 = A0; 
const int R1_A2 = A1;
//const int R1_B1 = A2;
//const int R1_B2 = A3;
const int R2_A1 = A4;
const int R2_A2 = A5;
//const int R2_B1 = A6;
//const int R2_B2 = A7;
const int R3_A1 = A8;
const int R3_A2 = A9;
//const int R3_B1 = A10;
//const int R3_B2 = A11;*/

/* Assigning names to digital pins. They are going to be used as outputs to LEDs. */
/* For Road 1 Lane A */
const int R1_A_Green = 35;
const int R1_A_Orange = 36;
const int R1_A_Red = 37;
/* For Road 1 Lane B */
/*const int R1_B_Green = 38;
const int R1_B_Orange = 39;
const int R1_B_Red = 40;
/* For Road 2 Lane A*/
const int R2_A_Green = 41;
const int R2_A_Orange = 42;
const int R2_A_Red = 43;
/* For Road 2 Lane B */
/*const int R2_B_Green = 44;
const int R2_B_Orange = 45;
const int R2_B_Red = 46;

/* For Road 3 Lane A */
const int R3_A_Green = 47;
const int R3_A_Orange = 48;
const int R3_A_Red = 49;
/* For Road 3 Lane B */
/*const int R3_B_Green = 50;
const int R3_B_Orange = 51;
const int R3_B_Red = 52;

/* variables for reading and storing analog values of each of the two sensors on one lane */
int Sensor_Value1 = 0;   
int Sensor_Value2 = 0;


/* This 'setup' program runs first and once. That is, it acts like the main program in C */
void setup() {
/* To define digital pins from 34 to 52 as digital outputs for LEDs */
   for(int x = 35; x <= 37; x++){
      pinMode(x, OUTPUT);
   }

   for(int x = 41; x <= 43; x++){
      pinMode(x, OUTPUT);
   }

   for(int x = 47; x <= 49; x++){
      pinMode(x, OUTPUT);
   }

   Serial.begin(9600);
}


/* This 'loop' program is executed iteratively, forever. The codes we want to iterate forever, we put in this 'loop' program */
void loop() {
   Road1_LaneA();     // calling the function for control of Road 1, Lane A 
   Road2_LaneA();     // calling the function for control of Road 2, Lane A 
   Road3_LaneA();     // calling the function for control of Road 3, Lane A 
   //Road1_LaneB();     // calling the function for control of Road 1, Lane B 
   //Road2_LaneB();     // calling the function for control of Road 2, Lane B 
   //Road3_LaneB();     // calling the function for control of Road 3, Lane B    
}


/* Definitions of functions used for checking each sensors at each lane, and to generate appropriate output */
/* Definition of function for Road 1, Lane A */
void Road1_LaneA(){
   Sensor_Value1 = analogRead(R1_A1);       // Read Sensor 1 of Lane A of Road 1
   if(Sensor_Value1 < 200){               // if it is high, (that is if vehicle is detected)
      delay(1000);
      Sensor_Value2 = analogRead(R1_A2);    // then read Sensor 2 of Lane A of Road 1.
      if(Sensor_Value2 < 200){            // if Sensor 2 value is high too, (that is if vehicle is detected)
         digitalWrite(R1_A_Red, LOW);       // turn off red light and,
         digitalWrite(R1_A_Orange, HIGH);      // turn Orange light on.
         delay(1000);                          // Wait for 1second
         digitalWrite(R1_A_Orange, LOW);
         digitalWrite(R1_A_Green, HIGH);    // turn green light on. Then,
         delay(10000);                      // wait for 20 seconds.
      }
      if(Sensor_Value2 > 200){        // if Sensor 2 value is low, (that is no vehicle is detected by sensor 2)
         digitalWrite(R1_A_Red, LOW);       // turn off red light and,
         digitalWrite(R1_A_Orange, HIGH);      // turn Orange light on.
         delay(1000);                          // Wait for 1second
         digitalWrite(R1_A_Orange, LOW);
         digitalWrite(R1_A_Green, HIGH);    // turn green light on. Then,
         delay(5000);                      // wait for 10 seconds.
      }
      digitalWrite(R1_A_Green, LOW);        // turn green light off.
      digitalWrite(R1_A_Orange, HIGH);      // turn Orange light on.
      delay(1000);                          // Wait for 1second
      digitalWrite(R1_A_Orange, LOW);       // Turn Orange ligh off.
      digitalWrite(R1_A_Red, HIGH);         // Turn Red light on.
   }
   Sensor_Value1 = 0;                       // clear sensor 1 value
   Sensor_Value2 = 0;                       // clear sensor 2 value
}

/* Definition of function for Road 1, Lane B */
/*void Road1_LaneB(){
   Sensor_Value1 = analogRead(R1_B1);
   if(Sensor_Value1 < 200){
      Sensor_Value2 = analogRead(R1_B2);
      if(Sensor_Value2 < 200){
         digitalWrite(R1_B_Red, LOW);
         digitalWrite(R1_B_Green, HIGH);
         delay(20000);  
      }
      else if(Sensor_Value2 > 200){
         digitalWrite(R1_B_Red, LOW);
         digitalWrite(R1_B_Green, HIGH);
         delay(10000);
      }
      digitalWrite(R1_B_Green, LOW);
      digitalWrite(R1_B_Orange, HIGH);
      delay(1000);
      digitalWrite(R1_B_Orange, LOW);
      digitalWrite(R1_B_Red, HIGH);
   }
   Sensor_Value1 = 0;
   Sensor_Value2 = 0;
}

/* Definition of function for Road 2, Lane A */
void Road2_LaneA(){
   Sensor_Value1 = analogRead(R2_A1);
   if(Sensor_Value1 < 200){
      Sensor_Value2 = analogRead(R2_A2);
      if(Sensor_Value2 < 200){
         digitalWrite(R2_A_Red, LOW);
         digitalWrite(R2_A_Orange, HIGH);
         delay(1000);
         digitalWrite(R2_A_Orange, LOW);
         digitalWrite(R2_A_Green, HIGH);
         delay(10000);  
      }
      if(Sensor_Value2 > 200){
         digitalWrite(R2_A_Red, LOW);
         digitalWrite(R2_A_Orange, HIGH);
         delay(1000);
         digitalWrite(R2_A_Orange, LOW);
         digitalWrite(R2_A_Green, HIGH);
         delay(5000);
      }
      digitalWrite(R2_A_Green, LOW);
      digitalWrite(R2_A_Orange, HIGH);
      delay(1000);
      digitalWrite(R2_A_Orange, LOW);
      digitalWrite(R2_A_Red, HIGH);
   }
   Sensor_Value1 = 0;
   Sensor_Value2 = 0;  
}

/* Definition of function for Road 2, Lane B */
/*void Road2_LaneB(){
   Sensor_Value1 = analogRead(R2_B1);
   if(Sensor_Value1 < 200){
      Sensor_Value2 = analogRead(R2_B2);
      if(Sensor_Value2 < 200){
         digitalWrite(R2_B_Red, LOW);
         digitalWrite(R2_B_Green, HIGH);
         delay(20000);  
      }
      else if(Sensor_Value2 > 200){
         digitalWrite(R2_B_Red, LOW);
         digitalWrite(R2_B_Green, HIGH);
         delay(10000);
      }
      digitalWrite(R2_B_Green, LOW);
      digitalWrite(R2_B_Orange, HIGH);
      delay(1000);
      digitalWrite(R2_B_Orange, LOW);
      digitalWrite(R2_B_Red, HIGH);
   }
   Sensor_Value1 = 0;
   Sensor_Value2 = 0;
}

/* Definition of function for Road 3, Lane A */
void Road3_LaneA(){
   Sensor_Value1 = analogRead(R3_A1);
   if(Sensor_Value1 < 200){
      Sensor_Value2 = analogRead(R3_A2);
      if(Sensor_Value2 < 200){
         digitalWrite(R3_A_Red, LOW);
         digitalWrite(R3_A_Orange, HIGH);
         delay(1000);
         digitalWrite(R3_A_Orange, LOW);
         digitalWrite(R3_A_Green, HIGH);
         delay(10000);  
      }
      if(Sensor_Value2 > 200){
         digitalWrite(R3_A_Red, LOW);
         digitalWrite(R3_A_Orange, HIGH);
         delay(1000);
         digitalWrite(R3_A_Orange, LOW);
         digitalWrite(R3_A_Green, HIGH);
         delay(5000);
      }
      digitalWrite(R3_A_Green, LOW);
      digitalWrite(R3_A_Orange, HIGH);
      delay(1000);
      digitalWrite(R3_A_Orange, LOW);
      digitalWrite(R3_A_Red, HIGH);
   }
   Sensor_Value1 = 0;
   Sensor_Value2 = 0;
}

/* Definition of function for Road 3, Lane B */
/*void Road3_LaneB(){
   Sensor_Value1 = analogRead(R3_B1);
   if(Sensor_Value1 < 200){
      Sensor_Value2 = analogRead(R3_B2);
      if(Sensor_Value2 < 200){
         digitalWrite(R3_B_Red, LOW);
         digitalWrite(R3_B_Green, HIGH);
         delay(20000);  
      }
      else if(Sensor_Value2 > 200){
         digitalWrite(R3_B_Red, LOW);
         digitalWrite(R3_B_Green, HIGH);
         delay(10000);
      }
      digitalWrite(R3_B_Green, LOW);
      digitalWrite(R3_B_Orange, HIGH);
      delay(1000);
      digitalWrite(R3_B_Orange, LOW);
      digitalWrite(R3_B_Red, HIGH);
   }
   Sensor_Value1 = 0;
   Sensor_Value2 = 0;
}*/
