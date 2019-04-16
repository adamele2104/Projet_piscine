#include <fstream>
#include <string>
#include <unordered_map>
#include <iostream>
#include "graphe.h"

graphe::graphe(std::string nomFichier,std::string nomFichier2 ){
    std::ifstream ifs{nomFichier};
    std::ifstream ifs2{nomFichier2};
    if (!ifs)
        throw std::runtime_error( "Impossible d'ouvrir en lecture " + nomFichier );
    if (!ifs2)
        throw std::runtime_error( "Impossible d'ouvrir en lecture " + nomFichier2 );

    int ordre;
    ifs >> ordre;

    if ( ifs.fail() )
        throw std::runtime_error("Probleme lecture ordre du graphe");

    int id;
    int ida;
    double x,y;

    //lecture des sommets

    for (int i=0; i<ordre; ++i){
        ifs>>id; if(ifs.fail()) throw std::runtime_error("Probleme lecture données sommet");
        ifs>>x; if(ifs.fail()) throw std::runtime_error("Probleme lecture données sommet");
        ifs>>y; if(ifs.fail()) throw std::runtime_error("Probleme lecture données sommet");
        m_sommets.insert({id,new Sommet{id,x,y}});
    }

    int taille;
    float cout1, cout2;

    ifs >> taille;

    int nbcout;
    int taille2;

    ifs2 >> taille2;

    ifs2 >> nbcout;
    if ( ifs2.fail() )
        throw std::runtime_error("Probleme lecture ordre du graphe");
    if ( ifs.fail() )
        throw std::runtime_error("Probleme lecture taille du graphe");
    int id_voisin;


    //lecture des aretes

    for (int i=0; i<taille2; ++i){

        //lecture des ids des deux extrémités

        ifs>>ida; if(ifs.fail()) throw std::runtime_error("Probleme lecture identifiant arete entre sommet 1 et 2");
        ifs>>id; if(ifs.fail()) throw std::runtime_error("Probleme lecture arete sommet 1");
        ifs>>id_voisin; if(ifs.fail()) throw std::runtime_error("Probleme lecture arete sommet 2");

        ifs2 >>ida; if(ifs2.fail()) throw std::runtime_error("Probleme lecture identifiant arete entre sommet 1 et 2");
        ifs2 >> cout1 ; if(ifs2.fail()) throw std::runtime_error("Probleme lecture poids 1 arete entre sommet 1 et 2");
        ifs2 >> cout2 ; if(ifs2.fail()) throw std::runtime_error("Probleme lecture poids 2 arete entre sommet 1 et 2");


        m_aretes.insert({ida, new arete{ida, id, id_voisin, cout1, cout2}});


        //ajouter chaque extrémité à la liste des voisins de l'autre (graphe non orienté)
        (m_sommets.find(id))->second->ajouterVoisin((m_sommets.find(id_voisin))->second);
        (m_sommets.find(id_voisin))->second->ajouterVoisin((m_sommets.find(id))->second);//remove si graphe orienté

    }


}


void graphe::afficher(){
    std::cout<<"graphe : "<<std::endl;
    std::cout<< "ordre : "<<m_sommets.size()<<std::endl;

    for ( auto  it = m_sommets.begin(); it != m_sommets.end(); ++it )
        {
            std::cout<<" sommet :";
            it->second->afficherData();
            it->second->afficherVoisins();
            std::cout<<std::endl;
        }
    for (auto  it = m_aretes.begin(); it != m_aretes.end(); ++it ){
        std::cout<<" arete : ";
        it->second->afficherA();
        std::cout<<std::endl;
    }

}





void graphe::dessiner(Svgfile& svgout){

double x1, y1, x2, y2;
double rayon = 7;

for(auto  it = m_sommets.begin(); it != m_sommets.end(); ++it){
        svgout.addDisk(it->second->getX(), it->second->getY(), rayon, "black");
}


for (auto it = m_aretes.begin(); it!=m_aretes.end(); ++it){
    std::unordered_map<int, Sommet*>::const_iterator got = m_sommets.find(it->second->getSommet1());
    if(got != m_sommets.end())
    {
        x1 = got->second->getX();
        y1 = got->second->getY();
    }
    got = m_sommets.find(it->second->getSommet2());
    if(got != m_sommets.end())
    {
        x2 = got->second->getX();
        y2 = got->second->getY();
    }
    svgout.addLine(x1,y1,x2,y2,"black");
}

}

/*
void graphe::kruskal(){

arete a;
std::map<arete> tab(m_aretes.end());
for (auto i:m_aretes){
        for (auto j:m_aretes){
             if( i->getcout1() < j->getcout1())
             a.m_cout1 = i->getcout1();
                tab.insert(a);
        }


}




}
*/


graphe::~graphe()
{
    //dtor
}
