//
// Created by daanv on 08/06/2022.
//
#include "../Header Files/reis.h"
#include "../Header Files/stap.h"


// Program to find Dijkstra's shortest path using STL set
#include<bits/stdc++.h>
using namespace std;
# define INF 0x3f3f3f3f


// Allocates memory for adjacency list
Reis::Reis(int hoekPunten, int beginBestemming, int eindBestemming) {
    this->hoekPunten = hoekPunten;
    this->beginBestemming = beginBestemming;
    this->eindBestemming = eindBestemming;

    stappen = new list< pair<int, int> >[hoekPunten];
}

bool Reis::compareTo() {
    return false;
}

void Reis::addEdge(Stap stap) {
    stappen[stap.getBeginstap()].push_back(make_pair(stap.getEindstap(), stap.getGewicht()));
    stappen[stap.getEindstap()].push_back(make_pair(stap.getBeginstap(), stap.getGewicht()));
}

void Reis::printShortest(vector<int> dist) {
    // Print shortest distances stored in dist[]
    printf("Vertex Distance from Source\n");
    for (int i = 0; i < hoekPunten; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
}

void Reis::shortestPath(int startPunt) {
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

        for (i = stappen[u].begin(); i != stappen[u].end(); ++i)
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

    printShortest(dist);
}
