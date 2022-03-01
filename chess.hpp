#ifndef CHESS_HPP
#define CHESS_HPP

#include <iostream>
#include <cmath>
#include <vector>

#include "class_position.hpp"

using namespace std;

enum PieceColor {
	b, n
};
enum PieceType {
	P, T, F, C, D, R
};

class type_piece{
public:
    PieceType Nom_piece;
    vector<vector<int>> Dep_rel;
    int valeur;

};

class pion: public type_piece {
public:
	pion() {
		this->Nom_piece = P;
		this->valeur = 100;
		//int Tableau [][]
	}


};
class tour: public type_piece {
public:
	tour() {
		this->Nom_piece = T;

		vector<vector<int>> Tableau{ { 0, 1, 0, -1 },
                                     { 1, 0, -1, 0 },
                                     { 0, 0, 0, 0 } };

		this->Dep_rel= Tableau;
		this->valeur = 500;
	}


};
class fou: public type_piece {
public:
	fou() {
		this->Nom_piece = F;
        vector<vector<int>> Tab{ { 1, 1, -1, -1 },
                                 { 1, -1, 1, -1 },
                                 { 0, 0, 0, 0 } };
		this->Dep_rel= Tab;
		this->valeur = 300;
	}


};
class cavalier: public type_piece {
public:
	cavalier() {
		this->Nom_piece = C;


		vector<vector<int>> Tableau{{ 1, 1, -1, -1, 2, 2, -2, -2 },
                                    { -2, 2, 2, -2, 1, -1, 1, -1},
                                    { 1, 1, 1, 1, 1, 1, 1, 1 } };



		this->Dep_rel= Tableau;
		this->valeur = 300;
	}



};
class dame: public type_piece {
public:
	dame() {
		this->Nom_piece = D;

		vector<vector<int>> Tableau{{ 0, 1, 0, -1, 1, 1, -1, -1 },
                                    { 1, 0, -1, 0, 1, -1, 1, -1},
                                    { 0, 0, 0, 0, 0, 0, 0, 0 } };



		this->Dep_rel= Tableau;
		this->valeur = 900;
	}


};
class roi: public type_piece {
public:
	roi() {
		this->Nom_piece = R;

		vector<vector<int>> Tableau{{ 0, 1, 0, -1, 1, 1, -1, -1 },
                                    { 1, 0, -1, 0, 1, -1, 1, -1},
                                    { 1, 1, 1, 1, 1, 1, 1, 1 } };
        this->valeur = 0;
	}




};


class piece{
public:
    type_piece P;
    PieceColor Couleur;
    int x;
    int y;

};


class echiquier{
public:
    piece plateau[64];
    void affichage();

    };

class coup_echec{
public:
    PieceColor couleur_c;
    piece PJ;
    int i1;
    int i2;
    int j1;
    int j2;
    piece Pprise;
    bool p_rooc;
    bool g_rooc;
    bool prom_f;
    bool prom_d;
    bool prom_c;
    bool prom_t;
    bool echec;
    bool echec_mat;
    void affichage_standard();

};

class Position_Echec: public Position {
public:
    //std::list<coup_echec> Liste_coup;
    PieceColor couleur_joueur; //Couleur du joueur à qui c'est au tour de jouer
    coup_echec* Liste_coup;
    echiquier echiquier_ref;
    Position_Echec& position_possible();
    double valeur_position() ;
    bool test_echec();
    bool test_echec_mat();


} ;

#endif
