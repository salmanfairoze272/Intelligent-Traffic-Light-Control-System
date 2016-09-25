int x, y, a, b = 0;
int S1, S2 = 0;
unsigned long T1, T2 = 0;
int T; 

int transmission1(int T);
int transmission2(int T);

void setup(){
  delay(1000);
  Serial.begin(9600);
  delay(1000);
}


void loop(){ 
  while(Serial.available() == 0);
  do{
    S1 = analogRead(A0);    // read analog sensor value
  }while( S1 > 200);        // wait until vehicle is detected to sensor 1
  T1 = millis();            // get the time at when vehicle detected to sensor 1, in milli seconds
  
  do{
    S2 = analogRead(A1);
  }while( S2 > 200);        // wait until vehicle is detected to sensor 2
  T2 = millis();            // get the time at when vehicle detected to sensor 2, in milli seconds
  
  T = (T2 - T1)/1000;       // get the time gap in seconds
  a = transmission1(T);
  b = transmission2(T);

  //Serial.write(6);
     
  while(Serial.available() == 0);   // waiting for the signal from mega, for digit 1
  Serial.write(a);
  while(Serial.available() == 0);   // waiting for the signal from mega, for digit 2
  Serial.write(b);
}


int transmission1(int T){
  x = T/10;
  if(x == 0){
    a = 48;
  }
  if(x == 1){
    a = 49;
  }
  if(x == 2){
    a = 50;
  }
  if(x == 3){
    a = 51;
  }
  if(x == 4){
    a = 52;
  }
  if(x == 5){
    a = 53;
  }
  if(x == 6){
    a = 54;
  }
  if(x == 7){
    a = 55;
  }
  if(x == 8){
    a = 56;
  }
  if(x == 9){
    a = 57;
  }
  return a;
}

int transmission2(int t){
  y = t%10;
  if(y == 0){
    b = 48;
  }
  if(y == 1){
    b = 49;
  }
  if(y == 2){
    b = 50;
  }
  if(y == 3){
    b = 51;
  }
  if(y == 4){
    b = 52;
  }
  if(y == 5){
    b = 53;
  }
  if(y == 6){
    b = 54;
  }
  if(y == 7){
    b = 55;
  }
  if(y == 8){
    b = 56;
  }
  if(y == 9){
    b = 57;
  }
  return b;
}
