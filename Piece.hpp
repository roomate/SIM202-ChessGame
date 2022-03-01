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
    vector<vector<int>> Dep_rel;
    int valeur;

};
class piece {
public:

	static const int valeur;
	type_piece P;
	PieceColor Couleur;
	int x;
    int y;
};

class pion: public type_piece {
public:
	pion() {
		this->Nom_piece = P;
		//int Tableau [][]
	}
	static const int valeur = 100;

};
class tour: public type_piece {
public:
	tour() {
		this->Nom_piece = T;

		vector<vector<int>> Tableau{ { 0, 1, 0, -1 },
                                     { 1, 0, -1, 0 },
                                     { 0, 0, 0, 0 } };

		this->Dep_rel= Tableau;
	}
	static const int valeur = 500;

};
class fou: public type_piece {
public:
	fou() {
		this->Nom_piece = F;
        vector<vector<int>> Tab{ { 1, 1, -1, -1 },
                                 { 1, -1, 1, -1 },
                                 { 0, 0, 0, 0 } };
		this->Dep_rel= Tab;
	}
	static const  int valeur = 300;

};
class cavalier: public type_piece {
public:
	cavalier() {
		this->Nom_piece = C;


		vector<vector<int>> Tableau{{ 1, 1, -1, -1, 2, 2, -2, -2 },
                                    { -2, 2, 2, -2, 1, -1, 1, -1},
                                    { 1, 1, 1, 1, 1, 1, 1, 1 } };



		this->Dep_rel= Tableau;
	}
	static const int valeur = 300;


};
class dame: public type_piece {
public:
	dame() {
		this->Nom_piece = D;

		vector<vector<int>> Tableau{{ 0, 1, 0, -1, 1, 1, -1, -1 },
                                    { 1, 0, -1, 0, 1, -1, 1, -1},
                                    { 0, 0, 0, 0, 0, 0, 0, 0 } };



		this->Dep_rel= Tableau;
	}
	static const int valeur = 900;

};
class roi: public type_piece {
public:
	roi() {
		this->Nom_piece = R;

		vector<vector<int>> Tableau{{ 0, 1, 0, -1, 1, 1, -1, -1 },
                                    { 1, 0, -1, 0, 1, -1, 1, -1},
                                    { 1, 1, 1, 1, 1, 1, 1, 1 } };
	}
	static const int valeur = 0;



};

#endif
