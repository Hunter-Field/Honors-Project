#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char **argv){

  // argv[1]: car file name
  // argv[2]: store file name
  // argv[3]: output file name
  if (argc < 4) {
    return EXIT_FAILURE;
  }
  
  double gasPrice;
  double milage;
  if(CarRead(argv[1], &gasPrice, &milage) == false) {
    return EXIT_FAILURE;
  }

  Store * sto;
  int numelem;
  if(StoreRead(argv[2], &sto, &numelem) == false) {
    return EXIT_FAILURE;
  }

  if(PrintBest(argv[3], sto, numelem, gasPrice, milage) == false){
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
