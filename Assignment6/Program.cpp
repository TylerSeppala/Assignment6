//Tyler Seppala
//2297817
//seppala@chapman.edu
//CPSC 350-02
//Assignment 6 (Sorting)

//Implementation of Program class, tests each of the sorting algorithms in the Sort class

#include <iostream>
#include "Program.h"
#include <cstdio>
#include <ctime>

using namespace std;

Program::Program(string file)
{
  filename = file;
}

Program::~Program()
{
  delete []arr;
}

void Program::readToArray()//Reads from file to array
{
  string line;
  ifstream read_file (filename);
  getline(read_file,line);
  arrayLength = stoi(line,nullptr,0);//Converts string array length to int
  arr = new int[arrayLength];

  if (read_file.is_open())
  {
    for (int i = 0; getline(read_file,line); i++)
    {
      arr[i] = stoi(line,nullptr,0);
    }
  }
}

void Program::testSorts()//asks user for desired algorithms and runs tests
{
  Sort sort;
  clock_t start;
  double duration;
  int choice;

  cout << "What would you like to test?" << endl;
  cout << "\t\t1 - BubbleSort\n\t\t2 - InsertionSort\n\t\t3 - MergeSort\n\t\t4 - QuickSort\n\t\t5 - All" << endl;
  cin >> choice;

  switch (choice)
  {
    case 1:
      bubbleTest(sort, start, duration);
      break;

    case 2:
      insertionTest(sort, start, duration);
      break;

    case 3:
      mergeTest(sort, start, duration);
      break;

    case 4:
      quickTest(sort, start, duration);
      break;

    case 5:
      bubbleTest(sort, start, duration);
      insertionTest(sort, start, duration);
      mergeTest(sort, start, duration);
      quickTest(sort, start, duration);
      break;

    default:
      cout << "Invalid Input." << endl;
      break;
  }
}

/////Here each algorithm is tested for runtime 
void Program::bubbleTest(Sort sort, clock_t start, double duration)
{
  readToArray();

  start = clock();
  sort.bubbleSort(arr, arrayLength - 1);
  duration = ( clock() - start ) / (double) CLOCKS_PER_SEC;

  cout << endl;
  cout << "BubbleSort Duration: " << duration << " seconds" << endl;
  cout << endl;
}

void Program::insertionTest(Sort sort, clock_t start, double duration)
{
  readToArray();

  start = clock();
  sort.insertionSort(arr, arrayLength - 1);
  duration = ( clock() - start ) / (double) CLOCKS_PER_SEC;

  cout << "InsertionSort Duration: " << duration << " seconds" << endl;
  cout << endl;
}

void Program::mergeTest(Sort sort, clock_t start, double duration)
{
  readToArray();

  start = clock();
  sort.mergeSort(arr, 0, arrayLength - 1);
  duration = ( clock() - start ) / (double) CLOCKS_PER_SEC;

  cout << "MergeSort Duration: " << duration << " seconds" << endl;
  cout << endl;
}

void Program::quickTest(Sort sort, clock_t start, double duration)
{
  readToArray();

  start = clock();
  sort.quickSort(arr, 0, arrayLength - 1);
  duration = ( clock() - start ) / (double) CLOCKS_PER_SEC;

  cout << "QuickSort Duration: " << duration << " seconds" << endl;
  cout << endl;
}

void Program::writeFile()//writes test file of random values
{
  int current;
  ofstream write_file;
  write_file.open (filename, std::ios_base::app);
  write_file << "100000" << endl;

  for (int i = 0; i < 100000; i++)
  {
    current = rand() % 200000 + 1;
    write_file << current << endl;
  }
  write_file.close();
}
