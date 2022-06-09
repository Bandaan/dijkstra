//
// Created by daanv on 06/06/2022.
//

#ifndef DIJKSTRA_TREINRIT_H
#define DIJKSTRA_TREINRIT_H


class Treinrit {
private:
    int numberVertices = 0;

public:
    int vertragingKans;
    int comfort;

    Treinrit(int vertragingKans, int comfort);

    Treinrit();
    void setVerticesSize(int hoekpunten);
    int getVerticesSize();

    int calculateEdgeWeight(int afstand);
};


#endif //DIJKSTRA_TREINRIT_H
