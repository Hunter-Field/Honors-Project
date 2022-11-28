#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#ifdef PRINT_BEST
bool PrintBest(char * filename, Store * stores, int numelem, double gasPrice, double milage){
  FILE * fptr;
  fptr = fopen(filename, "w");
  if(fptr == NULL){
    return false;
  }
  
  
  
  double pricePerMile = gasPrice / milage;
  
  int indexOfBest = 0;
  double cheapest = 1000000000;

  printf("PRINT FUNCTION RUNS");

  double tempPrice = 0;
  for(int i = 0; i < numelem; i++){
    tempPrice = stores[i].price + (stores[i].distance * pricePerMile);
    if(tempPrice < cheapest){
        cheapest = tempPrice;
        indexOfBest = i;
    }
  }
  
  fprintf(fptr, "The cheapest option is %s with the cost of $%lf.\n", stores[indexOfBest].name, cheapest);
  
  free(stores);
  fclose(fptr);
  
  return true;
}
#endif
