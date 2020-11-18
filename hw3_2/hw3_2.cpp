/*
 * Title: hw3_2.cpp
 * Abstract: This program prints out an adjacency matrix for inputted values
 * Author: Roy Morla
 * ID: 0327
 * Date: 09/16/2020
 */

#include<iostream>
#include<list>
#include<iterator>
using namespace std;
void printAdjacencyList(list<int> adjacencyList[], int v);
void addEdge(list<int> adjacencyList[], int x, int y);

int main() {
    int x;
    int y;
    int vertices;   
    int amountEdges;
    cin >> vertices;
    cin >> amountEdges;
    list<int> adjacencyList[vertices];

    for (int i = 0; i < amountEdges; i++) {
        cin >> x >> y;
        addEdge(adjacencyList, x, y);
    }

    for (int i = 0; i < vertices; i++) {
        adjacencyList[i].sort();
    }

    printAdjacencyList(adjacencyList, vertices);
}

void addEdge(list<int> adjacencyList[], int x, int y) {    
   adjacencyList[x].push_back(y);
}

void printAdjacencyList(list<int> adjacencyList[], int vertices) {
    for(int i = 0; i < vertices; i++) {
        list<int> :: iterator it;
        cout << i;
        for (it = adjacencyList[i].begin(); it != adjacencyList[i].end(); ++it) {
            cout << "->" << *it; 
        }
        cout << endl;
    }
}