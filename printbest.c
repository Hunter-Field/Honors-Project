#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#ifdef PRINT_BEST

////takes in a file, array of store objects, the number of stores, a gas price, and a gas milage
bool PrintBest(char * filename, Store * stores, int numelem, double gasPrice, double milage){
  
  ////opens the file for writing
  FILE * fptr;
  fptr = fopen(filename, "w");
  if(fptr == NULL){
    return false;
  }
  

  ////finds the cost per mile driven
  double pricePerMile = gasPrice / milage;
  

  ////loops through the array and finds the cheapest option
  int indexOfBest = 0;
  double cheapest = 1000000000;

  double tempPrice = 0;
  for(int i = 0; i < numelem; i++){
    tempPrice = stores[i].price + (stores[i].distance * pricePerMile);
    if(tempPrice < cheapest){
        cheapest = tempPrice;
        indexOfBest = i;
    }
  }


  ////prints the cheapest option to the opened file
  fprintf(fptr, "The cheapest option is %s with the cost of $%.2lf.\n", stores[indexOfBest].name, cheapest);
  

  free(stores);
  fclose(fptr);
  
  return true;
}

#endif
