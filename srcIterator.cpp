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
    currentInstruction = src[0];
    remaining = src.length();
}

int SrcIterator::getRemaining(){
    return remaining;
}

void SrcIterator::setRemaining(int val){
    remaining = val;
}

void SrcIterator::processInstruction(Cells &cells){
    std::string backup;
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
                handleLoop(cells,getSubString());
                break;
            default:
                break;
        }
}

void SrcIterator::handleLoop(Cells &cells, std::string subSrc){
        std::string backup;
        if(subSrc.length() > 0){
            SrcIterator subIter(subSrc);
            while(cells.value() != 0){
                backup = subSrc;
                subIter.setSrc(backup);
                while(subIter.getRemaining() > 0){
                    subIter.processInstruction(cells);
                    subIter.consume();
                }
            }
            processInstruction(cells);
        }
}

std::string SrcIterator::getSubString(){
    std::string subSrc = "";
    int openBracket = 1;
    int closeBracket = 0;
    do{
        consume();
        if(getCurrentInstruction() == '[')
            openBracket++;
        if(getCurrentInstruction() == ']')
            closeBracket++;
        if(openBracket != closeBracket || getCurrentInstruction() != ']')
            subSrc += getCurrentInstruction();
    }while(openBracket != closeBracket || getCurrentInstruction() != ']');
    consume();
    return subSrc;
}