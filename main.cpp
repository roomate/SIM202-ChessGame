#include <iostream>
#include "class_position.hpp"

using namespace std;

int main()
{
    Position_Morpion Q(1);
    Position_Morpion& P = Q;
    bool victoire_joueur = false; //Il joue les 1
    bool victoire_ordi = false; //Il joue les 2
    int x;
    int minimaxi;
    int maxi;
    int n = 0;
    bool nul = false;
    P.print_position();
    while (victoire_joueur == false && victoire_ordi == false && nul == false)
    {

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
            P.fille = nullptr;  // J'ai eu un problème avec ca
            P.position_possible();

            if (P.fille == nullptr)
            {
                nul = true;
            }
            else
            {
                Position *fille = P.fille->soeur;
                minimaxi = minimax(*P.fille,0,0,9);
                maxi = minimaxi;
                P = dynamic_cast<Position_Morpion&> (*P.fille);
                while (fille != nullptr)
                {
                    minimaxi = minimax(*fille,0,0,9);
                    if (minimaxi<maxi)
                    {
                        P = dynamic_cast<Position_Morpion &> (*fille);
                        maxi = minimaxi;
                    }
                    fille = fille->soeur;
                }
            }
        }
        victoire_ordi = P.gagne();
        ++n;
        P.print_position();
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
