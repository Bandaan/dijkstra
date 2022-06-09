//
// Created by daanv on 06/06/2022.
//

#include "../Header Files/stap.h"
#include "../Header Files/rit.h"


Rit::Rit() {
}

Rit::Rit(int benzinePrijs, int comfort) {
    this->benzinePrijs = benzinePrijs;
    this->comfort = comfort;
}

int Rit::getVerticesSize() {
    return this->numberVertices;
}

void Rit::setVerticesSize(int hoekpunten) {
    this->numberVertices = hoekpunten;
}

int Rit::calculateEdgeWeight(int afstand) {
    // Gemiddeld auto rijdt gemiddeld 50 km / h

    double reistijd = (afstand * 60) / 50;

    double totalCost = afstand + this->benzinePrijs- this->comfort + reistijd;

    double edgeCost = (afstand * 0.4) + (this->benzinePrijs * 0.2) - (this->comfort * 0.1) + (0.3 * reistijd) / totalCost;

    return (int)edgeCost;
}

