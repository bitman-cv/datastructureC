#include "sort.h"

void ShellSort(ElementType nArrar[], int N)
{
    int i=0, j=0, k=0;
    int key;
    for(k=N/2; k>0; k=k/2){
        for(i=0; i<N; i+=k){
            key = nArrar[i];
            for(j=i-k; j>=0; j-=k){
                if(nArrar[j] > key){
                    nArrar[j+1] = nArrar[j];
                }else{
                    break;
                }
            }

            nArrar[j+k] = key;
        }
    }
}