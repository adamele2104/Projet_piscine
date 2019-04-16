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
        ///v->getid(),ructeur qui charge le graphe en m�moire
        //format du fichier ordre/liste des sommets/taille/liste des ar�tes
        graphe(std::string, std::string);
        ~graphe();
        void afficher();
        void dessiner(Svgfile& svgout);
        void kruskal();


    protected:

    private:
        /// Le r�seau est constitu� d'une collection de sommets
        std::unordered_map<int,Sommet*> m_sommets;//stock�e dans une map (cl�=id du sommet, valeur= pointeur sur le sommet)
        std::unordered_map<int,arete*> m_aretes;


};

#endif // GRAPHE_H
