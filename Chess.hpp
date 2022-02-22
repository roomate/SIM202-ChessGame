
#ifndef CLASS_POSITION_HPP
#define CLASS_POSITION_HPP
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

#include "Piece.hpp"


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


/*



class type_piece{
public:
    char Nom_piece [1];
    int** Dep_rel;
    int valeur;

};

class piece{
public:
    type_piece P;
    char Couleur [1];
    int x;
    int y;

};*/


class echiquier{
public:
    piece* plateau[64];
    void affichage();
    piece* get_piece(short int x, short int y) {
		return plateau[x][y];
	}

    };

class coup_echec{
public:
    char couleur_c;
    piece PJ;
    int i1, i2;
    int j1, j2;
    piece Pprise;
    };


class Position_Echec: public Position
{
public:
    coup_echec* Liste_coup;
    echiquier echiquier_ref;
    Position_Echec& position_possible(Color);
    double valeur_position() ;


} ;






#endif // CLASS_PÖSITION_HPP
