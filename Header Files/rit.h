//
// Created by daanv on 06/06/2022.
//

#ifndef DIJKSTRA_RIT_H
#define DIJKSTRA_RIT_H


class Rit {
private:
    int numberVertices = 0;

public:
    int benzinePrijs;
    int comfort;

    Rit(int benzinePrijs, int comfort);

    Rit();
    void setVerticesSize(int hoekpunten);
    int getVerticesSize();

    int calculateEdgeWeight(int afstand);
};


#endif //DIJKSTRA_RIT_H
