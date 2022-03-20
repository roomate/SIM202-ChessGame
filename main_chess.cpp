#include "chess.hpp"
#include <cmath>
#include <iostream>
using namespace std;


int main(){

echiquier echiquier_d = echiquier_depart();
Position_Echec pos(echiquier_d);
pos.couleur_joueur=Blanc;
bool victoire_joueur = false; //Il joue les blancs
bool victoire_ordi = false; //Il joue les noirs
bool nul = false;
while (victoire_joueur == false && victoire_ordi == false && nul == false){
    pos.echiquier_ref.affichage();
    pos.coup_humain();
    pos.mise_a_jour_position();
    pos.echiquier_ref.affichage();
    if (pos.test_echec()==true){
        if(pos.couleur_joueur == Blanc){
            cout<<"Le joueur Noir est en position d'echec"<<endl;
        }
        if (pos.couleur_joueur==Noir){
            cout<<"Le joueur Blanc est en position d'echec"<<endl;
        }
    }
    pos.position_possible();
    cout<<pos.test_echec_mat()<<endl;
    if (pos.test_echec_mat()==true){
        if(pos.couleur_joueur==Blanc){
            cout<<"C'est un mat : Le joueur blanc a gagne !"<<endl;
            victoire_joueur = true;
        }
        if(pos.couleur_joueur==Noir){
            cout<<"C'est un mat : Le joueur noir a gagne !"<<endl;
            victoire_ordi = true;
        }
    }
    if (pos.test_match_nul()==true){
        cout<<"C'est un match nul !"<<endl;
        nul = true;
    }
}

