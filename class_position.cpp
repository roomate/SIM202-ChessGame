
#include "class_position.hpp"
#include <cmath>

const int MAX = 1000;
const int MIN = -1000;


//============================================
//            class grille
//============================================


grille::grille(){
    T=new int(9);
    for (int i = 0; i<9 ; i++){
        T[i] = 0;
    }
}




grille::grille(const grille & g){
    T=new int(9);
    for (int i = 0; i<9 ; i++){
            T[i] = g.T[i];
    }
}


void grille::affichage(){
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

Position_Morpion& Position_Morpion::position_possible()
    {
        Position_Morpion** Tableau_soeurs = new Position_Morpion*[9];
        Position_Morpion* Pfille = Tableau_soeurs[0];

        int k = 0;

        if (this->G.grille_pleine()){
            this->fille = NULL;
            cout<<"La grille est pleine"<<endl;
            return *this;
        }

        for (int i = 0; i<9; i++)
        {
            if (this->G.T[i] == 0)
            {
                Tableau_soeurs[k]->joueur = this->joueur%2+1;
                Tableau_soeurs[k]->G = this->G;
                Tableau_soeurs[k]->G.T[i] = this->joueur;
                k+=1;
                Tableau_soeurs[k-1]->soeur = Tableau_soeurs[k];
            }
        }
    this->fille = Pfille;
    return *this;
    }

bool Position_Morpion ::gagne(){
    return(this->G.a_gagne(this->joueur));
}

double Position_Morpion :: valeur_position() {
    if (this->G.a_gagne(this->joueur)){
        return 1000;
    }
    if (this->G.a_gagne(this->joueur%2+1)){
        return -1000;
    }
    else{
        return 0;
    }
}



//==========================================
//            Fonction Minmax
//==========================================

// Returns the optimal value a maximizer can obtain.

// Profondeur en argument
int minimax(Position &P, int alpha, int beta, bool maximizing, int depth )
{
   // position* pP=&P;
    P = P.position_possible();
    Position* pFilles= P.fille;
    int a = alpha ;
    int b = beta;
	// Terminating condition. i.e
	// leaf node is reached
	if (pFilles == NULL)
		return P.valeur_position();

    if (maximizing)
    {
        int best = MIN;

        //First child
    //    pP=P.fille;

        int val = minimax(*pFilles, a, b, false, depth+1);
        best = max(best, val);
        //  Recur for her sisters

        while (pFilles->soeur!=NULL)
        {   Position* pS=pFilles->soeur;

            int val = minimax(*(pS), a, b, false, depth+1);
            best = max(best, val);
            delete pFilles;
            pFilles=pS;
      //      alpha = max(alpha, best);

    /*        // Alpha Beta Pruning
            if (beta <= alpha)
                break;              */
        }

        delete pFilles;
        return best;
    }
    else
    {
        int best = MAX;

        //  first child
       // pP=P.fille;
        int val = minimax(*pFilles, a, b, true, depth+1);
        best = min(best, val);
        //  Recur for her sisters

        while (pFilles->soeur!=NULL)
        {   Position* pS=pFilles->soeur;
            int val = minimax(*(pS), a, b, true, depth+1);
            best = min(best, val);
            delete pFilles;
            pFilles=pS;
    //        beta = min(alpha, best);
      /*      // Alpha Beta Pruning
            if (beta <= alpha)
                break;              */
        }
        delete pFilles;
        return best;
    }
}
