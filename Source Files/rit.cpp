//
// Created by daanv on 06/06/2022.
//

#include "../Header Files/stap.h"
#include "../Header Files/rit.h"


Rit::Rit() {;
}

int Rit::getVerticesSize() {
    return this->numberVertices;
}

void Rit::setVerticesSize(int hoekpunten) {
    this->numberVertices = hoekpunten;
}
