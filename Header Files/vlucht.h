//
// Created by daanv on 06/06/2022.
//

#ifndef DIJKSTRA_VLUCHT_H
#define DIJKSTRA_VLUCHT_H

class Vlucht {
private:
    int numberVertices = 0;

public:
    int kansKofferKwijt;
    int comfort;

    Vlucht(int kansKofferKwijt, int comfort);

    Vlucht();
    void setVerticesSize(int hoekpunten);
    int getVerticesSize();

    int calculateEdgeWeight(int afstand);
};
#endif //DIJKSTRA_VLUCHT_H
