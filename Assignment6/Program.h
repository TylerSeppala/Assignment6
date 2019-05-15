//Tyler Seppala
//2297817
//seppala@chapman.edu
//CPSC 350-02
//Assignment 6 (Sorting)

//Header to Program class, holds array of numbers and delcares testing functions 

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "Sort.h"

using namespace std;

class Program
{
public:
  Program(string file);
  ~Program();

  void readToArray();
  void testSorts();
  void writeFile();
  void bubbleTest(Sort sort, clock_t start, double duration);
  void insertionTest(Sort sort, clock_t start, double duration);
  void mergeTest(Sort sort, clock_t start, double duration);
  void quickTest(Sort sort, clock_t start, double duration);

  string filename;//file containing list of nums
  int arrayLength;//length of num array
  int *arr;//array that holds contents of file
};
