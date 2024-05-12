#ifndef ROUTE_H
#define ROUTE_H
#include <iostream>
using namespace std;
int graph[7][7]={
        {0, 1500, 2500, 8200,5800,7000, 9100},//Istanbul
        {1500, 0, 900, 7000, 6750, 9000, 9400},//Munich
        {2500, 900, 0, 6000,7200,8000,9500},//London
        {8400, 7000, 6000, 0,12000 ,11000, 11000},//Washington
        {5800,6750,7200,12000,0,3000,5800},//Delhi (India)
        {7000, 9000, 8000, 11000,3000,0, 2000},//Beijing
        {9000, 9400, 9500, 11000,5800,2000, 0}};//Tokyo
class Route{
    public:
    int minDistance(int distance[],bool checkVisit[],int lastNode);
    void Dijkstra(int source,int lastNode);

    private:
    int currentNode;
};




#endif