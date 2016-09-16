const float learning_const = 0.001;             // learning constant
float input_matrix[10][3] = {{10,  8,  5},      // matrix of the inputs to train the neural network
                             {12,  9,  6},
                             //{14, 13, 10},
                             //{13, 17, 15},
                             { 9, 12, 13},
                             //{ 8, 15, 10},
                             //{11, 16,  8},  
                             //{16,  9, 12},
                             //{12, 13, 14},
                             //{15, 10,  9},
                             { 9, 14, 10},
                             {10,  6, 11},
                             //{14, 15, 16},
                             //{11, 12, 13},
                             //{15, 14, 16},
                             //{13, 10, 12},
                             //{12,  8,  8},
                             {12, 10, 13},
                             //{ 9, 11, 10},
                             {11, 15, 14},
                             //{16, 14, 15},
                             //{17, 15, 16},
                             //{15, 11, 14},
                             {13, 11,  9},
                             //{11, 12, 14},
                             { 8, 10,  9},
                             //{10,  9, 10},
                             //{11, 14, 13},
                             //{13, 12, 11},   
                             {15, 10,  8}};
int a;                                          // to pass the row number (number of input set) of inputs matrix
int b;                                          // to pass the column number of each array                            

float summation(int a,float new_weights[3]);    // fn to find sum of weighed inputs

void setup() {
  Serial.begin(9600);                           // set the baude rate for serial communication
  
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
  for(a=0; a<10; a++){                          // for each set of inputs,
    sum = summation(a,n1_final_weights);        // getting the summation value of each weighed input to neuron 1
/* applying activation function to sum, to find output */    
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
/* to print the values of all weight changes and new weights, in neuron 1 */
      Serial.println("weight ");
      Serial.print(b+1);
      Serial.print(" of neuron 1 for the input set ");
      Serial.print(a+1);
      Serial.print(" is ");
      Serial.print(n1_final_weights[b]);
    }
    Serial.println();               // goto new line   
  }
  Serial.println();                 // goto new line
  
/* calculating output, changes in weights and final weightsfor the SECOND NEURON */   
  for(a=0; a<10; a++){
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
      Serial.println("weight ");
      Serial.print(b+1);
      Serial.print(" of neuron 2 for the input set ");
      Serial.print(a+1);
      Serial.print(" is ");
      Serial.print(n2_final_weights[b]);
    }
    Serial.println();
  } 
  Serial.println();
  
/* calculating output, changes in weights and final weightsfor the THIRD NEURON */    
  for(a=0; a<10; a++){
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
      Serial.println("weight ");
      Serial.print(b+1);
      Serial.print(" of neuron 3 for the input set ");
      Serial.print(a+1);
      Serial.print(" is ");
      Serial.print(n3_final_weights[b]);
    }
    Serial.println();
  }
  Serial.println();
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
