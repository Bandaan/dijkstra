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

    vector<int> vluchtResult {};
    vector<int> ritResult {};
    vector<int> treinritResult {};

public:
    Vlucht v = Vlucht();
    Rit r = Rit();
    Treinrit t = Treinrit();

    bool vluchtStatus, ritStatus, treinritStatus = false;

    Reis(int beginBestemming, int eindBestemming); // Constructor

    void addEdgeVlucht(Stap stap, Vlucht & vlucht);  // functie om een punt toe te voegen
    void addEdgeRit(Stap stap, Rit & rit);  // functie om een punt toe te voegen
    void addEdgeTreinrit(Stap stap, Treinrit & treinrit);  // functie om een punt toe te voegen

    void setReisstatus();
    bool stepExistsChange(Stap stap, std::vector<Stap> vervoerLijst);
    int getVerticesSize(std::vector<Stap> vervoerLijst);
    void calculateGraph();


    vector<int> shortestPath(int startPunt, int hoekPunten, list<pair<int, int>> * bestemmingLijst); // print de korste route vanaf startPunt
    void getShortestPath();

    int compareTo();
};


#endif //DIJKSTRA_REIS_H
