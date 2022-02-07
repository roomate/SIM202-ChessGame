
#ifndef CLASS_POSITION_HPP
#define CLASS_POSITION_HPP

#include <iostream>
#include <cmath>
using namespace std;




class grille{
public:
    int* T;
    grille(const grille& g);
    grille();
    void affichage();
    bool a_gagne(int joueur);
    bool grille_pleine();
};


class Position
{
public:
    int joueur;
    Position(int J) : joueur(J) {}
    virtual double valeur_position() const =0;
    Position* fille = NULL;
    Position* soeur = NULL;
    virtual ~Position(){};
    virtual Position& position_possible() = 0;
    virtual void print_position(ostream& out) const = 0;
    virtual bool gagne();
};

class Position_Morpion : public Position
{
public:
    grille G;
    int possession(int i, int j) const {return G.T[i*3+j];}
    //~Position_Morpion()
    //{
       // if (G.T != nullptr) delete[] G.T;
    //}
    Position_Morpion& position_possible();
    bool gagne();
    double valeur_position() ;
    ~Position_Morpion()
    {
        delete this->G.T;
        delete this->fille;
        delete this->soeur;
    }
};


int minimax(Position &P, int alpha, int beta, bool maximizing, int depth );

#endif // CLASS_PÖSITION_HPP
