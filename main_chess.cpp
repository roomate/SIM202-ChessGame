
#include "chess.hpp"
#include <cmath>
#include <iostream>
using namespace std;


int main(){

echiquier echiquier_d = echiquier_depart();
//echiquier_d.affichage();

coup_echec Coups_Liste[3];

coup_echec coup1(echiquier_d.plateau[8],1,0,3,1);
coup1.affichage_standard();
coup_echec coup2(echiquier_d.plateau[51],6,3,4,3);
coup_echec coup3(echiquier_d.plateau[13],1,5,3,5);
Coups_Liste[0] = coup1;
Coups_Liste[1] = coup2;
Coups_Liste[2] = coup3;





Position_Echec pos_test;
pos_test.echiquier_ref = echiquier_d;
pos_test.echiquier_ref.affichage();

//Position_Echec pos_test(echiquier_d,Blanc,Coups_Liste);

//pos_test.echiquier_ref.affichage();

//pos_test.mise_a_jour_position();

return(0);



//delete echiquier_d;

}

