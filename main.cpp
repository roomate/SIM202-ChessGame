#include <iostream>
#include "classe_position.hpp"

using namespace std;

int main()
{
    Position_Morpion Q(1);
    Position_Morpion& P = Q;
    bool victoire_joueur = false; //Il joue les 1
    bool victoire_ordi = false; //Il joue les 2
    int x;
    int minimaxi;
    int n = 0;
    bool nul = false;
    while (victoire_joueur == false && victoire_ordi == false && nul == false)
    {
        P.G.affichage();
        cout<<" c'est au tour du joueur "<<P.joueur<<" de jouer"<<endl;
        if (P.joueur == 1)
        {
            cout<<"Joue ton coup"<<endl;
            cin>>x;
            while (P.G.T[x-1] != 0)
            {
                cout<<"Refaire le coup, zone deja prise.";
                cin>>x;
            }
            P.G.T[x-1] = 1;
            victoire_joueur = P.gagne();
            P.joueur = 2;
            if (P.pleine()) {nul = true;}
        }
        else
        {
            minimaxi = minimax(P,0,0,n+1);
            if (P.fille == nullptr)
            {
                nul = true;
            }
            else {
                Position *fille = P.fille;
                while (fille != nullptr)
                {
                    if (fille->min_max_results == minimaxi)
                    {
                        P = dynamic_cast<Position_Morpion&>(*fille);
                    }
                    fille = fille->soeur;
                }
            }
        }
        victoire_ordi = P.gagne();
        ++n;
    }
    if (victoire_joueur == true)
    {
        cout<<"Vous avez gagne"<<endl;
    }
    if (victoire_ordi == true)
    {
        cout<<"L'ordinateur a gagne"<<endl;
    }
    if (nul == true && victoire_ordi == false && victoire_joueur == false)
    {
        cout<<"Le match est nul"<<endl;
    }

//    Position_Morpion P(2);
//    P.G[0] = 0;
//    P.G[1] = 0;
//    P.G[2] = 0;
//    P.G[3] = 0;
//    P.G[4] = 0;
//    P.G[5] = 0;
//    P.G[6] = 0;
//    P.G[7] = 0;
//    P.G[8] = 0;
//    P.position_possible();
//    Position_Morpion &A = dynamic_cast<Position_Morpion&>(*P.fille);
//    A.position_possible();
//    A.fille->print_position();


    return 0;
}
