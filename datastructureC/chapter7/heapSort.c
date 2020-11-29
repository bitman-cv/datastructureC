#include "sort.h"

#define LeftChild(i) (2*(i) +1)

void PercDown(ElementType A[], int i, int N)
{
    int child;
    ElementType tmp;
    for(tmp=ElementType[i]; i<N; i=child){
        child = LeftChild(i);
        if(child!=N-1 && A[child]<A[child+1]){
            child += 1;
        }
        if(tmp < A[child]){
            A[i] = A[child];
        }else{
            break;
        }
    }
    A[i] = tmp;
}

void HeapSort(ElementType A[], int N)
{
    int i;
    for(i=N/2; i>=0; i--){

    }
    
}