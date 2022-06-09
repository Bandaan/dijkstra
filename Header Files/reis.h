//
// Created by daanv on 08/06/2022.
//

#ifndef DIJKSTRA_REIS_H
#define DIJKSTRA_REIS_H


#include<bits/stdc++.h>
#include "comparable.h"
#include <vector>
#include "stap.h"
#include "vlucht.h"
#include "rit.h"
#include "treinrit.h"


using namespace std;
# define INF 0x3f3f3f3f

// This class represents a directed graph using
// adjacency list representation

class Reis : public Comparable {

private:
    int beginBestemming;
    int eindBestemming;

    // opslag punten en gewichten van verbindingen
    list< pair<int, int> > *verbindingVlucht;
    list< pair<int, int> > *verbindingRit;
    list< pair<int, int> > *verbindingTreinrit;

    std::vector<Stap> vluchtStappen = {};
    std::vector<Stap> ritStappen = {};
    std::vector<Stap> treinritStappen= {};


public:
    Vlucht v = Vlucht();
    Rit r = Rit();
    Treinrit t = Treinrit();

    bool vluchtStatus, ritStatus, treinritStatus = false;

    Reis(int beginBestemming, int eindBestemming); // Constructor

    void addEdgeVlucht(Stap stap);  // functie om een punt toe te voegen
    void addEdgeRit(Stap stap);  // functie om een punt toe te voegen
    void addEdgeTreinrit(Stap stap);  // functie om een punt toe te voegen

    void setReisstatus();
    bool stepExistsChange(Stap stap, std::vector<Stap> vervoerLijst);
    int getVerticesSize(std::vector<Stap> vervoerLijst);


    void calculateGraph();


    void shortestPath(int startPunt); // print de korste route vanaf startPunt
    void printShortest(vector<int> dist);
    bool compareTo();
};


#endif //DIJKSTRA_REIS_H
