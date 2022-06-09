//
// Created by daanv on 06/06/2022.
//

#include "../Header Files/treinrit.h"

Treinrit::Treinrit() {
}

void Treinrit::setVerticesSize(int hoekpunten) {
    this->numberVertices = hoekpunten;
}

int Treinrit::getVerticesSize() {
    return this->numberVertices;
}
