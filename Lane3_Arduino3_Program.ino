/**********************************************
 *   This is the program written for Arduino  *
 *  uno 3, used on lane 3.                    *
 **********************************************/

const int Lane3_Sensor1 = A0;               // output of IR Sensor 1 is fed to analog input 0
const int Lane3_Sensor2 = A1;               // output of IR Sensor 2 is fed to analog input 1 

int Sensor1_Value, Sensor2_Value = 0;       // int variables to get sensor inputs
unsigned long Sensor1_Time, Sensor2_Time;   // long variables to get the time in miliseconds, at when each sensor detected vehicles 
int T3;                                     // float variable to pass the T1, which is an input of the NN, to main Mega board 
int Incoming_Value = 0;                     // to read the signal sent by the main Mega board 

void setup() {
  Serial.begin(9600);

  Sensor1_Value = analogRead(Lane3_Sensor1);
  if(Sensor1_Value < 200){
    Sensor1_Time = millis();
    while(analogRead(Lane3_Sensor2) > 200);
    Sensor2_Value = analogRead(Lane3_Sensor2);
    if(Sensor2_Value < 200){
      Sensor2_Time = millis();
      T3 = (Sensor2_Value - Sensor1_Value)/1000;
      Serial.write(T3);
    }
  }
}

void loop() {
  if(Serial.available() > 0){
    Incoming_Value = Serial.read();
    if(Incoming_Value == 10){
      Sensor1_Value = analogRead(Lane3_Sensor1);
      if(Sensor1_Value < 200){
        Sensor1_Time = millis();
        while(analogRead(Lane3_Sensor2) > 200);
        Sensor2_Value = analogRead(Lane3_Sensor2);
        if(Sensor2_Value < 200){
          Sensor2_Time = millis();
          T3 = (Sensor2_Value - Sensor1_Value)/1000;
          Serial.write(T3);
        }
      }      
    }
  }
}
