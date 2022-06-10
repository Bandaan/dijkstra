#include "Header Files/reis.h"
#include "Header Files/vlucht.h"


int main()
{
    Reis g = Reis(0, 8);

    Vlucht v = Vlucht(10, 2);

    g.addEdgeVlucht(Stap(0, 1, 40), v);
    g.addEdgeVlucht(Stap(0, 7, 80), v);
    g.addEdgeVlucht(Stap(1, 2, 80), v);
    g.addEdgeVlucht(Stap(1, 7, 110), v);
    g.addEdgeVlucht(Stap(2, 3, 70), v);
    g.addEdgeVlucht(Stap(2, 8, 20), v);
    g.addEdgeVlucht(Stap(2, 5, 40), v);
    g.addEdgeVlucht(Stap(3, 4, 90), v);
    g.addEdgeVlucht(Stap(3, 5, 140), v);
    g.addEdgeVlucht(Stap(4, 5, 100), v);
    g.addEdgeVlucht(Stap(5, 6, 20), v);
    g.addEdgeVlucht(Stap(6, 7, 10), v);
    g.addEdgeVlucht(Stap(6, 8, 60), v);
    g.addEdgeVlucht(Stap(7, 8, 70), v);

    Rit r(10, 1);

    g.addEdgeRit(Stap(0, 1, 40), r);
    g.addEdgeRit(Stap(0, 7, 80), r);
    g.addEdgeRit(Stap(1, 2, 80), r);
    g.addEdgeRit(Stap(1, 7, 110), r);
    g.addEdgeRit(Stap(2, 3, 70), r);
    g.addEdgeRit(Stap(2, 8, 20), r);
    g.addEdgeRit(Stap(2, 5, 40), r);
    g.addEdgeRit(Stap(3, 4, 90), r);
    g.addEdgeRit(Stap(3, 5, 140), r);
    g.addEdgeRit(Stap(4, 5, 100), r);
    g.addEdgeRit(Stap(5, 6, 20), r);
    g.addEdgeRit(Stap(6, 7, 10), r);
    g.addEdgeRit(Stap(6, 8, 60), r);
    g.addEdgeRit(Stap(7, 8, 70), r);

    Treinrit t(10, 10);

    g.addEdgeTreinrit(Stap(0, 1, 40), t);
    g.addEdgeTreinrit(Stap(0, 7, 80), t);
    g.addEdgeTreinrit(Stap(1, 2, 80), t);
    g.addEdgeTreinrit(Stap(1, 7, 110), t);
    g.addEdgeTreinrit(Stap(2, 3, 70), t);
    g.addEdgeTreinrit(Stap(2, 8, 20), t);
    g.addEdgeTreinrit(Stap(2, 5, 40), t);
    g.addEdgeTreinrit(Stap(3, 4, 90), t);
    g.addEdgeTreinrit(Stap(3, 5, 140), t);
    g.addEdgeTreinrit(Stap(4, 5, 100), t);
    g.addEdgeTreinrit(Stap(5, 6, 20), t);
    g.addEdgeTreinrit(Stap(6, 7, 10), t);
    g.addEdgeTreinrit(Stap(6, 8, 60), t);
    g.addEdgeTreinrit(Stap(7, 8, 70), t);


    g.getShortestPath();

    g.compareTo();

    return 0;
}
