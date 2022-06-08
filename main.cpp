#include "Header Files/reis.h"


int main()
{
    int V = 9;
    Reis g(V, 0, 8);

    // making above shown graph
    g.addEdge(Stap(0, 1, 4));
    g.addEdge(Stap(0, 7, 8));
    g.addEdge(Stap(1, 2, 8));
    g.addEdge(Stap(1, 7, 11));
    g.addEdge(Stap(2, 3, 7));
    g.addEdge(Stap(2, 8, 2));
    g.addEdge(Stap(2, 5, 4));
    g.addEdge(Stap(3, 4, 9));
    g.addEdge(Stap(3, 5, 14));
    g.addEdge(Stap(4, 5, 10));
    g.addEdge(Stap(5, 6, 2));
    g.addEdge(Stap(6, 7, 1));
    g.addEdge(Stap(6, 8, 6));
    g.addEdge(Stap(7, 8, 7));

    g.shortestPath(0);

    return 0;
}
