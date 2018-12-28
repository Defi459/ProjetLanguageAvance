#include "archer.h"

Archer::Archer(int x, int y) : Personnage(3, x, y), energie(100) {}

void Archer::flecheDeFeu(Personnage &cible) {
    this->energie=-15;
    cible.recevoirDegats(30);
}

void Archer::flecheDeGlace(Personnage &cible) {
    this->energie=-15;
    cible.recevoirDegats(20);
    cible.perdre_PM(1);
}

void Archer::rechargerEnergie(){
    if(point_mouvement==2){
       this->point_mouvement=0;
        this->energie=+30;
    }
}


/*** getter setter ***/
void Archer::set_energie(int new_energie){ this->energie=new_energie; }
int Archer::get_energie(){ return this->energie; }


