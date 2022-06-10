//
// Created by daanv on 06/06/2022.
//

#ifndef DIJKSTRA_RIT_H
#define DIJKSTRA_RIT_H


class Rit {
private:
    // Opslag aantal hoekpunten
    int numberVertices = 0;

public:
    // opslag benzineprijs en comfort van schaal 1/10
    int benzinePrijs;
    int comfort;

    /// @brief
    /// Constructor op basis van meegegeven waarden
    /// @param benzinePrijs De hoogte van de benzine prijs van schaal 1 / 10
    /// @param comfort De comfort van de rit op schaal van 1/10

    Rit(int benzinePrijs, int comfort);

    /// @brief
    /// Default constructor
    Rit();

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


#endif //DIJKSTRA_RIT_H
