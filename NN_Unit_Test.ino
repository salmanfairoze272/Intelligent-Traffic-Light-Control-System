const float learning_const = 0.001;             // learning constant
float input_matrix[16][3] = {{10,  8,  5},      // matrix of the inputs to train the neural network
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

/* The actual outputs, to compare with the NN outputs, for unit test purpose */
float N1_Actual_Output[3] = {3.1748636, 2.6471482, 2.4524322};      // actual 16th 3 weights of neuron 1
float N2_Actual_Output[3] = {2.7202074, 3.1821560, 2.4751044};      // actual 16th 3 weights of neuron 2
float N3_Actual_Output[3] = {2.7702238, 2.7211680, 3.0001122};      // actual 16th 3 weights of neuron 3
                                                                            
int a;                                          // to pass the row number (number of input set) of inputs matrix
int b;                                          // to pass the column number of each array   
int X = 0;                         

float summation(int a,float new_weights[3]);    // fn to find sum of weighed inputs

void setup() {
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  Serial.begin(9600);                           // set the baude rate for serial communication
  
  float sum = 0;                                // float variable to get the summation value passed by the fn 'summation'
  
  float n1_ultimate_weights[3];
  float n2_ultimate_weights[3];
  float n3_ultimate_weights[3];
  
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
/* unit testing for neuron 1 */
  Serial.println();
  for(int i=0; i<3; i++){
    if(N1_Actual_Output[i] == n1_ultimate_weights[i]){
      X = 1;
    }
    if(N1_Actual_Output[i] != n1_ultimate_weights[i]){
      X = 0;
    }
  }
  if(X == 1){
    Serial.println(" Neuron 1 test PASS ");
  }
  if(X == 0){
    Serial.println(" Neuron 1 test FAIL "); 
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
/* unit testing for neuron 2 */
  Serial.println();
  for(int i=0; i<3; i++){
    if(N2_Actual_Output[i] == n2_ultimate_weights[i]){
      X = 1;
    }
    if(N2_Actual_Output[i] != n2_ultimate_weights[i]){
      X = 0;
    }
  }
  if(X == 1){
    Serial.println(" Neuron 2 test PASS ");
  }
  if(X == 0){
    Serial.println(" Neuron 2 test FAIL "); 
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
/* unit testing for neuron 3 */
  Serial.println();
  for(int i=0; i<3; i++){
    if(N3_Actual_Output[i] == n3_ultimate_weights[i]){
      X = 1;
    }
    if(N3_Actual_Output[i] != n3_ultimate_weights[i]){
      X = 0;
    }
  }
  if(X == 1){
    Serial.println(" Neuron 3 test PASS ");
  }
  if(X == 0){
    Serial.println(" Neuron 3 test FAIL "); 
  }
}

void loop() {
 //put your main code here, to run repeatedly:
}

float summation(int a,float new_weights[3]){            
  float sum = 0;
  for(b=0; b<3; b++){
    sum += new_weights[b] * input_matrix[a][b];
  }
  return sum;
}
