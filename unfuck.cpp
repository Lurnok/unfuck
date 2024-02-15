#include <iostream>
#include <fstream>
#include <string>
#include "header.hpp"  // Inclusion du fichier d'en-tête contenant la déclaration de la classe Cells et de SrcIterator.

int main(int argc, char *argv[]) {
    // Vérifie si le nombre d'arguments passés en ligne de commande est inférieur à 2.
    if (argc < 2) {
        std::cerr << "Mauvais usage\nUsage correct : unfuck [chemin]" << std::endl;
        return EXIT_FAILURE;
    }

    // Ouverture du fichier source spécifié en ligne de commande.
    std::ifstream sourcefile;
    sourcefile.open(argv[1]);

    // Vérifie si le fichier source est ouvert avec succès.
    if (!sourcefile.is_open()) {
        std::cerr << "Fichier introuvable" << std::endl;
        return EXIT_FAILURE;
    }

    // Lecture du contenu du fichier source et stockage dans une chaîne de caractères.
    std::string temp, src = "";
    while (sourcefile.good()) {
        sourcefile >> temp;
        src += temp;
    }

    sourcefile.close();  // Fermeture du fichier source.

    Cells cells;  // Création d'un objet de la classe Cells.
    SrcIterator iter(src);  // Création d'un objet de la classe SrcIterator avec la chaîne source comme argument.

    if(iter.checkValidity() == 1){
        std::cerr << "Error : unmatched bracket" << std::endl;
        return EXIT_FAILURE;
    }

    // Boucle de traitement des instructions à partir de la source.
    while (iter.getRemaining() > 0) {
        iter.processInstruction(cells);  // Appel d'une méthode de la classe SrcIterator pour traiter une instruction.
        iter.consume();  // Appel d'une méthode de la classe SrcIterator pour consommer l'instruction traitée.
    }

    return EXIT_SUCCESS;
}
