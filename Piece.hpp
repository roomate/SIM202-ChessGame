#ifndef PIECE_HPP
#define PIECE_HPP

#include <iostream>
#include <vector>
#include <map>
//#include <cmath>
//#include <climits>

using namespace std;

enum PieceColor {
	b, n
};
enum PieceType {
	P, T, F, C, D, R
};


class type_piece{
public:
  //  virtual void print() = 0;
    PieceType Nom_piece;
    int** Dep_rel;
    int valeur;

};
class Piece {
public:

	static const int valeur;
	type_piece P;
	PieceColor Couleur;
	int x;
    int y;
};

class pion: public type_piece {
public:
	pion(PieceColor color) {
		this->Nom_piece = P;
		//int Tableau [][]
	}
	static const int valeur = 100;

};
class tour: public type_piece {
public:
	tour(PieceColor color) {
		this->Nom_piece = T;

		int** Tableau= new int*[4];
		Tableau[0][0] = 0;
		Tableau[0][1] = 1;
		Tableau[0][2] = 0;
		Tableau[0][3] = -1;
		Tableau[1][0] = 1;
		Tableau[1][1] = 0;
		Tableau[1][2] = -1;
		Tableau[1][3] = 0;
		Tableau[2][0] = 0;
		Tableau[2][1] = 0;
		Tableau[2][2] = 0;
		Tableau[2][3] = 0;
		this->Dep_rel= Tableau;
	}
	static const int valeur = 500;

};
class fou: public type_piece {
public:
	fou(PieceColor color) {
		this->Nom_piece = F;
        int Tab[3][4]={1,1,-1,-1,1,-1,1,-1,0,0,0,0};
		int** Tableau;
		Tableau=Tab;
		this->Dep_rel= Tableau;
	}
	static const  int valeur = 300;

};
class cavalier: public type_piece {
public:
	cavalier(PieceColor color) {
		this->Nom_piece = C;

		int Tableau[3][8]={1,1,-1,-1,2,2,-2,-2,2,-2,2,-2,1,-1,1,-1,0,-1,0,1,-1,1,-1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
		this->Dep_rel= Tableau;
	}
	static const int valeur = 300;


};
class dame: public type_piece {
public:
	dame(PieceColor color) {
		this->Nom_piece = D;
		this->color = color;
		int Tableau[3][8]={0,1,0,-1,1,1,-1,-1,1,0,-1,0,1,-1,1,-1,0,0,0,0,0,0,0,0};
		this->Dep_rel= Tableau;
	}
	static const int valeur = 900;

};
class roi: public type_piece {
public:
	roi(PieceColor color) {
		this->Nom_piece = R;

		int Tableau[3][8]={0,1,0,-1,1,1,-1,-1,1,0,-1,0,1,-1,1,-1,1,1,1,1,1,1,1,1};
		this->Dep_rel= Tableau;
	}
	static const int valeur = 0;



};

#endif
