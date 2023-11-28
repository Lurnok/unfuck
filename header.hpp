#pragma once
#include <string>

class SrcIterator;  // Déclaration préalable de la classe SrcIterator;.

class Cells {
private:
    unsigned char array[30000];
    int pointer;

public:
    // Constructeur par défaut
    Cells();

    // Méthodes de manipulation des cellules
    void incrCell();
    void decrCell();
    void goLeft();
    void goRight();
    void printValue();
    unsigned char value();
    void afficher20(SrcIterator iter);
    void userInput();
    int getPointer();
};

class SrcIterator {
private:
    std::string src;
    char currentInstruction;
    int remaining;

public:
    // Constructeur prenant une chaîne source comme argument
    SrcIterator(std::string src);

    // Méthode pour consommer l'instruction actuelle
    void consume();

    // Méthodes pour accéder et modifier l'instruction actuelle
    void setCurrentInstruction(int index);
    char getCurrentInstruction();

    // Méthodes pour accéder et modifier la source
    std::string getSrc();
    void setSrc(std::string source);

    // Méthodes pour accéder et modifier le nombre d'instructions restantes
    int getRemaining();
    void setRemaining(int val);

    // Méthode pour traiter l'instruction actuelle
    void processInstruction(Cells &cells);

    // Méthode pour gérer une boucle dans le code source
    void handleLoop(Cells &cells, std::string subSrc);

    // Méthode pour obtenir une sous-chaîne de la source
    std::string getSubString();
};
