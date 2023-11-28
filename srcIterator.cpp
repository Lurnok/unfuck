#include "header.hpp"
#include <iostream>
#include <string>

// Constructeur de la classe SrcIterator
SrcIterator::SrcIterator(std::string source) {
    src = source;
    currentInstruction = src[0];
    remaining = src.length();
}

// Méthode pour consommer l'instruction actuelle
void SrcIterator::consume() {
    src.erase(0, 1);
    currentInstruction = src[0];
    remaining--;
}

// Méthode pour obtenir l'instruction actuelle
char SrcIterator::getCurrentInstruction() {
    return currentInstruction;
}

// Méthode pour définir l'instruction actuelle à une position donnée dans la source
void SrcIterator::setCurrentInstruction(int index) {
    currentInstruction = src[index];
}

// Méthode pour obtenir la source
std::string SrcIterator::getSrc() {
    return src;
}

// Méthode pour définir la source
void SrcIterator::setSrc(std::string source) {
    src = source;
    currentInstruction = src[0];
    remaining = src.length();
}

// Méthode pour obtenir le nombre d'instructions restantes
int SrcIterator::getRemaining() {
    return remaining;
}

// Méthode pour définir le nombre d'instructions restantes
void SrcIterator::setRemaining(int val) {
    remaining = val;
}

// Méthode pour traiter l'instruction actuelle
void SrcIterator::processInstruction(Cells &cells) {
    std::string backup;
    
    // Utilise une instruction switch pour déterminer l'opération à effectuer en fonction de l'instruction actuelle
    switch (currentInstruction) {
    case '+':
        cells.incrCell();  // Incrémente la valeur de la cellule actuelle
        break;
    case '-':
        cells.decrCell();  // Décrémente la valeur de la cellule actuelle
        break;
    case '<':
        cells.goLeft();  // Déplace le pointeur vers la gauche
        break;
    case '>':
        cells.goRight();  // Déplace le pointeur vers la droite
        break;
    case '.':
        cells.printValue();  // Affiche la valeur de la cellule actuelle
        break;
    case ',':
        cells.userInput();  // Obtient une entrée utilisateur et la stocke dans la cellule actuelle
        break;
    case '[':
        handleLoop(cells, getSubString());  // Gère une boucle "[" en utilisant la méthode handleLoop
        break;
    default:
        break;
    }
}


// Méthode pour gérer une boucle dans le code source
void SrcIterator::handleLoop(Cells &cells, std::string subSrc) {
    std::string backup;
    if (subSrc.length() > 0) {
        // Crée un nouvel itérateur pour la sous-chaîne du code source à l'intérieur de la boucle
        SrcIterator subIter(subSrc);
        
        // Tant que la valeur de la cellule actuelle est différente de zéro
        while (cells.value() != 0) {
            // Sauvegarde la sous-chaîne du code source avant le début de la boucle
            backup = subSrc;
            subIter.setSrc(backup);
            
            // Itère sur la sous-chaîne et exécute les instructions jusqu'à ce que la cellule actuelle devienne zéro
            while (subIter.getRemaining() > 0) {
                subIter.processInstruction(cells);
                subIter.consume();
            }
        }
        
        // Après la fin de la boucle, traite l'instruction suivante dans la source principale
        processInstruction(cells);
    }
}


// Méthode pour obtenir une sous-chaîne de la source
std::string SrcIterator::getSubString() {
    std::string subSrc = "";
    int openBracket = 1;
    int closeBracket = 0;
    
    // Tant que le nombre de crochets ouvrants n'est pas égal au nombre de crochets fermants
    // ou que l'instruction actuelle n'est pas un crochet fermant
    do {
        consume();  // Consomme l'instruction actuelle
        if (getCurrentInstruction() == '[')
            openBracket++;
        if (getCurrentInstruction() == ']')
            closeBracket++;
        if (openBracket != closeBracket || getCurrentInstruction() != ']')
            subSrc += getCurrentInstruction();  // Ajoute l'instruction à la sous-chaîne
    } while (openBracket != closeBracket || getCurrentInstruction() != ']');
    
    consume();  // Consomme le crochet fermant
    return subSrc;
}
