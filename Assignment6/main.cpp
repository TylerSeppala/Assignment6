//Tyler Seppala
//2297817
//seppala@chapman.edu
//CPSC 350-02
//Assignment 6 (Sorting)

//Main class which collects input file, initializes the program, and tests the sorting algorithms.

#include <iostream>
#include "Program.h"

using namespace std;

int main (int argc, char **argv)
{
  string file = argv[1];//takes filename from console command 
  Program program(file);
  program.testSorts();
  //program.writeFile();//uncomment to write a new test file

  return 0;
}
