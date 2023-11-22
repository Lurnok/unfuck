#include "header.hpp"
#include <iostream>
#include <string>

SrcIterator::SrcIterator(std::string source){
    src = source;
    currentInstruction = src[0];
    remaining = src.length();
}

void SrcIterator::consume(){
    src.erase(0,1);
    currentInstruction = src[0];
    remaining--;
}

char SrcIterator::getCurrentInstruction(){
    return currentInstruction;
}

void SrcIterator::setCurrentInstruction(int index){
    currentInstruction = src[index];
}

std::string SrcIterator::getSrc(){
    return src;
}

void SrcIterator::setSrc(std::string source){
    src = source;
    remaining = src.length();
}

int SrcIterator::getRemaining(){
    return remaining;
}

void SrcIterator::setRemaining(int val){
    remaining = val;
}

void SrcIterator::processInstruction(Cells &cells){
    switch(currentInstruction){
            case '+':
                cells.incrCell();
                break;
            case '-':
                cells.decrCell();
                break;
            case '<':
                cells.goLeft();
                break;
            case '>':
                cells.goRight();
                break;
            case '.':
                cells.printValue();
                break;
            case ',':
                cells.userInput();
                break;
            case '[' :
                handleLoop(cells);
                break;
            default:
                break;
        }
}

void SrcIterator::handleLoop(Cells &cells){
    consume();
    //std::cout << src << std::endl;
    std::string subSrc = "";
        while(getCurrentInstruction() != ']'){
            subSrc += getCurrentInstruction();
            consume();
        }
        //std::cout << subSrc << std::endl;
        if(subSrc.length() > 0){
            SrcIterator subIter(subSrc);
            //std::cout << "a" << std::endl;
            while(cells.value() != 0){
               //std::cout << "b" << std::endl;
                subIter.processInstruction(cells);
                for(int i = 1; i < subIter.getRemaining(); i++){
                    subIter.setCurrentInstruction(i);
                    subIter.processInstruction(cells);
                }
                subIter.setCurrentInstruction(0);
            }
        }
}