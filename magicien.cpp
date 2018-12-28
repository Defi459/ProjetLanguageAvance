#include "magicien.h"

Magicien::Magicien(int x, int y) : Personnage(3, x, y), mana(100) {}

void Magicien::bouleDeFeu(Personnage &cible) {
    this->mana=-15;
    cible.recevoirDegats(30);
}

void Magicien::bouleDeGlace(Personnage &cible) {
    this->mana=-15;
    cible.recevoirDegats(20);
    cible.perdre_PM(1);
}

void Magicien::rechargerMana(){
    if(point_mouvement==3){
       this->point_mouvement=0;
        this->mana=+40;
    }
}

void Magicien::dash(int new_x, int new_y){
    if(x==new_x) {
        if(new_y==new_y+1 || new_y==new_y-1){
            this->y=new_y;
        }
    }
    if(y==new_y){
        if(new_x==new_x+1 || new_x==new_x-1){
            this->x=new_x;
        }
    }
}

/*** getter setter ***/
void Magicien::set_mana(int new_mana){ this->mana=new_mana; }
int Magicien::get_mana(){ return this->mana; }
