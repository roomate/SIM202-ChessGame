
#include "chess.hpp"
#include <cmath>
#include <iostream>
using namespace std;


int main(){

echiquier echiquier_d = echiquier_depart();
echiquier_d.affichage();



piece P(Roi,Blanc,1,2);


list<coup_echec> Coups_Liste;
coup_echec coup1(echiquier_d.plateau[8],1,0,3,1);
coup1.affichage_standard();
coup_echec coup2(echiquier_d.plateau[51],6,3,4,3);
coup_echec coup3(echiquier_d.plateau[13],1,5,3,5);


//coup_echec coup4 = coup1;

Coups_Liste.push_back(coup1);
Coups_Liste.push_back(coup2);
Coups_Liste.push_back(coup3);
//Coups_Liste[0].affichage_standard();
//Coups_Liste[1] = coup2;
//Coups_Liste[2] = coup3;

//echiquier_d.affichage();




Position_Echec pos_test(echiquier_d,Blanc,Coups_Liste);
pos_test.mise_a_jour_position();
pos_test.echiquier_ref.affichage();

cout<<pos_test.echiquier_ref.plateau[13]->x<<endl;
cout<<pos_test.echiquier_ref.plateau[29]<<endl;

//pos_test.mise_a_jour_position();

return(0);



//delete echiquier_d;

}


