//
// Created by daanv on 06/06/2022.
//

#ifndef DIJKSTRA_STAP_H
#define DIJKSTRA_STAP_H

class Stap {
private:
    int beginStap;
    int eindStap;
    int gewicht;

public:
    Stap(int beginStap, int eindStap, int gewicht);
    Stap();

    int getBeginstap();
    int getEindstap();
    int getGewicht();
};
#endif //DIJKSTRA_STAP_H
