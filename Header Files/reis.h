//
// Created by daanv on 08/06/2022.
//

#ifndef DIJKSTRA_REIS_H
#define DIJKSTRA_REIS_H


#include<bits/stdc++.h>
#include "comparable.h"
#include <vector>
#include "stap.h"
#include "vlucht.h"
#include "rit.h"
#include "treinrit.h"


using namespace std;
# define INF 0x3f3f3f3f

class Reis : public Comparable {

private:
    // opslag van beginBestemming en eindbestemming
    int beginBestemming;
    int eindBestemming;

    // opslag punten en gewichten van verbindingen
    list< pair<int, int> > *verbindingVlucht;
    list< pair<int, int> > *verbindingRit;
    list< pair<int, int> > *verbindingTreinrit;

    // opslag van stappen die worden toegevoegd
    std::vector<Stap> vluchtStappen = {};
    std::vector<Stap> ritStappen = {};
    std::vector<Stap> treinritStappen= {};

    // opslag van de kortste route van vervoersmiddel
    vector<int> vluchtResult {};
    vector<int> ritResult {};
    vector<int> treinritResult {};

public:
    // opslag van status van vervoersmiddelen
    bool vluchtStatus, ritStatus, treinritStatus = false;

    /// @brief
    /// Default constructor

    Vlucht v = Vlucht();

    /// @brief
    /// Default constructor

    Rit r = Rit();

    /// @brief
    /// Default constructor

    Treinrit t = Treinrit();

    /// @brief
    /// Constructor op basis van meegegeven waarden
    /// @param beginBestemming De beginbestemming van de reis
    /// @param eindBestemming De eindbestemming van de reis
    Reis(int beginBestemming, int eindBestemming); // Constructor

    /// @brief
    /// Constructor toevoegen aan vlucht lijst
    /// @param Stap De stap die wordt toegevoegd
    /// @param Vlucht De vlucht waarmee het gewicht berekend wordt.
    /// @return Niet van toepassing

    void addEdgeVlucht(Stap stap, Vlucht & vlucht);

    /// @brief
    /// Constructor toevoegen aan rit lijst
    /// @param Stap De stap die wordt toegevoegd
    /// @param Rit De rit waarmee het gewicht berekend wordt.
    /// @return Niet van toepassing

    void addEdgeRit(Stap stap, Rit & rit);

    /// @brief
    /// Constructor toevoegen aan treinrit lijst
    /// @param Stap De stap die wordt toegevoegd
    /// @param Treinrit De treinrit waarmee het gewicht berekend wordt.
    /// @return Niet van toepassing

    void addEdgeTreinrit(Stap stap, Treinrit & treinrit);

    /// @brief
    /// Reisstatus van vervoersmiddelen initialiseren
    /// @note bekijken welke vervoersmiddelen allemaal stappen hebben
    /// @note als ze geen stappen hebben -> false / Wel stappen -> true
    /// @return Niet van toepassing

    void setReisstatus();

    /// @brief
    /// Kijken of de stap al bestaat
    /// @note Als de stap al bestaat dan aanpassen met nieuwe gewicht
    /// @note als stap bestaat -> true / stap bestaat niet -> false
    /// @return bool

    bool stepExistsChange(Stap stap, std::vector<Stap> vervoerLijst);

    /// @brief
    /// Aantal hoekpunten berekenen
    /// @note per vervoersmiddel het aantal hoekpunten berekenen
    /// @return int -> aantal hoekpunten

    int getVerticesSize(std::vector<Stap> vervoerLijst);

    /// @brief
    /// De graaf initialiseren van een bepaald vervoersmiddel
    /// @note alle stappen toevoegen in een nieuwe graaf lijst
    /// @return niet van toepassing

    void calculateGraph();

    /// @brief
    /// Kortste route berekenen door dijkstra algoritme
    /// @note Doormiddel van startpunt, hoepunt en graaf de kortste route berekenen
    /// @return vector<int> -> vector met gewichten tussen hoekpunten

    vector<int> shortestPath(int startPunt, int hoekPunten, list<pair<int, int>> * bestemmingLijst); // print de korste route vanaf startPunt

    /// @brief
    /// Kortste route berekenen voor alle vervoersmiddelen
    /// @return niet van toepassing

    void getShortestPath();

    /// @brief
    /// Kortste route van vervoersmiddelen vergelijken
    /// @return int -> 0

    int compareTo();
};


#endif //DIJKSTRA_REIS_H
