//
// Created by daanv on 08/06/2022.
//
#include "../Header Files/reis.h"
#include<bits/stdc++.h>

using namespace std;
# define INF 0x3f3f3f3f

Reis::Reis(int beginBestemming, int eindBestemming) {

    this->beginBestemming = beginBestemming;
    this->eindBestemming = eindBestemming;
}


bool Reis::stepExistsChange(Stap stap, std::vector<Stap> vervoerLijst) {
    bool stapExist = false;

    for(Stap &oudeStap : vervoerLijst) {
        if ((oudeStap.getBeginstap() == stap.getBeginstap()) && oudeStap.getEindstap() == stap.getEindstap()) {
            oudeStap.setGewicht(stap.getGewicht());
            stapExist = true;
        }
    }

    return stapExist;
}

void Reis::addEdgeVlucht(Stap stap, Vlucht & vlucht) {
    // Als het pad al bestaat dan het gewicht veranderen

    int newGewicht = vlucht.calculateEdgeWeight(stap.getGewicht());
    stap.setGewicht(newGewicht);

    if (!stepExistsChange(stap, vluchtStappen)) {
        vluchtStappen.push_back(stap);
    }
}

void Reis::addEdgeRit(Stap stap, Rit & rit) {
    // Als het pad al bestaat dan het gewicht veranderen

    int newGewicht = rit.calculateEdgeWeight(stap.getGewicht());
    stap.setGewicht(newGewicht);

    if (!stepExistsChange(stap, ritStappen)) {
        ritStappen.push_back(stap);
    }
}

void Reis::addEdgeTreinrit(Stap stap, Treinrit & treinrit) {
    // Als het pad al bestaat dan het gewicht veranderen

    int newGewicht = treinrit.calculateEdgeWeight(stap.getGewicht());
    stap.setGewicht(newGewicht);

    if (!stepExistsChange(stap, treinritStappen)) {
        treinritStappen.push_back(stap);
    }
}

int Reis::getVerticesSize(std::vector<Stap> vervoerLijst) {

    std::vector<int> v = {};

    for(Stap &stap : vervoerLijst) {
        if (!std::count(v.begin(), v.end(), stap.getBeginstap())) {
            v.push_back(stap.getBeginstap());
        }
        if (!std::count(v.begin(), v.end(), stap.getEindstap())) {
            v.push_back(stap.getEindstap());
        }
    }
    return v.size();
}

void Reis::setReisstatus() {
    if (getVerticesSize(vluchtStappen) != 0) {
        vluchtStatus = true;
        v.setVerticesSize(getVerticesSize(vluchtStappen));
    }
    if (getVerticesSize(ritStappen) != 0) {
        ritStatus = true;
        r.setVerticesSize(getVerticesSize(ritStappen));
    }
    if (getVerticesSize(treinritStappen) != 0) {
        treinritStatus = true;
        t.setVerticesSize(getVerticesSize(treinritStappen));
    }
}

void Reis::calculateGraph() {

    if (vluchtStatus) {
        verbindingVlucht = new list< pair<int, int> >[v.getVerticesSize()];

        for(Stap &stap : vluchtStappen) {
            verbindingVlucht[stap.getBeginstap()].push_back(make_pair(stap.getEindstap(), stap.getGewicht()));
            verbindingVlucht[stap.getEindstap()].push_back(make_pair(stap.getBeginstap(), stap.getGewicht()));
        }
    }
    if (ritStatus) {
        verbindingRit = new list< pair<int, int> >[r.getVerticesSize()];

        for(Stap &stap : ritStappen) {
            verbindingRit[stap.getBeginstap()].push_back(make_pair(stap.getEindstap(), stap.getGewicht()));
            verbindingRit[stap.getEindstap()].push_back(make_pair(stap.getBeginstap(), stap.getGewicht()));
        }
    }
    if (treinritStatus) {
        verbindingTreinrit = new list< pair<int, int> >[t.getVerticesSize()];

        for(Stap &stap : treinritStappen) {
            verbindingTreinrit[stap.getBeginstap()].push_back(make_pair(stap.getEindstap(), stap.getGewicht()));
            verbindingTreinrit[stap.getEindstap()].push_back(make_pair(stap.getBeginstap(), stap.getGewicht()));
        }
    }
}


void Reis::getShortestPath() {

    setReisstatus();
    calculateGraph();

    if (vluchtStatus) {
        vluchtResult = shortestPath(this->beginBestemming, v.getVerticesSize(), verbindingVlucht);
    }
    if (ritStatus) {
        ritResult = shortestPath(this->beginBestemming, r.getVerticesSize(), verbindingRit);
    }
    if (treinritStatus) {
        treinritResult = shortestPath(this->beginBestemming, t.getVerticesSize(), verbindingTreinrit);
    }


}

vector<int> Reis::shortestPath(int startPunt, int hoekPunten, list<pair<int, int>> * bestemmingLijst) {

    calculateGraph();

    // Maak een set om hoekpunten op te slaan
    set< pair<int, int> > setds;

    // Maak een vector voor afstand in combinatie met hoekpunten, afstand is infinite (INF)
    vector<int> dist(hoekPunten, INF);

    // Voeg het begin punt toe met een afstand van 0
    setds.insert(make_pair(0, startPunt));
    dist[startPunt] = 0;

    // Loop door de kortste afstand tot dat de set leeg is
    while (!setds.empty())
    {
        // Het eerste element (kortste afstand) wordt uit de set gehaald.
        pair<int, int> tmp = *(setds.begin());
        setds.erase(setds.begin());

        // hoekpunt label wordt opgeslagen in twee element van paar tmp
        int u = tmp.second;

        // i is alle aangrenzende hoekpunten met het hoekpunt
        list< pair<int, int> >::iterator i;

        for (i = bestemmingLijst[u].begin(); i != bestemmingLijst[u].end(); ++i)
        {
            // Hoekpunt label en gewicht van aangrenzende vertex
            int v = (*i).first;
            int weight = (*i).second;

            // Als een kortere weg is
            if (dist[v] > dist[u] + weight)
            {
                // Als de afstand niet INF is dan zit hij in de set
                // Element wordt verwijderd en wordt opnieuw toegevoegd met de vernieuwde afstand.
                if (dist[v] != INF) {
                    setds.erase(setds.find(make_pair(dist[v], v)));
                }
                // update de afstand
                dist[v] = dist[u] + weight;
                setds.insert(make_pair(dist[v], v));
            }
        }
    }
    return dist;
}


int Reis::compareTo() {
    // routes met elkaar combineren

    std::array<pair<std::string, int>, 3> vervoersmiddelen;

    printf("Vertex Distance from Source\n");

    if (vluchtStatus) {
        for (int i = 0; i < v.getVerticesSize(); ++i)
            printf("%d \t\t %d\n", i, vluchtResult[i]);

        vervoersmiddelen[0] = make_pair("vliegtuig", vluchtResult[this->eindBestemming]);

    }

    printf("Vertex Distance from Source\n");

    if (ritStatus) {

        for (int i = 0; i < v.getVerticesSize(); ++i)
            printf("%d \t\t %d\n", i, ritResult[i]);

        vervoersmiddelen[1] = make_pair("auto", ritResult[this->eindBestemming]);

    }

    printf("Vertex Distance from Source\n");

    if (treinritStatus) {
        for (int i = 0; i < v.getVerticesSize(); ++i)
            printf("%d \t\t %d\n", i, treinritResult[i]);

        vervoersmiddelen[2] = make_pair("trein", treinritResult[this->eindBestemming]);
    }

    std::sort(std::begin(vervoersmiddelen), std::end(vervoersmiddelen));

    printf("\nDe beste reis opties:\n");

    for(int i = 3; i-- > 0; ) {
        cout << i << ".\t" << vervoersmiddelen[i].first << endl;
    }

    return 0;
}

