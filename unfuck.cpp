#include <iostream>
#include <fstream>
#include <string>
#include "header.hpp"

int main(int argc, char *argv[]){
    if(argc < 2){
        std::cerr << "Mauvais usage\nUsage correct : unfuck [chemin]" << std::endl;
        return EXIT_FAILURE;
    }

    std::ifstream sourcefile;
    sourcefile.open(argv[1]);

    if(!sourcefile.is_open()){
        std::cerr << "Fichier introuvable" << std::endl;
        return EXIT_FAILURE;
    }

    std::string temp,src = "";
    while ( sourcefile.good() ){
        sourcefile >> temp;
        src += temp;
    }

    sourcefile.close();

    Cells cells;
    SrcIterator iter(src);

    while(iter.getRemaining() > 0){
        iter.processInstruction(cells);
        iter.consume();
    }

    return EXIT_SUCCESS;
}