/*
 * Title: hw4_2.cpp
 * Abstract: This program prints the best combination of apple boxes with constraints to get max apples
 * Author: Roy Morla
 * ID: 0327
 * Date: 09/24/2020
 */
 
#include <iostream> 
#include <math.h> 
#include <vector>
#include <map>
#include <vector>
#include <iterator> 
using namespace std; 
  
class gfg 
{ 
      
public: 

bool adjacentSet(vector<int> x) {
    int n = 0;
    for (int i = 0; i < x.size(); i++) {
        n += x.at(i)*pow(2, i);
    }

    return (n & (n >> 1)); 
} 

void printPowerSet(vector<int> my_vector, int set_size) 
{ 
    /*set_size of power set of a set with set_size 
    n is (2**n -1)*/
    unsigned int pow_set_size = pow(2, set_size);
    bool check = false; 
    int counter; 

    vector<int> bin_vector;
    vector<int> combo_vector;
    map<vector<int>, vector<int>> my_map;
    map<vector<int>, int> maxes_map;

    //formats binary number--------------
    for(counter = 0; counter < pow_set_size; counter++) { 
        for(int j = 0; j < set_size; j++) { 
            /* Check if jth bit in the counter is set 
                If set then print jth element from set */
            if(counter & (1 << j)) 
                bin_vector.push_back(1);
            else 
                bin_vector.push_back(0);
        }

        for(int j = 0; j < set_size; j++) { 
        /* Check if jth bit in the counter is set 
            If set then print jth element from set */
            if(counter & (1 << j)) {
                combo_vector.push_back(my_vector.at(j));
            }
        }   
        //check if subset has any adjacent
        if (!adjacentSet(bin_vector)) {
            my_map.insert(pair<vector<int>, vector<int>>(bin_vector, combo_vector));
            bin_vector.clear();
            combo_vector.clear();
        }
        else {
            //remove bad subset data from vectors
            bin_vector.clear();
            combo_vector.clear();
        }
    }

    //calculate sums now; 
    map<vector<int>, vector<int>>::iterator itr;
    int max = -1000;
    for (itr = my_map.begin(); itr != my_map.end(); ++itr) {
        int max_sum = 0;

        for (int j = 0; j < itr->second.size(); j++) {
           max_sum += itr->second.at(j);

        }
        
        if (max_sum > max) {
            maxes_map.clear();
            max = max_sum;
            maxes_map.insert(pair<vector<int>, int>(itr->first, max_sum));
        }
    }
    map<vector<int>, int>::iterator itr1; 
    cout << "Boxes:" ; 
    for (itr1 = maxes_map.begin(); itr1 != maxes_map.end(); ++itr1) { 
        for (int i = 0; i < itr1->first.size(); i++){
            if (itr1->first.at(i) == 1) {
                cout << i << " ";
            }
        }
        cout << '\n' << "Max Apples:" << itr1->second; 
    } 
} 
}; 
  
/*Driver code*/
int main() 
{ 
    gfg g;
    int set_size; 
    int my_int;
    cin >> set_size;
    vector<int> my_vector;
    for (int i = 0; i < set_size; i++) {
        cin >> my_int;
        my_vector.push_back(my_int);
    } 
    g.printPowerSet(my_vector, set_size); 
    return 0; 
} 
  
// This code is contributed by SoM15242 