/*
 * Title: hw3_1.cpp
 * Abstract: This program prints out the max events that can occur concurrently from inputted values pairs.
 * Author: Roy Morla
 * ID: 0327
 * Date: 09/16/2020
 */
 
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<pair<int,int>> myVector;

    int x;
    int p1;
    int p2;
    int max = 1;
    int maxCount = 1;

    cin >> x;

    for (int i = 0; i < x; i++) {
        cin >> p1 >> p2;
        myVector.push_back(make_pair(p1, p2));
    }

    for (int i = 0; i < x; i++) {
        for (int j = i+1; j < x; j++) {
            if (myVector.at(i).second < myVector.at(j).second && myVector.at(i).second > myVector.at(j).first) {
                maxCount++;
                if (maxCount > max) {
                    max = maxCount;
                }
            }
            else if (myVector.at(i).second > myVector.at(j).second && myVector.at(i).first < myVector.at(j).first) {
                maxCount++;
                if (maxCount > max) {
                    max = maxCount;
                }
            }
        }
        maxCount = 1;

    }

    cout <<"Max events: " << max;
    
}