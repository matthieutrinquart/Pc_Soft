//
// Created by matth on 27/09/2022.
//

#ifndef PC_SOFT_INDEXATION_H
#define PC_SOFT_INDEXATION_H

#include "Map.h"
#include <fstream>
#include <filesystem>
using namespace std;
using std::cout; using std::cin;
using std::endl; using std::string;
using std::filesystem::directory_iterator;
using std::filesystem::is_directory;
     /**
 * @brief Classe Indexation permet d'instancier la classe Map en parcourant l'arborescence d'un dossier et récupère tous les mots des fichiers textes.
 */  
class Indexation {
private:
 /**
     * \brief Pointeur sur la classe Map
     * L'attribut map va permettre de stocker tous les mots de l'arborescence parcourue.
     */


    Map * map;


public:
         /**
     * \brief Constructeur vide de la classe Indexation.
     */

    Indexation();
         /**
     * \brief La fonction load fait un parcours du dossier passé en paramètre et remplit l'attribut map de tous les mots trouvés dans les fichiers textes.
     * \param path Prend en paramètre une chaine de caractères qui représente le lien du dossier à parcourir.
     */
    void load(string * path);
         /**
     * \brief La fonction getMap est un getter qui retourne la Map de la classe.
     * \return Retourne un pointeur sur l'attribut Map de la classe.
     */
    Map *getMap() const;

};


#endif //PC_SOFT_INDEXATION_H
