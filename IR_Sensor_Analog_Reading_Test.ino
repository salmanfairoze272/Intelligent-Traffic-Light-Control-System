
const int IR_Sensor = A0;                   // output of IR Sensor 1 is fed to analog input 0
int Sensor_Value = 0;                       // int variables to get sensor inputs

void setup() {
  Serial.begin(9600);                       // setup serial communication
} 
  
void loop() {
  Sensor_Value = analogRead(IR_Sensor);    // read analog sensor input
  Serial.println(Sensor_Value);             // print sensor value over the serial printer
  delay(1000);
}
