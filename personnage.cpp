#include "personnage.h"

using namespace std;

Personnage::Personnage() : vie(100), pseudo("Player") {}

Personnage::Personnage(int new_point_mouvement, int new_x, int new_y)
: vie(100), pseudo("Player") {
    this->point_mouvement=new_point_mouvement;
    this->x=new_x;
    this->y=new_y;
}

void Personnage::recevoirDegats(int degats) {
    vie -= degats;
}

void Personnage::coupDePoing(Personnage &cible) const {
    cible.recevoirDegats(10);
}

void Personnage::perdre_PM(int new_perte) {
    point_mouvement=-new_perte;
}

/*** getter setter ***/
void Personnage::set_vie(int new_vie){ this->vie=new_vie; }
void Personnage::set_pseudo(QString new_pseudo){ this->pseudo=new_pseudo; }
void Personnage::set_point_mouvement(int new_PM){ this->point_mouvement=new_PM; }
void Personnage::set_x(int new_x){ this->x=new_x; }
void Personnage::set_y(int new_y){ this->y=new_y; }
int Personnage::get_vie(){ return this->vie; }
QString Personnage::get_pseudo(){ return this->pseudo; }
int Personnage::get_PM(){ return this->point_mouvement; }
int Personnage::get_x(){ return this->x; }
int Personnage::get_y(){ return this->y; }












