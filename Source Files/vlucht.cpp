//
// Created by daanv on 06/06/2022.
//
#include "../Header Files/vlucht.h"


Vlucht::Vlucht() {;
}

void Vlucht::setVerticesSize(int hoekpunten) {
    this->numberVertices = hoekpunten;
}

int Vlucht::getVerticesSize() {
    return this->numberVertices;
}
