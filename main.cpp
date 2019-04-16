#include <iostream>
#include "graphe.h"

int main()
{
    Svgfile svgout;
    graphe g{"manhattan.txt", "manhattan_weights_0.txt"};
    g.afficher();
    g.dessiner(svgout);

    //g.kruskal();

    return 0;
}
