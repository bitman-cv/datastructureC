#include "sort.h"

void InsertionSort(ElementType nArrar[], int N)
{
    int i=0, j=0;
    for(i=1; i<N; i++)
    {
        int key = nArrar[i];
        for(j=i-1; j>=0; j--){
            if(nArrar[j] > key){
                nArrar[j+1] = nArrar[j];
            }else{
                break;
            }
        }
        nArrar[++j] = key;
    }
}