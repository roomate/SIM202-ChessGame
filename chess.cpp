#include "chess.hpp"
#include <cmath>

void echiquier::affichage(){
    for (int i = 0; i<8; i++){
        for (int j=0; j<8; j++){
            if (plateau[i*8+j] != NULL){
                cout<<plateau[i*8+j]->P.Nom_piece<<plateau[i*8+j]->Couleur<<"  ";
            }else{
                cout<<"    ";
            }
        }
        cout<<endl;
    }
}


//======================================
//    "Affichage du coup"
//======================================

void coup_echec::affichage_standard(){
    cout<<"(";
    const char* alphat = "ABCDEFGH";
    if (p_rooc == true){
        cout<<"o-o";
    }
    else if (g_rooc == true){
        cout<<"o-o-o";
    }
    else if (prom_d == true){
        cout<<"Dame"<<alphat[i2]<<j2+1;
    }
    else if (prom_c == true){
        cout<<"Cavalier"<<alphat[i2]<<j2+1;
    }
    else if (prom_f == true){
        cout<<"Fou"<<alphat[i2]<<j2+1;
    }
    else if (prom_t == true){
        cout<<"Tour"<<alphat[i2]<<j2+1;
    }
    else {
        enum PieceType Roi = R;
        enum PieceType Dame = D;
        enum PieceType Fou = F;
        enum PieceType Cavalier = C;
        enum PieceType Pion = P;
        enum PieceType Tour = T;
        enum PieceColor Blanc = b;
        enum PieceColor Noir = n;
        if (PJ.P.Nom_piece == Roi){
            cout<<"Roi";
        }
        if (PJ.P.Nom_piece == Dame){
            cout<<"Dame";
        }
        if (PJ.P.Nom_piece == Fou){
            cout<<"Fou";
        }
        if (PJ.P.Nom_piece == Cavalier){
            cout<<"Cavalier";
        }
        if (PJ.P.Nom_piece == Tour){
            cout<<"Tour";
        }
        if (PJ.P.Nom_piece == Pion){
            cout<<"Pion";
        }
        if (PJ.Couleur == Blanc){
            cout<<" Blanc";
        }
        if (PJ.Couleur == Noir){
            cout<<" Noir";
        }
        cout<<alphat[j1]<<i1+1;
        cout<<"-";
        cout<<alphat[j2]<<i2+1;

    }
    if (echec == true){
        cout<<"+";
    }
    if (echec_mat == true){
        cout<<"++";
    }
    cout<<")";
}

//======================================
//    "Construction de l'echiquier"
//======================================


echiquier construction_echequier(Position_Echec& P){
    int N = sizeof(P.Liste_coup);
    echiquier echiquier_final = P.echiquier_ref; //Il faut un constructeur par copie ?
    enum PieceColor Blanc = b;
    enum PieceColor Noir = n;
    for (int i = 0;i<N;i++){
        if (P.Liste_coup[i].p_rooc== true){
            if (P.Liste_coup[i].couleur_c == Blanc){
                echiquier_final.plateau[6] = echiquier_final.plateau[4];
                echiquier_final.plateau[6]->x = 0;
                echiquier_final.plateau[6]->y = 6;
                echiquier_final.plateau[4] = NULL;
                echiquier_final.plateau[5] = echiquier_final.plateau[7];
                echiquier_final.plateau[5]->x = 0;
                echiquier_final.plateau[5]->y = 5;
                echiquier_final.plateau[7] = NULL;
            }
            if (P.Liste_coup[i].couleur_c == Noir){
                echiquier_final.plateau[61] = echiquier_final.plateau[63];
                echiquier_final.plateau[61]->x = 7;
                echiquier_final.plateau[61]->y = 5;
                echiquier_final.plateau[63] = NULL;
                echiquier_final.plateau[62] = echiquier_final.plateau[60];
                echiquier_final.plateau[62]->x = 7;
                echiquier_final.plateau[62]->y = 6;
                echiquier_final.plateau[60] = NULL;
            }

        }
        else if (P.Liste_coup[i].g_rooc == true){
            if (P.Liste_coup[i].couleur_c == Blanc){
                echiquier_final.plateau[2] = echiquier_final.plateau[4];
                echiquier_final.plateau[2]->x = 0;
                echiquier_final.plateau[2]->y = 2;
                echiquier_final.plateau[4] = NULL;
                echiquier_final.plateau[3] = echiquier_final.plateau[0];
                echiquier_final.plateau[3]->x = 0;
                echiquier_final.plateau[3]->y = 3;
                echiquier_final.plateau[0] = NULL;
            }
            if (P.Liste_coup[i].couleur_c == Noir){
                echiquier_final.plateau[59] = echiquier_final.plateau[56];
                echiquier_final.plateau[59]->x = 7;
                echiquier_final.plateau[59]->y = 3;
                echiquier_final.plateau[56] = NULL;
                echiquier_final.plateau[58] = echiquier_final.plateau[60];
                echiquier_final.plateau[58]->x = 7;
                echiquier_final.plateau[58]->y = 2;
                echiquier_final.plateau[60] = NULL;
            }

        }
        else if (P.Liste_coup[i].prom_f == true){
                piece* promotion = echiquier_final.plateau[P.Liste_coup[i].i1*8+P.Liste_coup[i].j1];
                fou type_prom;
                promotion->P = type_prom;
                promotion->x = P.Liste_coup[i].i2;
                promotion->y = P.Liste_coup[i].j2;
                echiquier_final.plateau[P.Liste_coup[i].i2*8+P.Liste_coup[i].j2] = promotion;
                echiquier_final.plateau[P.Liste_coup[i].i1*8+P.Liste_coup[i].j1] = NULL;

        }
        else if (P.Liste_coup[i].prom_d == true){
                piece* promotion = echiquier_final.plateau[P.Liste_coup[i].i1*8+P.Liste_coup[i].j1];
                dame type_prom;
                promotion->P = type_prom;
                promotion->x = P.Liste_coup[i].i2;
                promotion->y = P.Liste_coup[i].j2;
                echiquier_final.plateau[P.Liste_coup[i].i2*8+P.Liste_coup[i].j2] = promotion;
                echiquier_final.plateau[P.Liste_coup[i].i1*8+P.Liste_coup[i].j1] = NULL;

        }
        else if (P.Liste_coup[i].prom_t == true){
                piece* promotion = echiquier_final.plateau[P.Liste_coup[i].i1*8+P.Liste_coup[i].j1];
                tour type_prom;
                promotion->P = type_prom;
                promotion->x = P.Liste_coup[i].i2;
                promotion->y = P.Liste_coup[i].j2;
                echiquier_final.plateau[P.Liste_coup[i].i2*8+P.Liste_coup[i].j2] = promotion;
                echiquier_final.plateau[P.Liste_coup[i].i1*8+P.Liste_coup[i].j1] = NULL;

        }
        else if (P.Liste_coup[i].prom_c == true){
                piece* promotion = echiquier_final.plateau[P.Liste_coup[i].i1*8+P.Liste_coup[i].j1];
                cavalier type_prom;
                promotion->P = type_prom;
                promotion->x = P.Liste_coup[i].i2;
                promotion->y = P.Liste_coup[i].j2;
                echiquier_final.plateau[P.Liste_coup[i].i2*8+P.Liste_coup[i].j2] = promotion;
                echiquier_final.plateau[P.Liste_coup[i].i1*8+P.Liste_coup[i].j1] = NULL;

        }
        else {
                piece* temp = echiquier_final.plateau[P.Liste_coup[i].i1*8+P.Liste_coup[i].j1];
                temp->x = P.Liste_coup[i].i2;
                temp->y = P.Liste_coup[i].j2;
                echiquier_final.plateau[P.Liste_coup[i].i2*8+P.Liste_coup[i].j2] = temp;
                echiquier_final.plateau[P.Liste_coup[i].i1*8+P.Liste_coup[i].j1] = NULL;
        }
    }
    return(echiquier_final);
}

double Position_Echec::valeur_position(){

}

bool Position_Echec::test_echec(){
    echiquier echiquier_final = construction_echequier(*this);
    int pos_x_roi;
    int pos_y_roi;
    for(int i = 0; i<64;i++){
        if (echiquier_final.plateau[i].P.Nom_piece = "R" && echiquier_final.plateau[i].Couleur = couleur_joueur){
            pos_x_roi = echiquier_final.plateau[i].x;
            pos_y_roi = echiquier_final.plateau[i].y;
        }
    }

}


