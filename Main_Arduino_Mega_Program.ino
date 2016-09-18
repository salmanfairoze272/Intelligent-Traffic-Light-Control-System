/* digital output pins for lighting LEDs */
const int L1_Green = 35;
const int L1_Orange = 36;
const int L1_Red = 37;
const int L2_Green = 38;
const int L2_Orange = 39;
const int L2_Red = 40;
const int L3_Green = 41;
const int L3_Orange = 42;
const int L3_Red = 43;

const float learning_const = 0.001;             // learning constant 
float input_matrix[16][3] = {{10,  8,  5},      // Matrix of the inputs to train the Neural network
                             {12,  9,  6},
                             {14, 13, 10},
                             {13, 17, 15},
                             { 9, 12, 13},                     
                             {11, 16,  8},                            
                             {12, 13, 14},
                             {15, 10,  9},
                             { 9, 14, 10},
                             {10,  6, 11},                             
                             {12, 10, 13},                             
                             {11, 15, 14},                            
                             {15, 11, 14},
                             {11, 12, 14},
                             {10,  9, 10},
                             {11, 14, 13}};

/*  arrays to store final 3 weights generated by the neurons after performing 
 * learning actions for each and every input set, in the input matrix. These
 * final weights are used in the 'loop' function to calculate the time how long 
 * green lights should be turned on */
float n1_ultimate_weights[3];
float n2_ultimate_weights[3];
float n3_ultimate_weights[3];

float new_inputs[3];                            // to have the next new training data set in 1 row and 3 columns (real time inputs)
                                                                            
int a;                                          // to pass the row number (number of input set) of inputs matrix
int b;                                          // to pass the column number of each array                            
float sum2 = 0;
float T1, T2, T3 = 0;                           // variables to get time differences between each sensor
float Output1, Output2, Output3;                // to get the output times, how long the green lights should be kept turned on

float summation(int a,float new_weights[3]);    // fn to find sum of weighed inputs
float lane_1(float time1); // To pass the green light signals to the LEDs (Outputs)
float lane_2(float time2); // To pass the green light signals to the LEDs (Outputs)
float lane_3(float time3); // To pass the green light signals to the LEDs (Outputs)


// in this setup function, NN is run once and weights are calculated based on 16 input sets
void setup() {
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  for(int x=35; x<=43; x++){
    pinMode(x, OUTPUT);
  }
  Serial.begin(9600);                           // set the baude rate for serial communication

/*  initially, all the red lights are kept turned on while the main Arduino Mega board
 * gets values for T1, T2 and T3 from other 3 Arduino Uno boards */
  digitalWrite(L1_Red, HIGH);
  digitalWrite(L1_Orange, LOW);
  digitalWrite(L1_Green, LOW);
  digitalWrite(L2_Red, HIGH);
  digitalWrite(L2_Orange, LOW);
  digitalWrite(L2_Green, LOW);
  digitalWrite(L3_Red, HIGH);
  digitalWrite(L3_Orange, LOW);
  digitalWrite(L3_Green, LOW);
  
  float sum = 0;                                // float variable to get the summation value passed by the fn 'summation'
  
  float n1_output_values[3];                    // float array of three elements to store each output of neuron 1, corresponding to each input set
  float n1_weight_changes[3];                   // float array of three elements to store each change in weights in neuron 1, after each training
  float n1_final_weights[3] = {1,0.5,0.5};      // initial weights to neuron 1
  
  float n2_output_values[3];          
  float n2_weight_changes[3];
  float n2_final_weights[3] = {0.5,1,0.5};
  
  float n3_output_values[3];          
  float n3_weight_changes[3];
  float n3_final_weights[3] = {0.5,0.5,1};
    
/* calculating output, changes in weights and final weightsfor the FIRST NEURON */    
  for(a=0; a<16; a++){                          // for each set of inputs,
    sum = summation(a,n1_final_weights);        // getting the summation value of each weighed input to neuron 1
    
/******************************************************** 
 * applying activation function to sum, to find output. *
 * the activation function is such that:                *
 *                                                      *
 *    y = 60        ; x <= 5                            *
 *    y = -2*x + 70 ; 5 < x <= 30                       *
 *    y = 10        ; 30 < x                            *
 *                                                      *
 ********************************************************/    
    if(sum<=5){
      n1_output_values[a] = 60;
    }
    if(5<sum<=30){
      n1_output_values[a] = -2*sum + 70;  
    }   
    if(30<sum){
      n1_output_values[a] = 10; 
    }
/* to find changes in weights and final weights, for each input of three inputs in an input set */
    for(b=0; b<3; b++){
      n1_weight_changes[b] = 0.001*n1_output_values[a]*input_matrix[a][b];          // getting the three weight changes occured in neuron 1, for one input set
      n1_final_weights[b] = n1_weight_changes[b]+n1_final_weights[b];               // getting the three new weights occured in neuron 1, for the same input set 
    }
    if(a==15){                   // to get the three weights of neuron 1, for the last set of inputs, i.e. the final set of weights of the neuron 1
      for(int i=0; i<3; i++){
        n1_ultimate_weights[i] = n1_final_weights[i];   // storing the final set of weights of neuron 1 into the array 'n1_ultimate_weights'
      }
    }   
  }
  Serial.println();
  Serial.println("Final weights of neuron 1 are:");
  for(int i=0; i<3; i++){
    Serial.println(n1_ultimate_weights[i]);
  }
  
/* calculating output, changes in weights and final weightsfor the SECOND NEURON */   
  for(a=0; a<16; a++){
    sum = summation(a,n2_final_weights);        
    if(sum<=5){
      n2_output_values[a] = 60;
    }
    if(5<sum<=30){
      n2_output_values[a] = -2*sum + 70;  
    }   
    if(30<sum){
      n2_output_values[a] = 10; 
    }
    for(b=0; b<3; b++){
      n2_weight_changes[b] = 0.001*n2_output_values[a]*input_matrix[a][b];
      n2_final_weights[b] = n2_weight_changes[b]+n2_final_weights[b];
    }
    if(a==15){
      for(int i=0; i<3; i++){
        n2_ultimate_weights[i] = n2_final_weights[i];   // storing the final set of weights of neuron 2 into the array 'n2_ultimate_weights'
      }
    }
  } 
  Serial.println();
  Serial.println("Final weights of neuron 2 are:");
  for(int i=0; i<3; i++){
    Serial.println(n2_ultimate_weights[i]);
  }
  
/* calculating output, changes in weights and final weightsfor the THIRD NEURON */    
  for(a=0; a<16; a++){
    sum = summation(a,n3_final_weights);    // getting the summation value
    if(sum<=5){
      n3_output_values[a] = 60;
    }
    if(5<sum<=30){
      n3_output_values[a] = -2*sum + 70;  
    }   
    if(30<sum){
      n3_output_values[a] = 10; 
    }
    for(b=0; b<3; b++){
      n3_weight_changes[b] = 0.001*n3_output_values[a]*input_matrix[a][b];
      n3_final_weights[b] = n3_weight_changes[b]+n3_final_weights[b];
    }
    if(a==15){
      for(int i=0; i<3; i++){
        n3_ultimate_weights[i] = n3_final_weights[i];   // storing the final set of weights of neuron 3 into the array 'n3_ultimate_weights'
      }
    }
  }   
  Serial.println();
  Serial.println("Final weights of neuron 3 are:");
  for(int i=0; i<3; i++){
    Serial.println(n3_ultimate_weights[i]);
  }
}


// function for traffic light controlling 
void loop() {
  T1, T2, T3 = 0;               // make all the three inputs zero

  if(Serial1.available() > 0){  // get the input from arduino 1 of lane 1
    T1 = Serial1.read();
  }
  if(Serial2.available() > 0){  // get the input from arduino 2 of lane 2
    T2 = Serial2.read();
  }
  if(Serial3.available() > 0){  // get the input from arduino 3 of lane 3
    T3 = Serial3.read();
  }

  if((0 < T1) && (0 < T2) && (0 < T3)){     // if the inputs T1, T2 and T3 all are non zero, then perform the calculation for outputs
    float new_array[3] = {T1, T2, T3};      // get the new inputs using an array
    for(int i=0; i<3; i++){
      new_inputs[i] = new_array[i];         // assign the new inputs T1, T2 and T3 to the array called 'new_inputs[3]' to pass new inputs, to calculate outputs of each neuron
    }
  
  /* to calculate the output value for neuron 1 */
    for(int i=0; i<3; i++){
      sum2 += new_inputs[i]*n1_ultimate_weights[i];
    }
    if(sum2 <= 5){
      Output1 = 60;
    }
    if(5 < sum2 <= 30){
      Output1 = -2*sum2 + 70;
    }
    if(sum2 < 30){
      Output1 = 10;
    }

  /* to calculate the output value for neuron 2 */
    for(int i=0; i<3; i++){
      sum2 += new_inputs[i]*n2_ultimate_weights[i];
    }
    if(sum2 <= 5){
      Output2 = 60;
    }
    if(5 < sum2 <= 30){
      Output2 = -2*sum2 + 70;
    }
    if(sum2 < 30){
      Output2 = 10;
    }

  /* to calculate the output value for neuron 3 */
    for(int i=0; i<3; i++){
      sum2 += new_inputs[i]*n3_ultimate_weights[i];
    }
    if(sum2 <= 5){
      Output3 = 60;
    }
    if(5 < sum2 <= 30){
      Output3 = -2*sum2 + 70;
    }
    if(sum2 < 30){
       Output3 = 10;
    }  

    lane_1(Output1);
    lane_2(Output2);
    lane_3(Output3); 
  }
}


// function for calculating the sum of weighed inputs
float summation(int a,float new_weights[3]){            
  float sum = 0;
  for(b=0; b<3; b++){
    sum += new_weights[b] * input_matrix[a][b];
  }
  return sum;
}


float lane_1(float time1){
  digitalWrite(L1_Red, LOW);
  digitalWrite(L1_Orange, HIGH);
  delay(600);
  digitalWrite(L1_Orange, LOW);
  digitalWrite(L1_Green, HIGH);
  delay(time1);
  digitalWrite(L1_Green, LOW);
  digitalWrite(L1_Orange, HIGH);
  delay(600);
  digitalWrite(L1_Red, HIGH);
  Serial1.write(10);
}


float lane_2(float time2){
  digitalWrite(L2_Red, LOW);
  digitalWrite(L2_Orange, HIGH);
  delay(600);
  digitalWrite(L2_Orange, LOW);
  digitalWrite(L2_Green, HIGH);
  delay(time2);
  digitalWrite(L2_Green, LOW);
  digitalWrite(L2_Orange, HIGH);
  delay(600);
  digitalWrite(L2_Red, HIGH);
  Serial2.write(10);
}


float lane_3(float time3){
  digitalWrite(L3_Red, LOW);
  digitalWrite(L3_Orange, HIGH);
  delay(600);
  digitalWrite(L3_Orange, LOW);
  digitalWrite(L3_Green, HIGH);
  delay(time3);
  digitalWrite(L3_Green, LOW);
  digitalWrite(L3_Orange, HIGH);
  delay(600);
  digitalWrite(L3_Red, HIGH);
  Serial.write(10);
}
