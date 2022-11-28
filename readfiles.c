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

  printf("CAR FILE 1\n");
  
  ////checks if file opens properly
  fptr = fopen(filename, "r");
  if(fptr == NULL){
    return false;
  }

  printf("CAR FILE 2\n");

  int rtv = fseek(fptr, 0, SEEK_SET);
  if (rtv == -1){
    fclose (fptr);
    return false;
  }

  printf("CAR FILE 3\n");

  ////scans the file and puts contents into variables
  double price = 0;
  double milage = 0;

  if(fscanf(fptr, "%lf %lf\n", &price, &milage) != 2){
    fclose(fptr);
    return false;
  }

  printf("CAR FILE 4\n");
  
  fclose(fptr);
  * gasPrice = price;
  * gasMilage = milage;

  return true;
}

bool StoreRead(char * filename, Store * * stores, int * numelem){
  ////opens the file
  FILE * fptr;
  
  printf("STORE FILE 1\n");

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

  printf("STORE FILE 2\n");
	
  ////counts the number of lines in the file
  int numline = CountLines(fptr);
  

  ////creates an array to hold store list
  Store * ptr;
  ptr = malloc(numline * sizeof(Store));
  if(ptr == NULL){
    fclose(fptr);
    return false;
  }

  printf("STORE FILE 3\n");
  printf("number of lines: %d\n", numline);

  ////puts file contents into array
  for(int i = 0; i < numline; i++){
    if(fscanf(fptr, "%s", ptr[i].name) > 0){
      fscanf(fptr, "%lf\n%lf\n", &ptr[i].price, &ptr[i].distance);
      fclose(fptr);
      free(ptr);
      return false;
    }
  }

  printf("%s\n", ptr[1].name);
  printf("%lf\n", ptr[1].price);
  printf("%lf\n", ptr[1].distance);
  

  printf("STORE FILE 4\n");

  fclose(fptr);

  * numelem = numline;
  * stores = ptr;
  
  return true;
}
#endif
