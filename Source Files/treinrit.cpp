//
// Created by daanv on 06/06/2022.
//

#include "../Header Files/treinrit.h"

Treinrit::Treinrit() {
}

Treinrit::Treinrit(int vertragingKans, int comfort) {
    this->vertragingKans = vertragingKans;
    this->comfort = comfort;

}

void Treinrit::setVerticesSize(int hoekpunten) {
    this->numberVertices = hoekpunten;
}

int Treinrit::getVerticesSize() {
    return this->numberVertices;
}

int Treinrit::calculateEdgeWeight(int afstand) {
    // Trein gemiddeld 100 km / h


    double reistijd = (afstand * 60) / 100;

    double totalCost = afstand + this->vertragingKans - this->comfort + reistijd;

    double edgeCost = (afstand * 0.4) + (this->vertragingKans * 0.2) - (this->comfort * 0.1) + (0.3 * reistijd) / totalCost;

    return (int)edgeCost;
}

