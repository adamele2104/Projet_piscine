#include "arete.h"
#include <iostream>
#include <queue>
#include <string>
#include <stack>
#include<unordered_map>
#include<unordered_set>

arete::arete(int ida, int s1, int s2, float cout1, float cout2) : m_ida{ida}, m_s1{s1}, m_s2{s2}, m_cout1{cout1}, m_cout2{cout2}
{
    //ctor
}

arete::~arete()
{
    //dtor
}

int arete::getida(){
return m_ida;
}

int arete::getSommet1(){
return m_s1;
}

int arete::getSommet2(){
return m_s2;
}

float arete::getcout1(){
return m_cout1;
}

float arete::getcout2(){
return m_cout2;
}

void arete::afficherA(){
    std::cout<<"  "<< m_ida <<" relie : "<<m_s1<<" et "<<m_s2<< " dont poids 1 = " << m_cout1 <<" et poids 2 = "<<m_cout2<<std::endl;
 }
















