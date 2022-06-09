#include "Header Files/reis.h"


int main()
{
    int V = 9;
    Reis g(3, 8);

    // making above shown graph
    g.addEdgeVlucht(Stap(0, 1, 4));
    g.addEdgeVlucht(Stap(0, 7, 8));
    g.addEdgeVlucht(Stap(1, 2, 8));
    g.addEdgeVlucht(Stap(1, 7, 11));
    g.addEdgeVlucht(Stap(2, 3, 7));
    g.addEdgeVlucht(Stap(2, 8, 2));
    g.addEdgeVlucht(Stap(2, 5, 4));
    g.addEdgeVlucht(Stap(3, 4, 9));
    g.addEdgeVlucht(Stap(3, 5, 14));
    g.addEdgeVlucht(Stap(4, 5, 10));
    g.addEdgeVlucht(Stap(5, 6, 2));
    g.addEdgeVlucht(Stap(6, 7, 1));
    g.addEdgeVlucht(Stap(6, 8, 6));
    g.addEdgeVlucht(Stap(7, 8, 7));


    g.addEdgeRit(Stap(0, 1, 2));
    g.addEdgeRit(Stap(0, 2, 3));
    g.addEdgeRit(Stap(1, 3, 6));
    g.addEdgeRit(Stap(2, 3, 4));
    g.addEdgeRit(Stap(3, 4, 1));
    g.addEdgeRit(Stap(3, 5, 8));
    g.addEdgeRit(Stap(4, 6, 1));
    g.addEdgeRit(Stap(5, 6, 1));

    g.getShortestPath();

    return 0;
}
