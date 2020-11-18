/*
* Title: hw5_2.cpp
* Abstract: Program finds best edges to use between vertices for a TSP graph path.
* Author: Roy Morla
* ID: 0327
* Date: 9/30/20
*/
#include <iostream>
#include <vector>
#include <map>
#include <iterator>
#include <algorithm>
using namespace std;

void find_path(map<pair<int,int>, int> edges_map, int edges, int root);

int main() {
    int vertices;
    int edges;
    int edge_pt1;
    int edge_pt2;
    int weight;
    int root;

    map<pair<int, int>, int> edges_map;

    cin >> vertices >> edges;

    for (int i=0; i<edges; i++) {
        cin >> edge_pt1 >> edge_pt2;
        cin >> weight;

        edges_map.insert(pair<pair<int, int>, int>(make_pair(edge_pt1, edge_pt2), weight));
    }

    cin >> root;

    find_path(edges_map, vertices, root);

}

void find_path(map<pair<int,int>, int> edges_map, int vertices, int root) {
    vector<int> path_vect;
    int place = root;
    int sum = 0;
    int target_num = 2000;
    int count = 0;
    bool new_target_selected;
    path_vect.push_back(root);

    map<pair<int, int>, int>::iterator itr;

    for (int i = 0; i < vertices; i++) {
        int lowest_val = 2000;
        new_target_selected=false;
        for (itr=edges_map.begin(); itr!=edges_map.end(); ++itr) {
            if (itr->first.first == place && itr->second < lowest_val && itr->first.second != root) {  
                target_num = itr->first.second;
                lowest_val = itr->second;
                new_target_selected = true;
            }
        }
        if(!new_target_selected) {
            for (int i = 0; i < path_vect.size()-1; i++) {
                int one = path_vect.at(i);
                int two = path_vect.at(i+1);      
                itr = edges_map.find(pair<int, int>(one, two));
                edges_map.erase(itr);
            }
            sum = 0;
            path_vect.clear();
            path_vect.push_back(root);
            count=0;
            i = 0;
            place=root;
            continue;
        }
        else {

            sum+=lowest_val;
            path_vect.push_back(target_num);
            place = target_num;
            lowest_val = 2000;
            count++;
        }

        if(count == vertices-1) {
            bool found_last_edge = false;
            for (itr=edges_map.begin(); itr!=edges_map.end(); ++itr) {
                if (itr->first.first == place && itr->second < lowest_val && itr->first.second == root ) {
                    lowest_val = itr->second;
                    target_num = itr->first.second;
                    found_last_edge = true;
                }
            } 

            if (found_last_edge){
                sum+=lowest_val;
                path_vect.push_back(target_num);
                break;
            }
            else {
                path_vect.clear();
                sum= -1;
                break;
            }
       

        }
    }
    cout << "Path:";
    for (int i = 0; i < path_vect.size(); i++) {
        if (i != path_vect.size()-1)
            cout << path_vect.at(i) << "->";
        else 
            cout << path_vect.at(i);
        
    }

    cout << endl << "Cost:" << sum;
}