#include "header.hpp"
#include <iostream>

// Constructeur de la classe Cells
Cells::Cells() {
    // Initialise le tableau avec des zéros et le pointeur à zéro.
    for (int i = 0; i < 30000; i++) {
        array[i] = 0;
    }
    pointer = 0;
}

// Méthode pour incrémenter la valeur de la cellule actuelle
void Cells::incrCell() {
    if (value() == 255)
        array[pointer] = 0;
    else
        array[pointer]++;
}

// Méthode pour décrémenter la valeur de la cellule actuelle
void Cells::decrCell() {
    if (value() == 0)
        array[pointer] = 255;
    else
        array[pointer]--;
}

// Méthode pour obtenir la valeur de la cellule actuelle
unsigned char Cells::value() {
    return array[pointer];
}

// Méthode pour afficher les 20 premières valeurs du tableau et des informations supplémentaires
void Cells::afficher20(SrcIterator iter) {
    std::cout << getPointer() << ", " << iter.getCurrentInstruction() << " : | ";
    for (int i = 0; i < 20; i++) {
        std::cout << (int)array[i] << " | ";
    }
    std::cout << std::endl;
}

// Méthode pour déplacer le pointeur vers la gauche
void Cells::goLeft() {
    if (pointer == 0)
        pointer = 29999;
    else
        pointer--;
}

// Méthode pour déplacer le pointeur vers la droite
void Cells::goRight() {
    if (pointer == 29999)
        pointer = 0;
    else
        pointer++;
}

// Méthode pour afficher la valeur de la cellule actuelle
void Cells::printValue() {
    putchar(value());
}

// Méthode pour obtenir une entrée utilisateur et la stocker dans la cellule actuelle
void Cells::userInput() {
    int x = -1;
    do {
        std::cin >> x;
    } while (x < 0 || x > 255);
    array[pointer] = x;
}

// Méthode pour obtenir la position actuelle du pointeur
int Cells::getPointer() {
    return pointer;
}
