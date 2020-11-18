/*
 * Title: hw1_1.cpp
 * Abstract: This program detects if two strings are anagrams of each other and prints out how much of each letter the word has.
 * Author: Roy Morla
 * ID: 0327
 * Date: 09/7/2020
 */
#include <iostream>
#include <algorithm>
#include <map> 
using namespace std;

int main() {
    string a1;
    string a2;
    map<char, int> mp;

    cin >> a1;
    cin >> a2;
    sort(a1.begin(), a1.end());
    sort(a2.begin(), a2.end());

    if (a1.compare(a2) == 0) {
        cout << "ANAGRAM" << endl;
        for (int i=0; i<a1.size(); i++) {
            if (mp.find(a1[i]) == mp.end()) {
                mp[a1[i]] = 1;
            }
            else {
                mp[a1[i]]++;
            }
        }
        for (auto x : mp) 
            cout << x.first << ": " << x.second << endl; 
    }
    else {
        cout << "NO ANAGRAM" << endl;
    }

}