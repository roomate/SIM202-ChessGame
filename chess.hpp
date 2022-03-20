#ifndef CHESS_HPP
#define CHESS_HPP

#include <iostream>
#include <cmath>
#include <vector>
#include <list>

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
        Dep_rel=Tableau;
        this->valeur = 0;
	}




};


class piece{
public:
    type_piece P;
    PieceColor Couleur;
    int x;
    int y;
    bool a_bouger = false;
    //Constructeur de la classe
    ~piece(){

    }
    piece(piece& p){
        x = p.x;
        y = p.y;
        Couleur = p.Couleur;
        P = p.P;
        a_bouger = p.a_bouger;
    }



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
            if (p.plateau[i] != nullptr){
                piece* p_temp = new piece(p.plateau[i]->P.Nom_piece, p.plateau[i]->Couleur,p.plateau[i]->x,p.plateau[i]->y);
                this->plateau[i] = p_temp;
            }else if (p.plateau[i]==nullptr) {
                this->plateau[i] = nullptr;
            }
        }
    }
    echiquier &operator=(const echiquier &p){ //constructeur par copie
        this->plateau.resize(64,NULL);
        for (int i = 0; i<=63; i++){
            if (p.plateau[i] != nullptr){
                piece* p_temp = new piece(p.plateau[i]->P.Nom_piece, p.plateau[i]->Couleur,p.plateau[i]->x,p.plateau[i]->y);
                this->plateau[i] = p_temp;
            }else if (p.plateau[i]==nullptr){
                this->plateau[i] = nullptr;
            }
        }
        return *this;
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
    piece* PJ = nullptr;
    int i1;
    int i2;
    int j1;
    int j2;
    piece* Pprise = nullptr;
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
        if (PJ!=nullptr){
            delete PJ;
        }
        if (Pprise!=nullptr){
            delete Pprise;
        }
    }

    coup_echec(const coup_echec &c){
        if (c.PJ!=nullptr){
            piece* p_temp = new piece(c.PJ->P.Nom_piece,c.PJ->Couleur,c.PJ->x,c.PJ->y);
            this->PJ = p_temp;
        }
        if (c.Pprise != nullptr){
            piece* pprise_temp = new piece(c.Pprise->P.Nom_piece,c.Pprise->Couleur,c.Pprise->x,c.Pprise->y);
            this->Pprise = pprise_temp;
        }
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

    coup_echec &operator=(const coup_echec &c){
        if (c.PJ!=nullptr){
            piece* p_temp = new piece(c.PJ->P.Nom_piece,c.PJ->Couleur,c.PJ->x,c.PJ->y);
            this->PJ = p_temp;
        }
        if (c.Pprise != nullptr){
            piece* pprise_temp = new piece(c.Pprise->P.Nom_piece,c.Pprise->Couleur,c.Pprise->x,c.Pprise->y);
            this->Pprise = pprise_temp;
        }
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
        return *this;

    }



    coup_echec(piece* piece_jouee,int x_init, int y_init, int x_final, int y_final){ // Coup correspondant à un déplacement
        if (piece_jouee!=nullptr){
            piece* p_temp = new piece(piece_jouee->P.Nom_piece,piece_jouee->Couleur,piece_jouee->x,piece_jouee->y);
            PJ = p_temp;
        }
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
    coup_echec(piece* piece_jouee,piece* piece_prise,int x_init, int y_init, int x_final, int y_final){ // Coup correspondant à une prise de pièce
        if (piece_jouee!=nullptr){
            piece* p_temp = new piece(piece_jouee->P.Nom_piece,piece_jouee->Couleur,piece_jouee->x,piece_jouee->y);
            PJ = p_temp;
        }
        if (piece_prise!=nullptr){
            piece* pprise_temp = new piece(piece_prise->P.Nom_piece,piece_prise->Couleur,piece_prise->x,piece_prise->y);
            Pprise = pprise_temp;
        }
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
    coup_echec(char* nom_coup,PieceColor couleur){ //onstructeur pour les roocs
        couleur_c = couleur;
        p_rooc = false;
        g_rooc = false;
        prom_f = false;
        prom_d = false;
        prom_c = false;
        prom_t = false;
        if (nom_coup == "p_rooc"){p_rooc = true;}
        if (nom_coup == "g_rooc"){g_rooc = true;}


    }
    coup_echec(char* nom_coup,piece* piece_jouee,int x_init, int y_init, int x_final, int y_final){ //Constructeur pour les promotions
    if (piece_jouee!=nullptr){
        piece* p_temp = new piece(piece_jouee->P.Nom_piece,piece_jouee->Couleur,piece_jouee->x,piece_jouee->y);
        PJ = p_temp;
    }
    couleur_c = piece_jouee->Couleur;
    p_rooc = false;
    g_rooc = false;
    prom_f = false;
    prom_d = false;
    prom_c = false;
    prom_t = false;
    if (nom_coup == "prom_f"){prom_f = true;}
    if (nom_coup == "prom_d"){prom_d = true;}
    if (nom_coup == "prom_c"){prom_c = true;}
    if (nom_coup == "prom_t"){prom_t = true;}
    i1 = x_init;
    i2 = x_final;
    j2 = y_final;
    j1 = y_init;
    couleur_c = piece_jouee->Couleur;
    }

    coup_echec(char* nom_coup,piece* piece_jouee,piece* piece_prise,int x_init, int y_init, int x_final, int y_final){ //Constructeur pour les promotions avec prise
    if (piece_jouee!=nullptr){
        piece* p_temp = new piece(piece_jouee->P.Nom_piece,piece_jouee->Couleur,piece_jouee->x,piece_jouee->y);
        PJ = p_temp;
    }
    if (piece_prise!=nullptr){
        piece* pprise_temp = new piece(piece_prise->P.Nom_piece,piece_prise->Couleur,piece_prise->x,piece_prise->y);
        Pprise = pprise_temp;
    }
    couleur_c = piece_jouee->Couleur;
    p_rooc = false;
    g_rooc = false;
    prom_f = false;
    prom_d = false;
    prom_c = false;
    prom_t = false;
    if (nom_coup == "prom_f"){prom_f = true;}
    if (nom_coup == "prom_d"){prom_d = true;}
    if (nom_coup == "prom_c"){prom_c = true;}
    if (nom_coup == "prom_t"){prom_t = true;}
    i1 = x_init;
    i2 = x_final;
    j2 = y_final;
    j1 = y_init;
    couleur_c = piece_jouee->Couleur;
    }

};

class Position_Echec: public Position {
public:
    //std::list<coup_echec> Liste_coup;
    PieceColor couleur_joueur; //Couleur du joueur à qui c'est au tour de jouer
    coup_echec Dernier_coup;
    list<coup_echec> Liste_coup;
    echiquier echiquier_ref;

    Position_Echec(){
        //Liste_coup = new coup_echec[10];
    }

    Position_Echec& position_possible(); //a def
    double valeur_position() const {return 0;} //a def
    bool test_echec(); //a def
    bool test_echec_mat(); //correspond au test d'echec et mat
    bool test_p_rooc();
    bool test_g_rooc();

    Position_Echec& coup_humain();

    ~Position_Echec(){              //def du destrcuteur
        Liste_coup.clear();
    }

    bool test_match_nul();
    void print_position()const {cout<<"à faire"<<endl;} //à définir
    Position_Echec& mise_a_jour_position();

    //Constructeur
    Position_Echec(echiquier& E, PieceColor C, list<coup_echec> L){
        echiquier_ref = E;
        couleur_joueur = C;
        Liste_coup = L;
    }

    Position_Echec(echiquier& E){
        echiquier_ref = E;
    }

    Position_Echec(PieceColor couleur) : couleur_joueur(couleur){
    }


} ;




//=============================
    //Fonctions externes
//=============================

echiquier echiquier_depart();
echiquier echiquier_test_p_rooc();
echiquier echiquier_test_g_rooc();
echiquier echiquier_test_prom();
echiquier construction_echiquier(Position_Echec& P);
echiquier echiquier_test_echec();


#endif
