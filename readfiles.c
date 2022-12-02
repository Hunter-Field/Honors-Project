#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int CountLines(FILE * fptr){
  int numline = 0;
  while(!feof(fptr)){
    int filechar = fgetc(fptr);
    if (filechar == '\n'){
	    numline++;
    }
  }
  return numline;
}


#ifdef TEST_READ
bool CarRead(char * filename, double * gasPrice, double * gasMilage){
  ////opens the file
  FILE * fptr;
  
  ////checks if file opens properly
  fptr = fopen(filename, "r");
  if(fptr == NULL){
    return false;
  }

  int rtv = fseek(fptr, 0, SEEK_SET);
  if (rtv == -1){
    fclose (fptr);
    return false;
  }

  ////scans the file and puts contents into variables
  double price = 0;
  double milage = 0;

  if(fscanf(fptr, "%lf %lf\n", &price, &milage) != 2){
    fclose(fptr);
    return false;
  }
  
  fclose(fptr);
  * gasPrice = price;
  * gasMilage = milage;

  return true;
}

bool StoreRead(char * filename, Store * * stores, int * numelem){
  ////opens the file
  FILE * fptr;

  ////checks if file opened correctly
  fptr = fopen(filename, "r");
  if(fptr == NULL){
    return false;
  }

  int rtv = fseek(fptr, 0, SEEK_SET);
  if (rtv == -1){
    fclose (fptr);
    return false;
  }
	
  ////counts the number of lines in the file
  int numline = CountLines(fptr);
  

  ////creates an array to hold store list
  Store * ptr;
  ptr = malloc(numline * sizeof(Store));
  if(ptr == NULL){
    fclose(fptr);
    return false;
  }

  fptr = fopen(filename, "r");
  if(fptr == NULL){
    return false;
  }

  ////puts file contents into array
  for(int i = 0; i < numline; i++){
    if(fscanf(fptr, "%s %lf %lf\n", ptr[i].name, &ptr[i].price, &ptr[i].distance) != 3){
      fclose(fptr);
      free(ptr);
      return false;
    }
  }

  fclose(fptr);

  * numelem = numline;
  * stores = ptr;
  
  return true;
}
#endif
