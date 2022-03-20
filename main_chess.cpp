#include <string>
#include "chess.hpp"
#include <cmath>
#include <iostream>
using namespace std;


//int main(){
//
//    echiquier echiquier_d = echiquier_depart();
//    Position_Echec pos(echiquier_d);
//    int minimaxi;
//    int mini;
//    int depth = 3;
//    bool victoire_joueur = false; //Il joue les blancs
//    bool victoire_ordi = false; //Il joue les noirs
//    bool nul = false;
//    string C;
//    cout<<"Voulez-vous jouez les blancs ou les Noirs ?"<<endl;
//    cin>>C;
//    while (c != Blanc && C != Noir)
//    {
//        if (C == Blanc)
//        {
//            pos.couleur_joueur = Blanc;
//        }
//        else if
//        {
//            pos.couleur_joueur = Noir;
//        }
//        else
//        {
//        cout<<"Ca ne correspond à aucune couleur"<<endl;
//        }
//    }
//    Position_Echec& posi = pos;
//    while (victoire_joueur == false && victoire_ordi == false && nul == false)
//    {
//        posi.echiquier_ref.affichage();
//        if (posi.test_echec()==true){
//            if(posi.couleur_joueur == Blanc){
//                cout<<"Le joueur Noir est en position d'echec"<<endl;
//            }
//            else
//            {
//                cout<<"Le joueur Blanc est en position d'echec"<<endl;
//            }
//        }
//        if (posi.joueur == 1)
//        {
//            posi.coup_humain();
//            posi.mise_a_jour_position();
//            posi.joueur = 0;
//        }
//        else if (posi.joueur == 0)
//        {
//            posi.fille = nullptr;
//            posi.position_possible();
//            if (posi.fille != nullptr)
//            {
//                Position* fille = posi.fille->soeur;
//                minimaxi = minimax(*posi.fille, 0,0 ,depth);
//                mini = minimaxi;
//                posi = dynamic_cast<Position_Echec&>(*fille);
//                while (fille != nullptr)
//                {
//                    minimaxi = minimax(*fille, 0, 0,depth);
//                    if (minimaxi < mini)
//                    {
//                        posi = dynamic_cast<Position_Echec&>(*fille);
//                        mini = minimaxi;
//                    }
//                    fille = fille->soeur;
//                }
//                posi.mise_a_jour_position();
//                posi.joueur = 1;
//            }
//        }
//        bool test_echecmat = posi.test_echec_mat();
//        if (test_echecmat)
//        {
//            if(posi.couleur_joueur==Blanc){
//                cout<<"C'est un mat : Le joueur blanc a gagne !"<<endl;
//                victoire_joueur = true;
//            }
//            if(posi.couleur_joueur==Noir){
//                cout<<"C'est un mat : Le joueur noir a gagne !"<<endl;
//                victoire_ordi = true;
//            }
//        }
// //       if (posi.test_match_nul()==true){
// //           cout<<"C'est un match nul !"<<endl;
// //           nul = true;
//        cout<<"==================================="<<endl;
//    }
//    if (victoire_joueur == true && victoire_ordi == false)
//    {
//        cout<<"Vous avez gagne"<<endl;
//    }
//    if (victoire_ordi == true && victoire_joueur == false)
//    {
//        cout<<"L'ordinateur a gagne"<<endl;
//    }
//    if (nul == true && victoire_ordi == false && victoire_joueur == false)
//    {
//        cout<<"Le match est nul"<<endl;
//    }
//    return 0;
//}








