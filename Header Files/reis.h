//
// Created by daanv on 08/06/2022.
//

#ifndef DIJKSTRA_REIS_H
#define DIJKSTRA_REIS_H


#include<bits/stdc++.h>
#include "comparable.h"
#include "stap.h"

using namespace std;
# define INF 0x3f3f3f3f

// This class represents a directed graph using
// adjacency list representation

class Reis : public Comparable {

private:

    // Aantal hoekpunten in de graaf
    int hoekPunten;
    int beginBestemming;
    int eindBestemming;


    // opslag punten en gewichten van verbindingen
    list< pair<int, int> > *stappen;

public:
    Reis(int hoekPunten, int beginBestemming, int eindBestemming); // Constructor
    void addEdge(Stap stap);  // functie om een punt toe te voegen
    void shortestPath(int startPunt); // print de korste route vanaf startPunt
    void printShortest(vector<int> dist);
    bool compareTo();
};


#endif //DIJKSTRA_REIS_H
