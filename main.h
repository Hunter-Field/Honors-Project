#ifndef HEADER
#define HEADER
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define NAME_LENGTH 50

typedef struct{
  char name[NAME_LENGTH];
  double distance;
  double price;
} Store;

bool PrintBest(char * filename, Store * stores, int numelem, double gasPrice, double milage);
int CountLines(FILE * fptr);
bool CarRead(char * filename, double * gasPrice, double * milage);
bool StoreRead(char * filename, Store * * stores, int * numelem);

#endif
