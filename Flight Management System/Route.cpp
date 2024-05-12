#include <iostream>
#include "Route.h"
#include <limits.h>
using namespace std;

int Route::minDistance(int distance[],bool checkVisit[],int lastNode){
    int minimum = INT_MAX;
    int Node;
    for(int k=0;k<lastNode;k++) 
    {
        if(!checkVisit[k] && distance[k]<=minimum)      
        {
            minimum=distance[k];
            Node=k;
        }
    }
    return Node;
}

void Route::Dijkstra(int source, int lastNode) {
    int distance[7];
    int previousNode[7];
    bool checkVisit[7];

    for (int k = 0; k < 7; k++) {
        distance[k] = INT_MAX;
        checkVisit[k] = false;
        previousNode[k] = -1;
    }

    distance[source] = 0;

    for (int k = 0; k < 7; k++) {
        int currentNode = minDistance(distance, checkVisit, lastNode);

        checkVisit[currentNode] = true;

        for (int k = 0; k < 7; k++) {
            if (!checkVisit[k] && graph[currentNode][k] != 0 && distance[currentNode] != INT_MAX && distance[currentNode] + graph[currentNode][k] < distance[k] && graph[currentNode][k] < 8000) {
                distance[k] = distance[currentNode] + graph[currentNode][k];
                previousNode[k] = currentNode; 
            }
        }
    }
    if(distance[lastNode] > 45000) {
        cout<<"There is no available route "<<endl;
    }
    else{
       cout << "The shortest distance is: " << distance[lastNode] << endl;

    cout << "Path: ";
    int node = lastNode;
    while (node != -1) {
        cout << node << " <- ";
        node = previousNode[node];
    }
    cout << endl;
    }

}
