//Tyler Seppala
//2297817
//seppala@chapman.edu
//CPSC 350-02
//Assignment 6 (Sorting)

//Header to Sort class, declares sorting algorithms and other necessary side algorithms 

#include <iostream>

using namespace std;

class Sort
{
public:
  void bubbleSort(int arr[], int n);
  void insertionSort(int arr[], int n);
  int partition (int arr[], int low, int high);
  void quickSort(int arr[], int low, int high);
  void merge(int arr[], int l, int m, int r);
  void mergeSort(int arr[], int l, int r);
  void swap(int *a, int *b);
  void printArray(int arr[], int n);
};
