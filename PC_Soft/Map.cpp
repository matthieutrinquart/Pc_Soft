//
// Created by matth on 27/09/2022.
//

#include "Map.h"

Map::Map() {
    nbmots = 0;

}

void Map::add(Mot *mot ) {
    //si c'est la première insertion insérer a la case 0 du tableau
    if (nbmots == 0) {
        this->mots = new Mot[1];
        mots[nbmots] = *mot;
        ++nbmots;
    } else {
        //recherche de l'endroit ou placer le mot par dichotomie
        int début = 0;
        int fin = getNbMots() - 1;
        bool trouvé = false;
        int mil;
        while (!trouvé && début <= fin) {
            mil = (int) ((début + fin) / 2);
            if (comparatorString(mot->getMot(), this->mots[mil].getMot()) == 2){
                //si le mot à été trouvé on insère le nouveau path et on met trouvé a true pour ne pas insérer comme un nouveau mot
                this->mots[mil].add(mot->getPath());
                trouvé = true;
            }
            if (comparatorString(mot->getMot(), this->mots[mil].getMot()) == 1)
                début = mil + 1;
            else
                fin = mil - 1;
        }
        if (!trouvé) {
            // insère le nouveau mot en faisant un tampon du tableau et en réinstiant le nouveau tableau avec une case en plus
            Mot *tampon = this->mots;
            this->mots = new Mot[this->nbmots + 2];
            bool inserer = false;
            for (int j = 0; j < nbmots; ++j) {
                if (inserer)
                    this->mots[j] = tampon[j - 1];
                else
                    this->mots[j] = tampon[j];
                // on insère le nouveau mot au bonne emplacement
                if (mil == j) {
                    this->mots[j] = *mot;
                    inserer = true;
                    ++nbmots;
                }
            }
            delete[] tampon;
        }

    }

}

Mot * Map::Recherche(string *mot) {
    //recherche par dichotomie
    int début = 0;
    int fin = getNbMots()-1;
    bool trouvé = false;
    int mil;
    while(!trouvé && début <= fin){
         mil = (int)((début + fin)/2);
        if(comparatorString(*mot, this->mots[mil].getMot()) == 2)
            trouvé = true;
        else
            if(comparatorString(*mot, this->mots[mil].getMot()) == 1)
                début = mil+1;
            else
                fin = mil-1;


    }
    if(trouvé)
        return &this->mots[mil];
    else
        return nullptr;

}

Mot *Map::getMots() {
    return this->mots;
}

int Map::getNbMots() {
    return this->nbmots;
}
int Map::comparatorString(string mot1, string mot2) {
    //on cherche a savoir quelle est le plus petit mot entre mot1 et mot2
    int taille;
    if(mot1.length() > mot2.length()){
        taille = mot2.length();
    }else if(mot1.length() < mot2.length()) {
        taille = mot1.length();
    }else{
        taille = mot1.length();
    }

    //on parcour chaque caractère et retourne si l'un d'entre eux est plus grand que l'autre
    for(int i = 0 ; i < taille; ++i){
        if( mot1[i] < mot2[i]){
            return 0;
        }else if( mot1[i] > mot2[i]){
            return 1;
        }
    }

    //si le mot est identique on retourne 2
    if(mot1.length() == mot2.length()){
        return 2;
    }// si l'un des 2 string est plus court alors on considèrera que c'est celui la le plus petit.
     else if(mot1.length() < mot2.length()){
        return 0;
    }else{
        return 1;
    }
}
