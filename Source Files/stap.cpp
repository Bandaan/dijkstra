//
// Created by daanv on 06/06/2022.
//

#include "../Header Files/stap.h"


Stap::Stap(int beginStap, int eindStap, int gewicht) {
    this->beginStap = beginStap;
    this->eindStap = eindStap;
    this->gewicht = gewicht;
}

Stap::Stap() {
    this->beginStap = 0;
    this->eindStap = 0;
    this->gewicht = 0;
}

int Stap::getBeginstap() {
    return this->beginStap;
}

int Stap::getEindstap() {
    return this->eindStap;
}

int Stap::getGewicht() {
    return this->gewicht;
}







