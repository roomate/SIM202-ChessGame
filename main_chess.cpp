#include <string>
#include "chess.hpp"
#include <cmath>
#include <iostream>
using namespace std;


int main(){

    echiquier echiquier_d = echiquier_depart();
    Position_Echec pos(echiquier_d);
    int minimaxi;
    int mini;
    int depth = 2;
    bool victoire_joueur = false; //Il joue les blancs
    bool victoire_ordi = false; //Il joue les noirs
    bool nul = false;
    string C;
    cout<<"Voulez-vous jouez les Blancs ou les Noirs ?"<<endl;
    cin>>C;
    while (C != "Blanc" && C != "Noir")
    {
        cout<<"Ca ne correspond à aucune couleur"<<endl;
        cin>>C;
    }
    if (C == "Blanc")
    {
        pos.joueur = 1;
    }
    else if (C == "Noir")
    {
        pos.joueur = 2;
    }
    pos.couleur_joueur = Blanc;
    Position_Echec& posi = pos;
    while (victoire_joueur == false && victoire_ordi == false && nul == false)
    {
        posi.echiquier_ref.affichage();
        if (posi.test_echec()==true){
            if(posi.couleur_joueur == Blanc){
                cout<<"Le joueur Noir est en position d'echec"<<endl;
            }
            else
            {
                cout<<"Le joueur Blanc est en position d'echec"<<endl;
            }
        }
        if (posi.joueur == 1)
        {
            posi.coup_humain();
            posi.mise_a_jour_position();
            posi.joueur = 2;
        }
        else if (posi.joueur == 2)
        {
            posi.fille = nullptr;
            posi.position_possible();
            Position_Echec& parent = posi;
            if (posi.fille != nullptr)
            {
                Position* fille = posi.fille->soeur;
                minimaxi = minimax(*posi.fille, 0,0 ,depth);
                mini = minimaxi;
                posi = dynamic_cast<Position_Echec&>(*fille);
                while (fille != nullptr)
                {
                    minimaxi = minimax(*fille, 0, 0,depth);
                    if (minimaxi < mini)
                    {
                        posi = dynamic_cast<Position_Echec&>(*fille);
                        mini = minimaxi;
                    }
                    fille = fille->soeur;
                }
                posi.mise_a_jour_position();
                posi.joueur = 1;
                parent.libere_fille(&posi);
            }
        }
        bool test_echecmat = posi.test_echec_mat();
        if (test_echecmat)
        {
            if(posi.couleur_joueur==Blanc){
                cout<<"C'est un mat : Le joueur blanc a gagne !"<<endl;
                victoire_joueur = true;
            }
            if(posi.couleur_joueur==Noir){
                cout<<"C'est un mat : Le joueur noir a gagne !"<<endl;
                victoire_ordi = true;
            }
        }
 //       if (posi.test_match_nul()==true){
 //           cout<<"C'est un match nul !"<<endl;
 //           nul = true;
        cout<<"==================================="<<endl;
    }
    if (victoire_joueur == true && victoire_ordi == false)
    {
        cout<<"Vous avez gagne"<<endl;
    }
    if (victoire_ordi == true && victoire_joueur == false)
    {
        cout<<"L'ordinateur a gagne"<<endl;
    }
    if (nul == true && victoire_ordi == false && victoire_joueur == false)
    {
        cout<<"Le match est nul"<<endl;
    }
    return 0;
}

//int main(){
//
//    echiquier echiquier_d = echiquier_test_echec_mat();
//    echiquier_d.affichage();
//    cout<<"==================================="<<endl;
//////    piece* actuel = echiquier_d.plateau[8*7 + 1];
//////    coup_echec C(actuel, 7, 1, 5, 0);
//    Position_Echec E(echiquier_d);
//    //E.echiquier_ref.affichage();
//    E.couleur_joueur = Blanc;
//    E.position_possible();
////    cout<<E.test_echec_mat()<<endl;
////    Position_Echec* fille = dynamic_cast<Position_Echec*>(E.fille->soeur);
////    fille->mise_a_jour_position();
////    fille->echiquier_ref.affichage();
//////    E.Liste_coup.push_back(C);
//////    E.mise_a_jour_position();
////    E.echiquier_ref.affichage();
//    cout<<minimax(E,0,0,2)<<endl;
//    return 0;
//}








