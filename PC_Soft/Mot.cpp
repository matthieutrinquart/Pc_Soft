//
// Created by matth on 27/09/2022.
//

#include "Mot.h"


Mot::Mot(string * mot) {
    this->mot = *mot;
    this->nbpath = 0;
    this->path = new string[this->nbpath];

}
Mot::Mot() {

}

void Mot::add(string * path) {
    bool existe = true;
    //création d'un tampon pour mémoriser le tableau
    string * tampon = this->path;
    //initialisation du nouveau tableau avec 1 case en plus
    this->path = new string[nbpath + 2];
    //Copie de l'ancien tableau sur le nouveau
    for(int i = 0 ; i < nbpath ; ++i){
        this->path[i] = tampon[i];
        //Si le mot est déjà dans le fichier on ne recopie pas le path pour economiser de la mémoire
        if(tampon[i] == *path)
            existe = false;
    }
    if(existe){
        this->path[nbpath] = *path;
        ++nbpath;
    }
    delete[] tampon;

}

string * Mot::getPath() {
    return this->path;
}

string Mot::getMot() {
    return this->mot;
}
int Mot::getNbPath() {
    return this->nbpath;
}