//
// Created by daanv on 08/06/2022.
//
#include "../Header Files/reis.h"
#include "../Header Files/stap.h"
#include "../Header Files/vlucht.h"
#include "../Header Files/rit.h"
#include "../Header Files/treinrit.h"


// Program to find Dijkstra's shortest path using STL set
#include<bits/stdc++.h>

using namespace std;
# define INF 0x3f3f3f3f


// Allocates memory for adjacency list
Reis::Reis(int beginBestemming, int eindBestemming) {

    this->beginBestemming = beginBestemming;
    this->eindBestemming = eindBestemming;
}


bool Reis::stepExistsChange(Stap stap, std::vector<Stap> vervoerLijst) {
    bool stapExist = false;

    for(Stap &oudeStap : vervoerLijst) {
        if ((oudeStap.getBeginstap() == stap.getBeginstap()) && oudeStap.getEindstap() == stap.getEindstap()) {
            oudeStap.setGewicht(stap.getGewicht());
            stapExist = true;
        }
    }

    return stapExist;
}

void Reis::addEdgeVlucht(Stap stap) {
    // Als het pad al bestaat dan het gewicht veranderen
    if (!stepExistsChange(stap, vluchtStappen)) {
        vluchtStappen.push_back(stap);
    }
}

void Reis::addEdgeRit(Stap stap) {
    // Als het pad al bestaat dan het gewicht veranderen
    if (!stepExistsChange(stap, ritStappen)) {
        ritStappen.push_back(stap);
    }
}


void Reis::addEdgeTreinrit(Stap stap) {
    // Als het pad al bestaat dan het gewicht veranderen
    if (!stepExistsChange(stap, treinritStappen)) {
        treinritStappen.push_back(stap);
    }
}

int Reis::getVerticesSize(std::vector<Stap> vervoerLijst) {

    std::vector<int> v = {};

    for(Stap &stap : vervoerLijst) {
        if (!std::count(v.begin(), v.end(), stap.getBeginstap())) {
            v.push_back(stap.getBeginstap());
        }
        if (!std::count(v.begin(), v.end(), stap.getEindstap())) {
            v.push_back(stap.getEindstap());
        }
    }
    return v.size();
}

void Reis::setReisstatus() {
    if (getVerticesSize(vluchtStappen) != 0) {
        vluchtStatus = true;
        v.setVerticesSize(getVerticesSize(vluchtStappen));
    }
    if (getVerticesSize(ritStappen) != 0) {
        ritStatus = true;
        r.setVerticesSize(getVerticesSize(ritStappen));
    }
    if (getVerticesSize(treinritStappen) != 0) {
        treinritStatus = true;
        t.setVerticesSize(getVerticesSize(treinritStappen));
    }
}

void Reis::calculateGraph() {

    if (vluchtStatus) {
        verbindingVlucht = new list< pair<int, int> >[v.getVerticesSize()];

        for(Stap &stap : vluchtStappen) {
            verbindingVlucht[stap.getBeginstap()].push_back(make_pair(stap.getEindstap(), stap.getGewicht()));
            verbindingVlucht[stap.getEindstap()].push_back(make_pair(stap.getBeginstap(), stap.getGewicht()));
        }
    }
    if (ritStatus) {
        verbindingRit = new list< pair<int, int> >[r.getVerticesSize()];

        for(Stap &stap : ritStappen) {
            verbindingRit[stap.getBeginstap()].push_back(make_pair(stap.getEindstap(), stap.getGewicht()));
            verbindingRit[stap.getEindstap()].push_back(make_pair(stap.getBeginstap(), stap.getGewicht()));
        }
    }
    if (treinritStatus) {
        verbindingTreinrit = new list< pair<int, int> >[t.getVerticesSize()];

        for(Stap &stap : treinritStappen) {
            verbindingTreinrit[stap.getBeginstap()].push_back(make_pair(stap.getEindstap(), stap.getGewicht()));
            verbindingTreinrit[stap.getEindstap()].push_back(make_pair(stap.getBeginstap(), stap.getGewicht()));
        }
    }
}


void Reis::getShortestPath() {

    setReisstatus();
    calculateGraph();

    if (vluchtStatus) {
        vector<int> vluchtResult = shortestPath(this->beginBestemming, v.getVerticesSize(), verbindingVlucht);
        printShortest(vluchtResult, v.getVerticesSize());
    }
    if (ritStatus) {
        vector<int> ritResult = shortestPath(this->beginBestemming, r.getVerticesSize(), verbindingRit);
        printShortest(ritResult, r.getVerticesSize());
    }
    if (treinritStatus) {
        vector<int> treinritResult = shortestPath(this->beginBestemming, t.getVerticesSize(), verbindingTreinrit);
        printShortest(treinritResult, t.getVerticesSize());
    }


}

vector<int> Reis::shortestPath(int startPunt, int hoekPunten, list<pair<int, int>> * bestemmingLijst) {

    calculateGraph();

    set< pair<int, int> > setds;     // Create a set to store vertices that are being

    vector<int> dist(hoekPunten, INF); // Create a vector for distances and initialize all, distances as infinite (INF)

    // Insert source itself in Set and initialize its
    // distance as 0.
    setds.insert(make_pair(0, startPunt));
    dist[startPunt] = 0;

    /* Looping till all shortest distance are finalized then setds will become empty */
    while (!setds.empty())
    {
        pair<int, int> tmp = *(setds.begin());         // The first vertex in Set is the minimum distance
        setds.erase(setds.begin());                    // vertex, extract it from set.

        // vertex label is stored in second of pair (it
        // has to be done this way to keep the vertices
        // sorted distance (distance must be first item
        // in pair)
        int u = tmp.second;

        // 'i' is used to get all adjacent vertices of a vertex
        list< pair<int, int> >::iterator i;

        for (i = bestemmingLijst[u].begin(); i != bestemmingLijst[u].end(); ++i)
        {
            // Get vertex label and weight of current adjacent
            // of u.
            int v = (*i).first;
            int weight = (*i).second;

            // If there is shorter path to v through u.
            if (dist[v] > dist[u] + weight)
            {
                /* If distance of v is not INF then it must be in
                    our set, so removing it and inserting again
                    with updated less distance.
                    Note : We extract only those vertices from Set
                    for which distance is finalized. So for them,
                    we would never reach here. */
                if (dist[v] != INF) {
                    setds.erase(setds.find(make_pair(dist[v], v)));
                }

                // Updating distance of v
                dist[v] = dist[u] + weight;
                setds.insert(make_pair(dist[v], v));
            }
        }
    }
    return dist;
}

void Reis::printShortest(vector<int> dist , int hoekPunten) {
    // Print shortest distances stored in dist[]
    printf("Vertex Distance from Source\n");
    for (int i = 0; i < hoekPunten; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
}


bool Reis::compareTo() {
    return false;
}

