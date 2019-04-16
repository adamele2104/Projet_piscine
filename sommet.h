#ifndef SOMMET_H
#define SOMMET_H
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>


class Sommet
{
    public:

        ///constructeur qui reçoit en params les données du sommet
        Sommet(int,double,double);
        void ajouterVoisin(Sommet*);
        void afficherData();
        void afficherVoisins();
        int getid();
         std::vector<Sommet*> getvoisins();
         double getX();
         double getY();

        ~Sommet();

    protected:

    private:
        /// Voisinage : liste d'adjacence

        std::vector<Sommet*> m_voisins;

        /// Données spécifiques du sommet
        int m_id; // Identifiant
        double m_x, m_y; // Position

};

#endif // SOMMET_H
