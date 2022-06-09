//
// Created by daanv on 06/06/2022.
//
#include "../Header Files/vlucht.h"


Vlucht::Vlucht() {
}

Vlucht::Vlucht(int kansKofferKwijt, int comfort) {
    this->kansKofferKwijt = kansKofferKwijt;
    this->comfort = comfort;
}

void Vlucht::setVerticesSize(int hoekpunten) {
    this->numberVertices = hoekpunten;
}

int Vlucht::getVerticesSize() {
    return this->numberVertices;
}

int Vlucht::calculateEdgeWeight(int afstand) {
    // Gemiddeld vliegtuig vliegt gemiddeld 900 km / h

    double reistijd = (afstand * 60) / 900;

    double totalCost = afstand + this->kansKofferKwijt - this->comfort + reistijd;

    double edgeCost = (afstand * 0.4) + (this->kansKofferKwijt * 0.2) - (this->comfort * 0.1) + (0.3 * reistijd) / totalCost;

    return (int)edgeCost;
}
