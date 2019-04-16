#ifndef ARETE_H
#define ARETE_H
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include "sommet.h"
#include <stack>
#include <queue>

class arete
{
    public:
        arete(int,int, int, float, float);
        int getida();
        int getSommet1();
        int getSommet2();
        float getcout1();
        float getcout2();
        void afficherA();

        ~arete();


    protected:

    private:

        int m_ida;
        int m_s1, m_s2;
        float m_cout1, m_cout2;



};

#endif // ARETE_H
