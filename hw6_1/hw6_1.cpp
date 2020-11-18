/*
* Title: hw5_2.cpp
* Abstract: Program conducts a BFS on a graph where the user specifies the root node and hop limit
            and displays which nodes are within specified hop constraint with their respective hop distance from
            the root. 
* Author: Roy Morla
* ID: 0327
* Date: 10/8/20
*/
#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

void read_graph(vector<pair<string, string>> & g, vector<string> & v)
{
    
    int num_of_vertices;
    cin >> num_of_vertices;

    string vertex;

    for (int i = 0; i < num_of_vertices; i++) {
        cin >> vertex;
        v.push_back(vertex);
    }
    
    int num_of_edges;
    cin >> num_of_edges;

    string from;
    string to;
    
    for (int i = 0; i < num_of_edges; i++) 
    {
        cin >> from;
        cin >> to;
        g.push_back(make_pair(from, to));
    }
}

void bfs(vector<pair<string, string>> & g, vector<string> & v, string src, int hops) 
{
    queue<string> q;
	int count = 0;
    map<string, int> mark;

    for (int i = 0; i < v.size(); i++) {
        mark.insert({v.at(i), 0});
    }
    bool b = false;
	mark[src] = ++count;
    q.push(src);
    while (!q.empty()) 
    {
        string curr = q.front();
        q.pop();
        for (int i = 0; i < g.size(); i++) 
        {
            if (g.at(i).first == curr) {

                string neighbor = g.at(i).second;
                if (b) {
                    mark[neighbor] = count;
                    q.push(neighbor);
                }
                else if(mark[neighbor] == 0) 
                {   
                    if (mark[curr] < count) {
                        count--;
                    }
                    mark[neighbor] = ++count;
                    q.push(neighbor);
                    b = true;                
                }
                
            }
        }
        b = false;

    }

	for (auto& x: mark)
	{   
        if (x.second <= hops+1 && x.second != 0)
		cout << x.first << ":" << x.second - 1 << endl;
	}

    return;
}



int main()
{
    vector<string> vertices;
    vector<pair<string, string>> graph;
    
    read_graph(graph, vertices);
    string src;
    int hops;
    cin >> src;
    cin >> hops;

    bfs(graph, vertices, src, hops);

    return 0;
}
