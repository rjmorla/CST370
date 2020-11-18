/*
 * Title: hw4_1.cpp
 * Abstract: This program prints out all combinations with their associated bits. 
 * Author: Roy Morla
 * ID: 0327
 * Date: 09/24/2020
 */

#include <iostream> 
#include <math.h> 
#include <vector>
#include <stack>
#include <algorithm>
using namespace std; 
  
class gfg 
{ 
      
public: 
void printPowerSet(vector<string> my_vector, int set_size) 
{ 
    /*set_size of power set of a set with set_size 
    n is (2**n -1)*/
    unsigned int pow_set_size = pow(2, set_size);
    bool check = false; 
    int counter; 
    vector<string> sorted_values;
    stack<int> s;

    for(counter = 0; counter < pow_set_size; counter++) { 
        for(int j = 0; j < set_size; j++) { 
            /* Check if jth bit in the counter is set 
                If set then print jth element from set */
            if(counter & (1 << j)) 
                s.push(1);
            else 
                s.push(0);
        }
  
        /*Run from counter 000..0 to 111..1*/
        for(int j = 0; j < set_size; j++) { 
            /* Check if jth bit in the counter is set 
                If set then print jth element from set */
            cout << s.top();
            s.pop();
        }
        cout << ":";
        int count = set_size - 1;
        for(int j = 0; j < set_size; j++) { 
            /* Check if jth bit in the counter is set 
                If set then print jth element from set */
            if(counter & (1 << j)) {
                sorted_values.push_back(my_vector.at(count)); 
                check = true;
            }
            count--;
        }
        sort(sorted_values.begin(), sorted_values.end());
        for(int j = 0; j < sorted_values.size(); j++) { 
            cout << sorted_values.at(j) << " "; 
        }
        sorted_values.clear();
        if (!check) 
            cout << "EMPTY";
    cout << endl; 
    } 
    
} 
}; 
  
/*Driver code*/
int main() 
{ 
    gfg g;
    int set_size; 
    string my_string;
    cin >> set_size;

    vector<string> my_vector;
    for (int i = 0; i < set_size; i++) {
        cin >> my_string;
        my_vector.push_back(my_string);
    } 
    cout << endl;
    if (set_size == 0)
        cout << "0";
    g.printPowerSet(my_vector, set_size); 
    return 0; 
} 
  
// This code is contributed by SoM15242 