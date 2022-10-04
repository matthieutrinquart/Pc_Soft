//
// Created by matth on 27/09/2022.
//


#include "Indexation.h"
Indexation::Indexation() {
     map = new Map();
}


void Indexation::load(string * path) {
    for (const auto & file : directory_iterator(*path)) {

        //cout << file.path() << endl;
        *path = file.path().generic_string();

        if(is_directory(*path))
            load(path);
        else if(path->substr(path->length()-4,path->length()) == ".txt"){
            ifstream fichier(*path);
            if(fichier)
            {
                //L'ouverture s'est bien passée, on peut donc lire

                string ligne; //Une variable pour stocker les lignes lues

                while(getline(fichier, ligne)) //Tant qu'on n'est pas à la fin, on lit
                {

                    size_t pos ;
                    string token;
                    string delimiter = " ";
                    for(unsigned int i=0; i< ligne.size(); ++i)  //On parcourt la chaine
                    {
                        //on elimine les caractères particulier
                        if(ligne[i] == '\'' ||ligne[i] == '\"' ||ligne[i] == '.' ||ligne[i] == ',' ||ligne[i] == '!' ||ligne[i] == '?' ||ligne[i] == ';' )    
                            ligne.replace(i, 1, " ");
                    }
                    while ((pos = ligne.find(delimiter)) != std::string::npos) {
                        token = ligne.substr(0, pos);
                        ligne.erase(0, pos + delimiter.length());
                        if(token != ""){
                            Mot mot(&token);
                            mot.add(path);
                            this->map->add(&mot);
                        }
                    }
                }
            }
            else
            {
                cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
            }
       }else {
           cout << "ni l'un ni l'autre"<< endl;
           cout << *path<< endl;
       }

    }


}

Map *Indexation::getMap() const {
    return map;
}
