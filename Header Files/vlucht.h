//
// Created by daanv on 06/06/2022.
//

#ifndef DIJKSTRA_VLUCHT_H
#define DIJKSTRA_VLUCHT_H

class Vlucht {
private:
    // Opslag aantal hoekpunten
    int numberVertices = 0;

public:
    // opslag kans op kofferkwijt en comfort van schaal 1/10
    int kansKofferKwijt;
    int comfort;

    /// @brief
    /// Constructor op basis van meegegeven waarden
    /// @param kansKofferKwijt De kans dat je je koffer kwijt raakt van schaal 1/10
    /// @param comfort De comfort van de rit op schaal van 1/10

    Vlucht(int kansKofferKwijt, int comfort);

    /// @brief
    /// Default constructor

    Vlucht();

    /// @brief
    /// Aantal hoekpunten aanpassen
    /// @return niet van toepassing

    void setVerticesSize(int hoekpunten);

    /// @brief
    /// Aantal hoekpunten teruggeven
    /// @return int -> aantal hoekpunten

    int getVerticesSize();

    /// @brief
    /// Gewicht van hoekpunt naar hoekpunt berekenen.
    /// @param afstand De afstand van de reis
    /// @param afstand wordt berekend aan de hand van meerdere factoren en een formule
    /// @return int -> het nieuwe gewicht

    int calculateEdgeWeight(int afstand);
};
#endif //DIJKSTRA_VLUCHT_H
