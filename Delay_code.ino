//****---ROAD 1(R1)---************//
//TR11 - Traffic Light 11(RED)
//TY11 - Traffic Light 11(AMBER)
//TG11 - Traffic Light 11(GREEN)

//TR12 - Traffic Light 12(RED)
//TY12 - Traffic Light 12(AMBER)
//TG12 - Traffic Light 12(GREEN)


//****---ROAD 2(R2)---***********//
//TR21 - Traffic Light 21(RED)
//TY21 - Traffic Light 21(AMBER)
//TG21 - Traffic Light 21(GREEN)

//TR22 - Traffic Light 22(RED)
//TY22 - Traffic Light 22(AMBER)
//TG22 - Traffic Light 22(GREEN)


//****---ROAD 3(R3)---************//
//TR31 - Traffic Light 31(RED)
//TY31 - Traffic Light 31(AMBER
//TG31 - Traffic Light 31(GREEN)

//TR32 - Traffic Light 32(RED)
//TY32 - Traffic Light 32(AMBER)
//TG32 - Traffic Light 32(GREEN)


//******-Global Variables---*//
///////*****LED PINS******//////////

//****---ROAD 1 Lane 1(R11)---************//
int TR11 = 34;
int TY11 = 35;
int TG11 = 36;

//****---ROAD 1 Lane 2(R12)---************//
int TR12 = 37;
int TY12 = 38;
int TG12 = 39;

//****---ROAD 2 Lane 1(R21)---************//
int TR21 = 40;
int TY21 = 41;
int TG21 = 42;

//****---ROAD 2 Lane 2(R22)---************//
int TR22 = 43;
int TY22 = 44;
int TG22 = 45;

//****---ROAD 3 Lane 1(R31)---************//
int TR31 = 46;
int TY31 = 47;
int TG31 = 48;

//****---ROAD 3 Lane 2(R32)---************//
int TR32 = 49;
int TY32 = 50;
int TG32 = 51;

void setup() {
  // put your setup code here, to run once:
  
int i;
 for(i=34;i<52;i++)
      pinMode(i,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  Cond1();
  delay(5000);

  Cond2();
  delay(1000);

  Cond3();
  delay(5000);
  
  Cond4();
  delay(1000);
  
  Cond5();
  delay(5000);
  
  Cond6();
  delay(1000);
  
}

void Cond1()
{
   digitalWrite(TR11,HIGH);   //Road 1 Lane 1 -STOP
   digitalWrite(TY11,LOW);
   digitalWrite(TG11,LOW);

   digitalWrite(TR12,HIGH);   //Road 1 Lane 2 -STOP
   digitalWrite(TY12,LOW);
   digitalWrite(TG12,LOW);

   digitalWrite(TR21,LOW);   //Road 2 Lane 1 -GO
   digitalWrite(TY21,LOW);
   digitalWrite(TG21,HIGH); 

   digitalWrite(TR22,LOW);   //Road 2 Lane 2 -GO
   digitalWrite(TY22,LOW);
   digitalWrite(TG22,HIGH); 

   digitalWrite(TR31,LOW);   //Road 3 Lane 1 -GO
   digitalWrite(TY31,LOW);
   digitalWrite(TG31,HIGH); 

   digitalWrite(TR32,HIGH);   //Road 3 Lane 2 -STOP
   digitalWrite(TY32,LOW);
   digitalWrite(TG32,LOW); 
}

void Cond2()
{
   digitalWrite(TR11,HIGH);   //Road 1 Lane 1 -READY
   digitalWrite(TY11,HIGH);
   digitalWrite(TG11,LOW);
  
   digitalWrite(TR12,HIGH);   //Road 1 Lane 2 -READY
   digitalWrite(TY12,HIGH);
   digitalWrite(TG12,LOW);

   digitalWrite(TR21,LOW);   //Road 2 Lane 1 -GO
   digitalWrite(TY21,LOW);
   digitalWrite(TG21,HIGH); 

   digitalWrite(TR22,LOW);   //Road 2 Lane 2 -READY STOP
   digitalWrite(TY22,HIGH);
   digitalWrite(TG22,LOW); 

   digitalWrite(TR31,LOW);   //Road 3 Lane 1 -READY STOP
   digitalWrite(TY31,HIGH);
   digitalWrite(TG31,LOW); 

   digitalWrite(TR32,HIGH);   //Road 3 Lane 2 -STOP
   digitalWrite(TY32,LOW);
   digitalWrite(TG32,LOW); 

}

void Cond3()
{
   digitalWrite(TR11,LOW);   //Road 1 Lane 1 -GO
   digitalWrite(TY11,LOW);
   digitalWrite(TG11,HIGH);

   digitalWrite(TR12,LOW);   //Road 1 Lane 2 -GO
   digitalWrite(TY12,LOW);
   digitalWrite(TG12,HIGH);

   digitalWrite(TR21,LOW);   //Road 2 Lane 1 -GO
   digitalWrite(TY21,LOW);
   digitalWrite(TG21,HIGH); 

   digitalWrite(TR22,HIGH);   //Road 2 Lane 2 -STOP
   digitalWrite(TY22,LOW);
   digitalWrite(TG22,LOW); 

   digitalWrite(TR31,HIGH);   //Road 3 Lane 1 -STOP
   digitalWrite(TY31,LOW);
   digitalWrite(TG31,LOW); 

   digitalWrite(TR32,HIGH);   //Road 3 Lane 2 -STOP
   digitalWrite(TY32,LOW);
   digitalWrite(TG32,LOW); 

   

}

void Cond4()
{
   digitalWrite(TR11,LOW);   //Road 1 Lane 1 -GO
   digitalWrite(TY11,LOW);
   digitalWrite(TG11,HIGH);

   digitalWrite(TR12,LOW);   //Road 1 Lane 2 -READY STOP
   digitalWrite(TY12,HIGH);
   digitalWrite(TG12,LOW);

   digitalWrite(TR21,LOW);   //Road 2 Lane 1 -READY STOP
   digitalWrite(TY21,HIGH);
   digitalWrite(TG21,LOW); 

   digitalWrite(TR22,HIGH);   //Road 2 Lane 2 -STOP
   digitalWrite(TY22,LOW);
   digitalWrite(TG22,LOW); 

   digitalWrite(TR31,HIGH);   //Road 3 Lane 1 -READY
   digitalWrite(TY31,HIGH);
   digitalWrite(TG31,LOW); 

   digitalWrite(TR32,HIGH);   //Road 3 Lane 2 -READY
   digitalWrite(TY32,HIGH);
   digitalWrite(TG32,LOW); 
}

void Cond5()
{
   digitalWrite(TR11,LOW);   //Road 1 Lane 1 -GO
   digitalWrite(TY11,LOW);
   digitalWrite(TG11,HIGH);

   digitalWrite(TR12,HIGH);   //Road 1 Lane 2 - STOP
   digitalWrite(TY12,LOW);
   digitalWrite(TG12,LOW);

   digitalWrite(TR21,HIGH);   //Road 2 Lane 1 - STOP
   digitalWrite(TY21,LOW);
   digitalWrite(TG21,LOW); 

   digitalWrite(TR22,HIGH);   //Road 2 Lane 2 -STOP
   digitalWrite(TY22,LOW);
   digitalWrite(TG22,LOW); 

   digitalWrite(TR31,LOW);   //Road 3 Lane 1 -GO
   digitalWrite(TY31,LOW);
   digitalWrite(TG31,HIGH); 

   digitalWrite(TR32,LOW);   //Road 3 Lane 2 -GO
   digitalWrite(TY32,LOW);
   digitalWrite(TG32,HIGH); 
}

void Cond6()
{
   digitalWrite(TR11,LOW);   //Road 1 Lane 1 -READY STOP
   digitalWrite(TY11,HIGH);
   digitalWrite(TG11,LOW);

   digitalWrite(TR12,HIGH);   //Road 1 Lane 2 - STOP
   digitalWrite(TY12,LOW);
   digitalWrite(TG12,LOW);

   digitalWrite(TR21,HIGH);   //Road 2 Lane 1 - GO
   digitalWrite(TY21,HIGH);
   digitalWrite(TG21,LOW); 

   digitalWrite(TR22,HIGH);   //Road 2 Lane 2 -GO
   digitalWrite(TY22,HIGH);
   digitalWrite(TG22,LOW); 

   digitalWrite(TR31,LOW);   //Road 3 Lane 1 -GO
   digitalWrite(TY31,LOW);
   digitalWrite(TG31,HIGH); 

   digitalWrite(TR32,HIGH);   //Road 3 Lane 2 -READY STOP
   digitalWrite(TY32,LOW);
   digitalWrite(TG32,LOW); 
}

