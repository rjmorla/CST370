/*
* Title: hw5_1.cpp
* Abstract: Program moves all pos nums to right side and all neg nums to the left side.
* Author: Roy Morla
* ID: 0327
* Date: 9/30/20
*/
#include<iostream>
#include<vector>
using namespace std;

void a1(vector<int> my_vector, int size);
void a2(vector<int> my_vector, int size);

int main() {

  vector<int> v1;
  vector<int> v2;    
  int input;
  cin >> input;

  
  for (int i = 0; i < input; i++) {
      int val;
      cin >> val;
      v1.push_back(val);
      v2.push_back(val);
  }
  
  a1(v1, input);
  cout << endl;
  a2(v2, input);
  
    return 0;
}


void a1(vector<int> my_vector, int size) {

  int j = size - 1;
  int i;
  for (i = 0; i < j; i++) {
      
      if (my_vector[i] < 0) {
          continue;
      }
      
      for (j = size - 1; j > i; j--) {
          if (my_vector[j] < 0 && my_vector[i] > 0) {
              int temp = my_vector[j];
              my_vector[j] = my_vector[i];
              my_vector[i] = temp;
              break;
          }
      }
      
  }
  
  for (int k = 0; k < size; k++) {
    cout << my_vector[k] << " ";
  }
    
}

void a2(vector<int> my_vector, int size) {   
    
  int count = 0;
  for (int i = 0; i < size; i++) {
      
      if (my_vector[i] < 0) {
          count++;
          continue;
      }
      
      while (count < size) {
          
          if (my_vector[count] < 0 && my_vector[i] > 0) {
              int temp = my_vector[count];
              my_vector[count] = my_vector[i];
              my_vector[i] = temp;
              break;
          }
          count++;
      }  
  }
  
  for (int k = 0; k < size; k++) {
    cout << my_vector[k] << " ";
  }
    
}


