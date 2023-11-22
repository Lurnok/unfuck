#include "header.hpp"
#include <iostream>

Cells::Cells(){
    for(int i = 0; i < 30000; i++){
        array[i] = 0;
    }
    pointer = 0;
}

void Cells::incrCell(){
    if(value() == 255)
        array[pointer] = 0;
    else
        array[pointer]++;
}

void Cells::decrCell(){
    if(value() == 0)
        array[pointer] = 255;
    else
        array[pointer]--;
}

unsigned char Cells::value(){
    return array[pointer];
}

void Cells::afficher20(SrcIterator iter){
    std::cout << getPointer() << ", " << iter.getCurrentInstruction() << " : | ";
    for(int i = 0; i < 20; i++){
        std::cout << (int)array[i] << " | ";
    }
     std::cout << std::endl;
}

void Cells::goLeft(){
    if(pointer == 0)
        pointer = 29999;
    else
        pointer--;
}

void Cells::goRight(){
    if(pointer == 29999)
        pointer = 0;
    else
        pointer++;
}

void Cells::printValue(){
    putchar(value());
}

void Cells::userInput(){
    int x = -1;
    do{
        std::cin >> x;
    } while(x < 0 || x > 255);
    array[pointer] = x;
}

int Cells::getPointer(){
    return pointer;
}
