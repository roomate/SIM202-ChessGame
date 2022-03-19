#include "chess.hpp"
#include <cmath>
#include <string>
#include <sstream>
//====================================

const int alpha = 1;
const int beta = 1;

const int MAX = 1000;
const int MIN = -1000;

//====================================

void echiquier::affichage(){

    for (int i = 7; i>=0; i--){
        for (int j=0; j<8; j++){
            if (plateau[i*8+j] != nullptr){
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
    list<coup_echec>::iterator it;
    for (it=P.Liste_coup.begin();it!=P.Liste_coup.end();it++){
        if (it->p_rooc== true){
            if (it->couleur_c == Blanc){
                echiquier_final.plateau[6] = echiquier_final.plateau[4];
                echiquier_final.plateau[6]->x = 0;
                echiquier_final.plateau[6]->y = 6;
                echiquier_final.plateau[4] = nullptr;
                echiquier_final.plateau[5] = echiquier_final.plateau[7];
                echiquier_final.plateau[5]->x = 0;
                echiquier_final.plateau[5]->y = 5;
                echiquier_final.plateau[7] = nullptr;
            }
            if (it->couleur_c == Noir){
                echiquier_final.plateau[61] = echiquier_final.plateau[63];
                echiquier_final.plateau[61]->x = 7;
                echiquier_final.plateau[61]->y = 5;
                echiquier_final.plateau[63] = nullptr;
                echiquier_final.plateau[62] = echiquier_final.plateau[60];
                echiquier_final.plateau[62]->x = 7;
                echiquier_final.plateau[62]->y = 6;
                echiquier_final.plateau[60] = nullptr;
            }

        }
        else if (it->g_rooc == true){
            if (it->couleur_c == Blanc){
                echiquier_final.plateau[2] = echiquier_final.plateau[4];
                echiquier_final.plateau[2]->x = 0;
                echiquier_final.plateau[2]->y = 2;
                echiquier_final.plateau[4] = nullptr;
                echiquier_final.plateau[3] = echiquier_final.plateau[0];
                echiquier_final.plateau[3]->x = 0;
                echiquier_final.plateau[3]->y = 3;
                echiquier_final.plateau[0] = nullptr;
            }
            if (it->couleur_c == Noir){
                echiquier_final.plateau[59] = echiquier_final.plateau[56];
                echiquier_final.plateau[59]->x = 7;
                echiquier_final.plateau[59]->y = 3;
                echiquier_final.plateau[56] = nullptr;
                echiquier_final.plateau[58] = echiquier_final.plateau[60];
                echiquier_final.plateau[58]->x = 7;
                echiquier_final.plateau[58]->y = 2;
                echiquier_final.plateau[60] = nullptr;
            }

        }
        else if (it->prom_f == true){
                piece* promotion = echiquier_final.plateau[it->i1*8+it->j1];
                fou type_prom;
                promotion->P = type_prom;
                promotion->x = it->i2;
                promotion->y = it->j2;
                echiquier_final.plateau[it->i2*8+it->j2] = promotion;
                echiquier_final.plateau[it->i1*8+it->j1] = nullptr;

        }
        else if (it->prom_d == true){
                piece* promotion = echiquier_final.plateau[it->i1*8+it->j1];
                dame type_prom;
                promotion->P = type_prom;
                promotion->x = it->i2;
                promotion->y = it->j2;
                echiquier_final.plateau[it->i2*8+it->j2] = promotion;
                echiquier_final.plateau[it->i1*8+it->j1] = nullptr;

        }
        else if (it->prom_t == true){
                piece* promotion = echiquier_final.plateau[it->i1*8+it->j1];
                tour type_prom;
                promotion->P = type_prom;
                promotion->x = it->i2;
                promotion->y = it->j2;
                echiquier_final.plateau[it->i2*8+it->j2] = promotion;
                echiquier_final.plateau[it->i1*8+it->j1] = nullptr;

        }
        else if (it->prom_c == true){
                piece* promotion = echiquier_final.plateau[it->i1*8+it->j1];
                cavalier type_prom;
                promotion->P = type_prom;
                promotion->x = it->i2;
                promotion->y = it->j2;
                echiquier_final.plateau[it->i2*8+it->j2] = promotion;
                echiquier_final.plateau[it->i1*8+it->j1] = nullptr;

        }
        else {
                piece* temp = echiquier_final.plateau[it->i1*8+it->j1];
                temp->x = it->i2;
                temp->y = it->j2;
                echiquier_final.plateau[it->i2*8+it->j2] = temp;
                //cout<<"&"<<temp<<endl;
                //cout<<"&&"<<echiquier_final.plateau[it->i1*8+it->j1]<<endl;
                echiquier_final.plateau[it->i1*8+it->j1] = nullptr;
        }
    }
    return(echiquier_final);
}


Position_Echec& Position_Echec::mise_a_jour_position(){ //Met à jour l'echiquier de ref, vide la liste de coup, et determine le joueur à qui c'est au tour de jouer
    int N = sizeof(this->Liste_coup);
    this->Dernier_coup = this->Liste_coup.back(); //Recup du dernier coup

    enum PieceColor Dernier_joueur = this->Dernier_coup.couleur_c;
    if (Dernier_joueur == Blanc){
        this->couleur_joueur = Noir;
        cout<<"c'est maintenant au joueur noir de jouer"<<endl;
    }
    if (Dernier_joueur == Noir){
        this->couleur_joueur = Blanc;
        cout<<"c'est maintenant au joueur blanc de jouer"<<endl;
    }

    echiquier_ref = construction_echiquier(*this); //Mise à jour de l'echiquier


    Liste_coup.clear();

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
    piece* P_59= new piece(Roi,Noir,7,3);
    E.plateau[59]= P_59;
    piece* P_60= new piece(Dame,Noir,7,4);
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


echiquier echiquier_test_p_rooc(){
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
    piece* P_59= new piece(Roi,Noir,7,3);
    E.plateau[59]= P_59;
    piece* P_60= new piece(Dame,Noir,7,4);
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

echiquier echiquier_test_g_rooc(){
    echiquier E;
    piece* P_0 = new piece(Tour,Blanc,0,0);
    E.plateau[0]= P_0;

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
    piece* P_59= new piece(Roi,Noir,7,3);
    E.plateau[59]= P_59;
    piece* P_60= new piece(Dame,Noir,7,4);
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



Position_Echec& Position_Echec::coup_humain(){ //Met le coup joué par le joueur humain dans la liste de coup
    string reponse;
    cout<<"C'est au tour du joueur blanc de jouer"<<endl;
    cout<<"Coup special ou normal ?"<<endl;
    cin >> reponse;
    string N("normal");
    string S("special");
    if (reponse == N){
        //Recupération des donnees utilisateur
        cout<<"Position de la piece a jouer ?"<<endl;
        string pos_int;
        cin >> pos_int;
        cout<<"Position finale de la piece ?"<<endl;
        string pos_final;
        cin >> pos_final;

        //Analyse de ces données
        char c1 = pos_int[1];
        char c2 = pos_final[1];
        string str_i_init(1,c1);
        string str_i_final(1,c2);
        pos_int.resize(1);
        pos_final.resize(1);

        int j_init;
        int j_final;
        int i_init;
        int i_final;
        stringstream ss;
            ss << str_i_init;
            ss >> i_init;
        stringstream sss;
            sss << str_i_final;
            sss >> i_final;
        i_init = i_init -1;
        i_final = i_final -1;

        string A("A");
        string B("B");
        string C("C");
        string D("D");
        string E("E");
        string F("F");
        string G("G");
        string H("H");


        if (pos_int==A){ j_init = 0 ;}
        if (pos_int==B){ j_init = 1 ;}
        if (pos_int==C){ j_init = 2 ;}
        if (pos_int==D){ j_init = 3 ;}
        if (pos_int==E){ j_init = 4 ;}
        if (pos_int==F){ j_init = 5 ;}
        if (pos_int==G){ j_init = 6 ;}
        if (pos_int==H){ j_init = 7 ;}

        if (pos_final==A){ j_final = 0 ;}
        if (pos_final==B){ j_final = 1 ;}
        if (pos_final==C){ j_final = 2 ;}
        if (pos_final==D){ j_final = 3 ;}
        if (pos_final==E){ j_final = 4 ;}
        if (pos_final==F){ j_final = 5 ;}
        if (pos_final==G){ j_final = 6 ;}
        if (pos_final==H){ j_final = 7 ;}

        //Mise à jour de la liste de coup de la position

        if (this->echiquier_ref.plateau[i_final*8+j_final] != nullptr){
            cout<<"Vous mangez une piece"<<endl;
            coup_echec coup_joue(this->echiquier_ref.plateau[i_init*8+j_init],this->echiquier_ref.plateau[i_final*8+j_final],i_init,j_init,i_final,j_final);
            this->Liste_coup.push_back(coup_joue);
        }else if (this->echiquier_ref.plateau[i_final*8+j_final] == nullptr){
            coup_echec coup_joue(this->echiquier_ref.plateau[i_init*8+j_init],i_init,j_init,i_final,j_final);
            this->Liste_coup.push_back(coup_joue);
        }
    }
    if (reponse == S){
        cout<<"lequel ? : g_rooc , p_rooc , prom_t , prom_d , prom_c , prom_f ?"<<endl;
        string reponse2;
        cin >> reponse2;

        string p_rooc("p_rooc");
        string g_rooc("g_rooc");
        string prom_t("prom_t");
        string prom_d("prom_d");
        string prom_c("prom_c");
        string prom_f("prom_f");

        if(reponse2 == p_rooc ){
            cout<<"Vous effectuez un petit rooc"<<endl;
            coup_echec coup_joue("p_rooc",this->couleur_joueur);
            this->Liste_coup.push_back(coup_joue);
        }
        if(reponse2 == g_rooc ){
            cout<<"Vous effectuez un grand rooc"<<endl;
            coup_echec coup_joue("g_rooc",this->couleur_joueur);
            this->Liste_coup.push_back(coup_joue);
        }else if (reponse2 == prom_c || reponse2==prom_f || reponse2==prom_t || reponse2==prom_d){
            //Recupération des donnees utilisateur
            cout<<"Position de la piece a jouer ?"<<endl;
            string pos_int;
            cin >> pos_int;
            cout<<"Position finale de la piece ?"<<endl;
            string pos_final;
            cin >> pos_final;

            //Analyse de ces données
            char c1 = pos_int[1];
            char c2 = pos_final[1];
            string str_i_init(1,c1);
            string str_i_final(1,c2);
            pos_int.resize(1);
            pos_final.resize(1);

            int j_init;
            int j_final;
            int i_init;
            int i_final;
            stringstream ss;
            ss << str_i_init;
            ss >> i_init;
            stringstream sss;
            sss << str_i_final;
            sss >> i_final;
            i_init = i_init -1;
            i_final = i_final -1;

            string A("A");
            string B("B");
            string C("C");
            string D("D");
            string E("E");
            string F("F");
            string G("G");
            string H("H");


            if (pos_int==A){ j_init = 0 ;}
            if (pos_int==B){ j_init = 1 ;}
            if (pos_int==C){ j_init = 2 ;}
            if (pos_int==D){ j_init = 3 ;}
            if (pos_int==E){ j_init = 4 ;}
            if (pos_int==F){ j_init = 5 ;}
            if (pos_int==G){ j_init = 6 ;}
            if (pos_int==H){ j_init = 7 ;}

            if (pos_final==A){ j_final = 0 ;}
            if (pos_final==B){ j_final = 1 ;}
            if (pos_final==C){ j_final = 2 ;}
            if (pos_final==D){ j_final = 3 ;}
            if (pos_final==E){ j_final = 4 ;}
            if (pos_final==F){ j_final = 5 ;}
            if (pos_final==G){ j_final = 6 ;}
            if (pos_final==H){ j_final = 7 ;}

            if(reponse2 == prom_c){
                if (this->echiquier_ref.plateau[i_final*8+j_final] != nullptr){
                    cout<<"Vous mangez une piece"<<endl;
                    cout<<"Vous obtenez un cavalier"<<endl;
                    coup_echec coup_joue("prom_c",this->echiquier_ref.plateau[i_init*8+j_init],this->echiquier_ref.plateau[i_final*8+j_final],i_init,j_init,i_final,j_final);
                    this->Liste_coup.push_back(coup_joue);
                }else if (this->echiquier_ref.plateau[i_final*8+j_final] == nullptr){
                    cout<<"Vous obtenez un cavalier"<<endl;
                    coup_echec coup_joue("prom_c",this->echiquier_ref.plateau[i_init*8+j_init],i_init,j_init,i_final,j_final);
                    this->Liste_coup.push_back(coup_joue);
                }

            }
            if(reponse2 == prom_f){
                if (this->echiquier_ref.plateau[i_final*8+j_final] != nullptr){
                    cout<<"Vous mangez une piece"<<endl;
                    cout<<"Vous obtenez un fou"<<endl;
                    coup_echec coup_joue("prom_f",this->echiquier_ref.plateau[i_init*8+j_init],this->echiquier_ref.plateau[i_final*8+j_final],i_init,j_init,i_final,j_final);
                    this->Liste_coup.push_back(coup_joue);
                }else if (this->echiquier_ref.plateau[i_final*8+j_final] == nullptr){
                    cout<<"Vous obtenez un fou"<<endl;
                    coup_echec coup_joue("prom_f",this->echiquier_ref.plateau[i_init*8+j_init],i_init,j_init,i_final,j_final);
                    this->Liste_coup.push_back(coup_joue);
                }

            }
            if(reponse2 == prom_d){
                if (this->echiquier_ref.plateau[i_final*8+j_final] != nullptr){
                    cout<<"Vous mangez une piece"<<endl;
                    cout<<"Vous obtenez une dame"<<endl;
                    coup_echec coup_joue("prom_d",this->echiquier_ref.plateau[i_init*8+j_init],this->echiquier_ref.plateau[i_final*8+j_final],i_init,j_init,i_final,j_final);
                    this->Liste_coup.push_back(coup_joue);
                }else if (this->echiquier_ref.plateau[i_final*8+j_final] == nullptr){
                    cout<<"Vous obtenez une dame"<<endl;
                    coup_echec coup_joue("prom_d",this->echiquier_ref.plateau[i_init*8+j_init],i_init,j_init,i_final,j_final);
                    this->Liste_coup.push_back(coup_joue);
                }

            }
            if(reponse2 == prom_t){
                if (this->echiquier_ref.plateau[i_final*8+j_final] != nullptr){
                    cout<<"Vous mangez une piece"<<endl;
                    cout<<"Vous obtenez une tour"<<endl;
                    coup_echec coup_joue("prom_t",this->echiquier_ref.plateau[i_init*8+j_init],this->echiquier_ref.plateau[i_final*8+j_final],i_init,j_init,i_final,j_final);
                    this->Liste_coup.push_back(coup_joue);
                }else if (this->echiquier_ref.plateau[i_final*8+j_final] == nullptr){
                    cout<<"Vous obtenez une tour"<<endl;
                    coup_echec coup_joue("prom_t",this->echiquier_ref.plateau[i_init*8+j_init],i_init,j_init,i_final,j_final);
                    this->Liste_coup.push_back(coup_joue);
                }

            }


        }

    }




    return(*this);
}



