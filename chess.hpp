#ifndef CHESS_HPP
#define CHESS_HPP

#include <iostream>
#include <cmath>
#include <vector>

#include "class_position.hpp"

using namespace std;

enum PieceColor {
	Blanc, Noir
};
enum PieceType {
	Pion, Tour, Fou, Cavalier, Dame, Roi
};

class type_piece{
public:
    PieceType Nom_piece;
    vector<vector<int>> Dep_rel;
    int valeur;
    ~type_piece(){
        Dep_rel.clear();

    }

};

class pion: public type_piece {
public:
	pion() {
		this->Nom_piece = Pion;
		this->valeur = 100;
		//int Tableau [][]
	}


};
class tour: public type_piece {
public:
	tour() {
		this->Nom_piece = Tour;

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
		this->Nom_piece = Fou;
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
		this->Nom_piece = Cavalier;


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
		this->Nom_piece = Dame;

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
		this->Nom_piece = Roi;

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
    //Constructeur de la classe
    ~piece(){

    }
    piece(){}
    piece(PieceType nom_piece, PieceColor couleur, int a, int b){
        if (nom_piece == Roi){
            roi piece;
            P = piece;
        }
        if (nom_piece == Pion){
            pion piece;
            P = piece;
        }
        if (nom_piece == Tour){
            tour piece;
            P = piece;
        }
        if (nom_piece == Dame){
            dame piece;
            P = piece;
        }
        if (nom_piece == Fou){
            fou piece;
            P = piece;
        }
        if (nom_piece == Cavalier){
            cavalier piece;
            P = piece;
        }
        x = a;
        y = b;
        if (couleur == Blanc){
            Couleur = Blanc;
        }
        if (couleur == Noir){
            Couleur = Noir;
        }

    }
    const char* string_type(){ //Permet de récuperer une chaine de caractère correspondant au Type de piece
        switch(P.Nom_piece){
            case Dame : return("D");
            case Roi : return("R");
            case Pion : return("P");
            case Cavalier : return("C");
            case Fou : return("F");
            case Tour : return("T");
        }
    }
};


class echiquier{
public:
    vector<piece*> plateau;
    //piece plateau[64];
    echiquier(){
        plateau.resize(64,NULL);
    }


    echiquier(const echiquier &p){ //constructeur par copie
        this->plateau.resize(64,NULL);
        for (int i = 0; i<=63; i++){
            piece* p_temp = new piece(p.plateau[i]->P.Nom_piece, p.plateau[i]->Couleur,p.plateau[i]->x,p.plateau[i]->y);
            this->plateau[i] = p_temp;
        }
    }


    void affichage();

    ~echiquier(){ //Destructeur de l'echiquier
        for (int i = 0; i<=63; i++){
            if (plateau[i] != NULL){
                delete plateau[i];
            }
        plateau.clear();
        }
    }
};

class coup_echec{
public:
    PieceColor couleur_c;
    piece* PJ = NULL;
    int i1;
    int i2;
    int j1;
    int j2;
    piece* Pprise = NULL;
    bool p_rooc;
    bool g_rooc;
    bool prom_f;
    bool prom_d;
    bool prom_c;
    bool prom_t;
    bool echec;
    bool echec_mat;
    void affichage_standard();

    coup_echec(){

    }
    ~coup_echec(){ //destructeur
        if (PJ!=NULL){
            delete PJ;
        }
        if (Pprise!=NULL){
            delete Pprise;
        }
    }

    coup_echec(const coup_echec &c){
        piece* p_temp = new piece(c.PJ->P.Nom_piece,c.PJ->Couleur,c.PJ->x,c.PJ->y);
        this->PJ = p_temp;
        piece* pprise_temp = new piece(c.Pprise->P.Nom_piece,c.Pprise->Couleur,c.Pprise->x,c.Pprise->y);
        this->Pprise = pprise_temp;
        this->couleur_c = c.couleur_c;
        this->i1 = c.i1;
        this->i2 = c.i2;
        this->j1 = c.j1;
        this->j2 = c.j2;
        this->p_rooc = c.p_rooc;
        this->g_rooc = c.g_rooc;
        this->prom_f = c.prom_f;
        this->prom_d = c.prom_d;
        this->prom_c = c.prom_c;
        this->prom_t = c.prom_t;
        this->echec = c.echec;
        this->echec_mat = c.echec_mat;

    }


    coup_echec(piece* piece_jouee,int x_init, int y_init, int x_final, int y_final){ // Coup correspondant à un déplacement
        piece* p_temp = new piece(piece_jouee->P.Nom_piece,piece_jouee->Couleur,piece_jouee->x,piece_jouee->y);
        PJ = p_temp;
        p_rooc = false;
        g_rooc = false;
        prom_f = false;
        prom_d = false;
        prom_c = false;
        prom_t = false;
        i1 = x_init;
        i2 = x_final;
        j2 = y_final;
        j1 = y_init;
        couleur_c = piece_jouee->Couleur;

    }
    coup_echec(piece* piece_jouee,piece* piece_prise,int x_init, int y_init, int x_final, int y_final){ // Coup correspondant à un déplacement
        piece* p_temp = new piece(piece_jouee->P.Nom_piece,piece_jouee->Couleur,piece_jouee->x,piece_jouee->y);
        PJ = p_temp;
        piece* pprise_temp = new piece(piece_prise->P.Nom_piece,piece_prise->Couleur,piece_prise->x,piece_prise->y);
        Pprise = pprise_temp;
        p_rooc = false;
        g_rooc = false;
        prom_f = false;
        prom_d = false;
        prom_c = false;
        prom_t = false;
        i1 = x_init;
        i2 = x_final;
        j2 = y_final;
        j1 = y_init;
        couleur_c = piece_jouee->Couleur;

    }
    coup_echec(char* nom_coup,PieceColor couleur){ //à modifier : mettre à jour pièce prise/joué +position
        couleur_c = couleur;
        p_rooc = false;
        g_rooc = false;
        prom_f = false;
        prom_d = false;
        prom_c = false;
        prom_t = false;
        if (nom_coup = "p_rooc"){p_rooc = true;}
        if (nom_coup = "g_rooc"){g_rooc = true;}
        if (nom_coup = "prom_f"){prom_f = true;}
        if (nom_coup = "prom_d"){prom_d = true;}
        if (nom_coup = "prom_c"){prom_c = true;}
        if (nom_coup = "prom_t"){prom_t = true;}

    }

};

class Position_Echec: public Position {
public:
    //std::list<coup_echec> Liste_coup;
    PieceColor couleur_joueur; //Couleur du joueur à qui c'est au tour de jouer
    coup_echec Dernier_coup;
    coup_echec* Liste_coup;
    echiquier echiquier_ref;

    Position_Echec(){
        Liste_coup = new coup_echec[10];
    }

    Position_Echec& position_possible(){ return *this;} //a def
    double valeur_position() const {return 0;} //a def
    bool test_echec(){return true;} //a def
    bool gagne()const {return true;} //correspond au test d'echec et mat

    ~Position_Echec(){              //def du destrcuteur
        delete[] Liste_coup;
    }

    bool test_match_nul();
    void print_position()const {cout<<"à faire"<<endl;} //à définir
    Position_Echec& mise_a_jour_position();

    //Constructeur
    Position_Echec(echiquier& E, PieceColor C, coup_echec* L){
        Liste_coup = new coup_echec[10];
        echiquier_ref = E;
        couleur_joueur = C;
        for (int i =0 ; i<int(sizeof(L));i++){
            Liste_coup[i] = L[i];
        }
    }

    Position_Echec(echiquier& E){
        Liste_coup = new coup_echec[10];
        echiquier_ref = E;


    }


} ;




//=============================
    //Fonctions externes
//=============================

echiquier echiquier_depart();
echiquier construction_echiquier(Position_Echec& P);

#endif
