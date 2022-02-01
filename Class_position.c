#include "position.hpp"
#include <cmath>

//============================================
//            class grille
//============================================


grille::grille(){
    T=new int(9)
    for (int i = 0; i<9 ; i++){
        T[i] = 0;
    }
}




grille::grille(const grille & g){
    T=new int(9)
    for (int i = 0; i<9 ; i++){
            T[i] = g.T[i];
    }
}


ostream& grille::print_grille(ostream& out){
    	for (int j=0; j<3; j++){
            for (int i=0; i<3; i++){
                if (T[i + 3*j]==0){
                    cout<<".";
                }
                if (T[i + 3*j]==1){
                    cout<<"X";
                }
                if (T[i + 3*j]==2){
                    cout<<"0";
                }
            }
            cout<<endl;
        }
        cout<<endl;

}

bool grille::a_gagne(int joueur){
	for (int i = 0; i<3 ; ++i){
		if (T[i]==joueur && T[i+1]==joueur && T[i+2]==joueur){
			return true;
		}
		if (T[i]==joueur && T[i+3]==joueur && T[i+6]==joueur){
			return true;
		}
	}
	if (T[0]==joueur && T[4]==joueur && T[8]==joueur){
		return true;
	}
	if (T[2]==joueur && T[4]==joueur && T[6]==joueur){
		return true;
	}
	return false;
}

bool grille::grille_pleine(){
	for (int i=0; i<9; i++){
		if (T[i]==0){
			return false;
		}
	}
	return true;

}

//==========================================
//            class Position_Morpion
//==========================================

Position_Morpion Position_Morpion&::position_possible()
    {
        Position_morpion** Tableau_soeurs = new Position_morpion*[9];
        Position_morpion* Pfille = Tableau_soeurs[0];
        this->fille = Pfille;
        int k = 0;
        for (int i = 0; i<G.m*G.n; i++)
        {
            if (this->G.T[i] == 0)
            {
                Tableau_soeurs[k]->joueur = this->joueur%2+1
                Tableau_soeurs[k]->G = this->G;
                Tableau_soeurs[k]->G.T[i] = this->joueur;
                k+=1;
                Tableau_soeurs[k-1]->soeur = Tableau_soeur[k];
            }
        }
    return Pfille;
    }


