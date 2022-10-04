//
// Created by matth on 27/09/2022.
//

#ifndef PC_SOFT_MAP_H
#define PC_SOFT_MAP_H


#include "Mot.h"
/**
 * @brief la classe Map permet d'enregistrer tous les mots qui apparaissent dans les fichiers texte de l'arborescence.
 */

class Map {
private:
     /**
     * \brief mots est un pointeur sur un tableau dynamique de Mot trié.
     */

    Mot * mots;

             /**
     * \brief nbmots est un entier qui représente le nombre de Mot stocké par le tableau dynamique.
     */
    int nbmots;



public:
         /**
     * \brief Constructeur vide de la classe Map.
     */
    Map();
         /**
     * \brief La fonction add permet de rajouter un Mot dans le tableau dynamique
     * \param mot Prend en paramètre le mot à rajouter dans le tableau.
     * La fonction add insert un mot en respectant l'ordre de trier du tableau en utilisant le principe de la dichotomie pour trouver l'emplacement où insérer le mot.
     * Si le mot existe déjà la fonction insère juste le path dans le Mot sinon comme pour la fonction add de la classe Mot la fonction crée une copie du tableau puis réinstancie le tableau avec une case en plus. Ensuite la fonction copie l'ancien tableau dans le nouveau tableau en rajoutant le Mot à rajouter.
     */

    void add(Mot * mot);
         /**
     * \brief La fonction Recherche permet de retrouver un Mot dans le tableau mots en fonction d'une chaine de caractères.
     * \param mot Prend en paramètre une chaine de caractères à rechercher dans le tableau.
     * \return Retourne un pointeur sur un Mot qui correspond à la chaine de caractères passée en paramètre.
     * le tableau mots étant trié je fais une recherche dichotomique pour retrouver le mot dans le tableau.
     */

    Mot * Recherche(string * mot);
         /**
     * \brief Getter du tableau mots.
     * \return Retourne un pointeur sur un tableau de Mot.
     */
    Mot *getMots();
         /**
    * \brief Getter le nombre de Mot stocké.
     * \return Retourne un entier.
     */
    int getNbMots();
             /**
    * \brief comparatorString permet de comparer deux String.
    * \param mot1 première chaine de caractères à comparer.
    * \param mot2 deuxième chaine de caractères à comparer.
     * \return Retourne un entier 0 si mot1 < mot2, 1 si mot1 > mot2 et 2 si mot1 == mot2
     * La fonction compare des string en fonction de la position dans le tableau ASCII de chaque caractère en prenant comme priorité la position du caractère dans le string.(la fonction  va comparer le premier caractère des string s'ils sont les mêmes elle va ensuite comparer le second caractère etc...).
     */
    int comparatorString(string mot1, string mot2);


};


#endif //PC_SOFT_MAP_H
