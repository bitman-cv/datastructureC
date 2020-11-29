#include "../fatal.h"
#include "sort.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LeftChild(i) (2*(i)+1)

// extern int getInputs(int nNumArray[]);
// extern void myPrintf(int nNumArray[], int n);
// extern void InsertionSort(ElementType[], int N);
// extern void myAarrayCpy(int nSrc[], int nDest[], int n);

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

void Swap(int *n1, int *n2)
{
    int tmp = *n1;
    *n1 = *n2;
    *n2 = tmp;  
}

void PercDown(ElementType A[], int i, int N)
{
    int child;
    ElementType tmp;
    for(tmp=A[i]; i<N; i=child){
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
        PercDown(A, N/2, N);
    }

    for(int j = N-1; j>=0; j--){
        Swap(&A[0], &A[j]);
        PercDown(A, 0, j);
    }  
}

void Merge(ElementType A[], ElementType TmpArray[], int Lpos, int Rpos, int RightEnd)
{
    int i , LeftEnd, NumElements, TmpPos;
    LeftEnd = Rpos - 1;
    TmpPos = Lpos;
    NumElements = RightEnd - Lpos + 1;

    /*main loop*/
    while(Lpos <= LeftEnd && Rpos <= RightEnd){
        if(A[Lpos] <= A[Rpos]){
            TmpArray[TmpPos++] = A[Lpos++];
        }else{
            TmpArray[TmpPos++] = A[Rpos++];
        }
    }
    while(Lpos <= LeftEnd){
        /*Copy rest of first half*/
        TmpArray[TmpPos++] = A[Lpos++];
    }
    while(Rpos <= RightEnd){
        /*Copy rest of second half*/
        TmpArray[TmpPos++] = A[Rpos++];
    }
    /*Copy TmpArray back*/
    for(i=0; i<NumElements; i++, RightEnd--){
        A[RightEnd] = TmpArray[RightEnd];
    }
}

void MSort(ElementType A[], ElementType TmpArray[], int Left, int Right)
{
    int Center;

    if(Left < Right){
        Center = (Left + Right)/2;
        MSort(A, TmpArray, Left, Center);
        MSort(A, TmpArray, Center + 1, Right);
        Merge(A, TmpArray, Left, Center+1, Right);
    }
}

void MergeSort(ElementType nArray[], int N)
{
    ElementType *TmpArray;
    TmpArray = (int *)malloc(N* sizeof(ElementType));
    if(TmpArray !=NULL){
        MSort(nArray, TmpArray, 0, N-1);
        free(TmpArray);
    }else{
        FatalError("No space for tmp array!!!");
    }
}

int main()
{
    int nNumArray[1024];
    int nToSort[1024];
    int n = getInputs(nNumArray);
    while(n){
        printf("there are %d integers to sort, befor sort:");
        myPrintf(nNumArray, n);
        // // 插入排序
        // myAarrayCpy(nNumArray, nToSort, n); 
        // InsertionSort(nToSort, n);
        // printf("after insertion sort:");
        // myPrintf(nToSort, n);
        // //希尔排序
        // myAarrayCpy(nNumArray, nToSort, n); 
        // ShellSort(nToSort, n);
        // printf("after insertion sort:");
        // myPrintf(nToSort, n);
        //堆排序
        myAarrayCpy(nNumArray, nToSort, n); 
        HeapSort(nToSort, n);
        printf("after insertion sort:");
        myPrintf(nToSort, n);

        n = getInputs(nNumArray);
    }

    return 0;
}