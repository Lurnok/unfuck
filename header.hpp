#pragma once
#include <string>

class Cells{
private:
    unsigned char array[30000];
    int pointer;

public:
  Cells();
  void incrCell();
  void decrCell();
  void goLeft();
  void goRight();
  void printValue();
  unsigned char value();
  void afficher20();
  void userInput();
};

class SrcIterator{
private:
  std::string src;
  char currentInstruction;
  int remaining;
public:
  SrcIterator(std::string src);
  void consume();
  void setCurrentInstruction(int index);
  char getCurrentInstruction();
  std::string getSrc();
  void setSrc(std::string source);
  int getRemaining();
  void setRemaining(int val);
  void processInstruction(Cells &cells);
  void handleLoop(Cells &cells);
};