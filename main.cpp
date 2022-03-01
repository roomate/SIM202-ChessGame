#include <iostream>
#include "classe_position.hpp"

using namespace std;

int main()
{
    Position_Morpion P(2);
    bool victoire_joueur = false; //Il joue les 1
    bool victoire_ordi = false; //Il joue les 2
    int x;
    int minimaxi;
    int minimaxi2;
    int k = 0;
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
            P.G.T[x-1] = 1;
            victoire_joueur = P.gagne();
            P.joueur = P.joueur%2+1;
        }
        else
        {
            P.position_possible();
            Position_Morpion& F = dynamic_cast<Position_Morpion&>(*P.fille);
            if (P.fille == nullptr)
            {
                nul = true;
            }
            minimaxi = minimax(F,0,0,++n);
            while (F.soeur != nullptr)
            {
                minimaxi2 = minimax(*F.soeur,0,0,++n);
                if (minimaxi2 < minimaxi)
                    {
                        minimaxi = minimaxi2;
                        ++k;
                    }
                F = dynamic_cast<Position_Morpion&>(*F.soeur);
            }
            F = dynamic_cast<Position_Morpion&>(*P.fille);
            while (k!=0)
            {
                F = dynamic_cast<Position_Morpion&>(*F.soeur);
                --k;
            }
            P = F;
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
    if (nul == true)
    {
        cout<<"Le match est nul"<<endl;
    }

//    Position_Morpion P(2);
//    P.G[0] = 1;
//    P.G[1] = 1;
//    P.G[2] = 2;
//    P.G[3] = 1;
//    P.G[4] = 2;
//    P.G[5] = 1;
//    P.G[6] = 0;
//    P.G[7] = 1;
//    P.G[8] = 2;
//    P.position_possible();
//    Position_Morpion A = dynamic_cast<Position_Morpion&>(*P.fille);
//    cout<<A.joueur;
