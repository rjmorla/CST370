/*
 * Title: hw1_1.cpp
 * Abstract: This program tells the difference between two times where the second time is always after the first.
 * Author: Roy Morla
 * ID: 0327
 * Date: 09/7/2020
 */
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

int main() {
    string s1;
    string s2;

    cin >> s1 >> s2;

    vector<int> v1;
    vector<int> v2;

    replace(s1.begin(), s1.end(), ':', ' ');
    replace(s2.begin(), s2.end(), ':', ' ');

    int temp;
    stringstream ss1(s1);
    while (ss1 >> temp) {
        v1.push_back(temp);
    }
    stringstream ss2(s2);
    while (ss2 >> temp) {
        v2.push_back(temp);
    }

    int hour;
    if (v1.at(0) > v2.at(0)) {
        hour = 24 - v1.at(0);
        hour += v2.at(0);
    }
    else {
        hour = v2.at(0) - v1.at(0);
    }

    int minutes;
    if (v1.at(1) > v2.at(1)) {
        minutes = 60 - v1.at(1);
        minutes += v2.at(1);
        hour -= 1;
    }
    else {
        minutes = v2.at(1) - v1.at(1);
    }

    int seconds;
    if (v1.at(2) > v2.at(2)) {
        seconds = 60 - v1.at(2);
        seconds += v2.at(2);
        minutes -= 1;
    }
    else {
        seconds = v2.at(2) - v1.at(2);
    }

    if (hour < 10) {
        cout << "0" << hour << ":";
    }
    else {
        cout << hour << ":";
    }

    if (minutes < 10) {
        cout << "0" << minutes << ":";
    }
    else {
        cout << minutes << ":";
    }

    if (seconds < 10) {
        cout << "0" << seconds;
    }
    else {
        cout << seconds;
    }

}