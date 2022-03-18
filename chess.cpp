#include "chess.hpp"
#include <cmath>

//====================================

const int alpha = 1;
const int beta = 1;

const int MAX = 1000;
const int MIN = -1000;

//====================================

void echiquier::affichage(){

    for (int i = 7; i>=0; i--){
        for (int j=0; j<8; j++){
            if (plateau[i*8+j] != NULL){
                cout<<plateau[i*8+j]->string_type()<<(plateau[i*8+j]->Couleur==Blanc?"b":"n")<<"  ";
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
        if (PJ->P.Nom_piece == Roi){
            cout<<"Roi";
        }
        if (PJ->P.Nom_piece == Dame){
            cout<<"Dame";
        }
        if (PJ->P.Nom_piece == Fou){
            cout<<"Fou";
        }
        if (PJ->P.Nom_piece == Cavalier){
            cout<<"Cavalier";
        }
        if (PJ->P.Nom_piece == Tour){
            cout<<"Tour";
        }
        if (PJ->P.Nom_piece == Pion){
            cout<<"Pion";
        }
        if (PJ->Couleur == Blanc){
            cout<<" Blanc";
        }
        if (PJ->Couleur == Noir){
            cout<<" Noir";
        }
        cout<<" "<<alphat[j1]<<i1+1;
        cout<<"-";
        cout<<alphat[j2]<<i2+1;

    }
    if (echec == true){
        cout<<"+";
    }
    if (echec_mat == true){
        cout<<"++";
    }
    cout<<")"<<endl;
}

//======================================
//    "Construction de l'echiquier"
//======================================


echiquier construction_echiquier(Position_Echec& P){
    int N = sizeof(P.Liste_coup);
    echiquier echiquier_final = P.echiquier_ref; //Il faut un constructeur par copie ?
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


Position_Echec& Position_Echec::mise_a_jour_position(){ //Met à jour l'echiquier de ref, vide la liste de coup, et determine le joueur à qui c'est au tour de jouer
    int N = sizeof(this->Liste_coup);
    this->Dernier_coup = this->Liste_coup[N-1]; //Recup du dernier coup


    enum PieceColor Dernier_joueur = this->Liste_coup[N-1].couleur_c;
    if (Dernier_joueur = Blanc){
        this->couleur_joueur = Noir;
    }
    if (Dernier_joueur = Noir){
        this->couleur_joueur = Blanc;
    }

    echiquier_ref = construction_echiquier(*this); //Mise à jour de l'echiquier
    

    delete[] Liste_coup;

    return *this;
}

/* Mise en commentaire en attendant d'avoir créer test echec

double Position_Echec::valeur_position(){
    this->mise_a_jour_position();
    echiquier echiquier_final = construction_echiquier(*this);
    int cont_blanc = 0;
    int cont_noir = 0;
    int val_blanc = 0;
    int val_noir = 0;
    int val;
    if (this->test_echec_mat()==true){
        return MAX;
    } else if (this->test_match_nul()==true) {
        return 0;
    } else {
        for(int i = 0; i<64;i++){
            if (echiquier_final.plateau[i] != NULL)
                if (echiquier_final.plateau[i]->Couleur = Blanc){
                    cont_blanc = cont_blanc +1;
                    val_blanc = val_blanc + echiquier_final.plateau[i]->P.valeur;
                } else if (echiquier_final.plateau[i]->Couleur = Noir){
                    cont_noir = cont_noir +1;
                    val_noir = val_noir + echiquier_final.plateau[i]->P.valeur;
                }
        }
        val = alpha *(val_blanc - val_noir) + beta*(cont_blanc - cont_noir);
        return val;
    }
}

*/

echiquier echiquier_depart(){
    echiquier E;
    piece* P_0 = new piece(Tour,Blanc,0,0);
    E.plateau[0]= P_0;
    piece* P_1 = new piece(Cavalier,Blanc,0,1);
    E.plateau[1]= P_1;
    piece* P_2= new piece(Fou,Blanc,0,2);
    E.plateau[2]= P_2;
    piece* P_3= new piece(Dame,Blanc,0,3);
    E.plateau[3]= P_3;
    piece* P_4= new piece(Roi,Blanc,0,4);
    E.plateau[4]= P_4;
    piece* P_5= new piece(Fou,Blanc,0,5);
    E.plateau[5]= P_5;
    piece* P_6= new piece(Cavalier,Blanc,0,6);
    E.plateau[6]= P_6;
    piece* P_7= new piece(Tour,Blanc,0,7);
    E.plateau[7]= P_7;
    for (int i = 0; i<=7; i++){
        piece* temp_P= new piece(Pion,Blanc,1,i);
        E.plateau[8+i] = temp_P;
    }
    piece* P_56 = new piece(Tour,Noir,7,0);
    E.plateau[56]= P_56;
    piece* P_57 = new piece(Cavalier,Noir,7,1);
    E.plateau[57]= P_57;
    piece* P_58 = new piece(Fou,Noir,7,2);
    E.plateau[58]= P_58;
    piece* P_59= new piece(Dame,Noir,7,3);
    E.plateau[59]= P_59;
    piece* P_60= new piece(Roi,Noir,7,4);
    E.plateau[60]= P_60;
    piece* P_61= new piece(Fou,Noir,7,5);
    E.plateau[61]= P_61;
    piece* P_62= new piece(Cavalier,Noir,7,6);
    E.plateau[62]= P_62;
    piece* P_63= new piece(Tour,Noir,7,7);
    E.plateau[63]= P_63;
    for (int i = 0; i<=7; i++){
        piece* temp_P= new piece(Pion,Noir,6,i);
        E.plateau[6*8+i] = temp_P;
    }
    return E;
}

/* A FAIRE
bool Position_Echec::test_echec(){
    echiquier echiquier_final = construction_echiquier(*this);
    int pos_x_roi;
    int pos_y_roi;
    for(int i = 0; i<64;i++){
        if (echiquier_final.plateau[i].P.Nom_piece = "R" && echiquier_final.plateau[i].Couleur = couleur_joueur){
            pos_x_roi = echiquier_final.plateau[i].x;
            pos_y_roi = echiquier_final.plateau[i].y;
        }
    }

}
*/


