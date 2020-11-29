#include "sort.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int getInputs(int *nNumArray)
{
    char str[1024];
    char * delimiter = " "; 
    char *end=NULL;
    int i=0;
    printf("Enter a set of integers,separated by spaces:\n");
    fgets(str, 1024, stdin);
    char *token = strtok(str, delimiter);
    while(token){
        nNumArray[i++] = strtol(token,&end, 10);
        token = strtok(NULL, delimiter);
    }
    return i;
}

void myPrintf(int nNumArray[], int n)
{
    int i=0;
    while(i<n){
        printf("%d ", nNumArray[i++]);
    }
    printf("\n");
}

void myAarrayCpy(int nSrc[], int nDest[], int n)
{
    for(int i=0; i<n; i++){
        nDest[i] = nSrc[i];
    }
}