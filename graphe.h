#ifndef GRAPHE_H
#define GRAPHE_H
#include <string>
#include <unordered_map>
#include "sommet.h"
#include "arete.h"
#include <stack>
#include <queue>
#include "Svgfile.h"


class graphe
{
    public:
        ///v->getid(),ructeur qui charge le graphe en mémoire
        //format du fichier ordre/liste des sommets/taille/liste des arêtes
        graphe(std::string, std::string);
        ~graphe();
        void afficher();
        void dessiner(Svgfile& svgout);
        void kruskal();


    protected:

    private:
        /// Le réseau est constitué d'une collection de sommets
        std::unordered_map<int,Sommet*> m_sommets;//stockée dans une map (clé=id du sommet, valeur= pointeur sur le sommet)
        std::unordered_map<int,arete*> m_aretes;


};

#endif // GRAPHE_H
