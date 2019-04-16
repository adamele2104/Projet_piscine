#include <iostream>
#include <queue>
#include <stack>
#include<unordered_map>
#include<unordered_set>
#include "sommet.h"

Sommet::Sommet(int id,double x,double y):m_id{id},m_x{x},m_y{y}
{
}
void Sommet::ajouterVoisin(Sommet* voisin){
    m_voisins.push_back(voisin);
}
 void Sommet::afficherData(){
     std::cout<<"    "<<m_id<<" : "<<"(x,y)=("<<m_x<<","<<m_y<<")"<<std::endl;
 }
void Sommet::afficherVoisins(){
    std::cout<<"  voisins :"<<std::endl;
    for(auto v:m_voisins) {
        v->afficherData();
    }
}
int Sommet::getid(){
return m_id;
}
std::vector<Sommet*> Sommet::getvoisins()
{
    return m_voisins;
}
double Sommet::getY()
{
    return m_y;
}

double Sommet::getX()
{
    return m_x;
}



Sommet::~Sommet()
{
    //dtor
}
