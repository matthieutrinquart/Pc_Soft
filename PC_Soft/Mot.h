//
// Created by matth on 27/09/2022.
//
#include <iostream>
#ifndef PC_SOFT_MOT_H
#define PC_SOFT_MOT_H

using namespace std;
/**
 * @brief La classe Mot permet de stocker tous les liens des fichiers textes où apparait le mot .
 */
class Mot {
private:
     /**
     * \brief mot stocker
     * Représente le mot stocké 
     */
    string mot ;
         /**
     * \brief Nombre de lien
     * Cet attribut représente le nombre de fichiers texte où apparait le mot stocker.
     */
    int nbpath{};
    /**
     * \brief nbpath est un pointeur sur le tableau dynamique de chaines de caractères
     * Cet attribut représente un tableau dynamique de tous les liens vers les fichiers textes où apparait le mot.
     */
    string * path{};

public:
    /**
     * \brief Constructeur vide de la classe Mot.
     */
    Mot();
         /**
     * \brief Constructeur de la classe Mot avec comme paramètre le mot à stocker.
     */
    Mot(string * mot);
         /**
     * \brief Ajout d'un nouveau lien dans le tableau path.
     * \param path Prend en paramètre une adresse d'une chaine de caractères qui symbolise le lien du fichier texte où appparait le mot.
     * Cet fonction ajoute un nouveau lien d'un fichier où apparait le mot de l'attribut "mot".
     * Le tableau path étant dynamique la fonction fait une copie du tableau et réinstancie le tableau avec une case supplémentaire pour ensuite remplir le nouveau tableau avec la copie de l'ancien tableau + le nouveau lien. 
     * Cette méthode est couteuse en temps de calcul car la fonction doit à chaque nouveau lien recopier le tableau. Mais elle est bien optimisée en mémoire car le tableau fait la taille du nombre de liens stockés pour ce mot. 
     */

    void add(string * path);
         /**
     * \brief Getter du tableau de lien des fichiers textes
     * \return un pointeur sur une chaine de caractères.
     */

    string * getPath();
         /**
     * \brief Getter du mot stocker.
     * \return retourne un string contenant le mot stocker.
     */
    string getMot();
             /**
     * \brief Getter du nombre de lien stocker.
     * \return retourne un int contant le nombre de lien stocker.
     */

    int getNbPath();

};


#endif //PC_SOFT_MOT_H
