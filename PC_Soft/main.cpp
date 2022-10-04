
#include <iostream>
#include "Indexation.h"
#include "Mot.h"

using namespace std;
int main() {
    Indexation index ;
    string path;
    cout << "Donner le dossier a parcourir : "<< endl;
    cin >> path ;
    // path = "C:\\Users\\matth\\OneDrive\\Bureau\\Github\\projet_perso\\TestPCSoft";//C:\Users\matth\OneDrive\Bureau\Github\projet_perso\TestPCSoft
     cout << "chargement..." << endl;
     index.load(&path);

    string motrecherche;
    while(motrecherche != "exit"){
        cout << "Donner le mot a chercher : "<< endl;
        cin >> motrecherche ;
        Mot * t = index.getMap()->Recherche(&motrecherche);
        if(t == nullptr)
            cout << "Le mot n'apparait pas" << endl;
        else {
            cout << "Fichier ou le mot apparait : " << endl;
            for (int i = 0; i < t->getNbPath(); ++i) {
                cout << "   " << t->getPath()[i] << endl;
            }
        }
    }


    return 0;
}
