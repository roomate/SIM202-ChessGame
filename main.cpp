#include <iostream>
#include "classe_position.hpp"

using namespace std;

int main()
{
    Position_Morpion Q(2);
    Position_Morpion& P = Q;
    bool victoire_joueur = false; //Il joue les 1
    bool victoire_ordi = false; //Il joue les 2
    int x;
    int minimaxi;
    int maxi;
    int n = 0;
    bool nul = false;
    while (victoire_joueur == false && victoire_ordi == false && nul == false)
    {
        P.print_position();
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
            cout<<P.fille<<endl;
            Position* filles = P.fille;
            while (filles!= nullptr)
            {
                cout<<" ====== "<<endl;
                filles->print_position();
                filles = filles->soeur;
                cout<<" ====== "<<endl;
            }
            P.fille->print_position();

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
                    fille->print_position();
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
        cout<<" ===== L'ordinateur a t'il gagne ? ====="<<endl;
        cout<<victoire_ordi<<"\n";
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

//    Position_Morpion P(2);
//    P.G[0] = 1;
//    P.G[1] = 0;
//    P.G[2] = 0;
//    P.G[3] = 0;
//    P.G[4] = 1;
//    P.G[5] = 0;
//    P.G[6] = 0;
//    P.G[7] = 2;
//    P.G[8] = 0;
//    P.position_possible();
//    Position* fille = P.fille;
//    while (fille!= nullptr)
//    {
//        fille->print_position();
//        fille = fille->soeur;
//    }


    return 0;
}
