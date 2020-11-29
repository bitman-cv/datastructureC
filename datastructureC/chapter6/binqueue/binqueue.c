
#include "fatal.h"

typedef struct BinNode *Position;
typedef struct Collection *BinQueue

struct BinNode
{
    ElementType Element;
    Position LeftChild;
    Position NextSibling;
}

struct Collection
{
    int CurrentSize;
    BinTree TheTrees[MaxTrees];
}

/*Return the result of merging equal-sized T1 and T2*/
BinTree CombineTrees(BinTree T1, BinTree T2)
{
    if(T1->Element > T2->Element){
        return CombineTrees(T2, T1);
    }
    T2->NextSibling = T1->LeftChild;
    T1->LeftChild = T2;
    return T1;
}

/*Merge two binomial queues*/
/*Not optimized for early termination*/
/*H1 contains merged result*/

BinQueue Merge(BinQueue H1, BinQueue H2)
{
    BinTree T1, T2, Carry = NULL;
    int i, j;

    if(H1->CurrentSize + H2->CurrentSize > Capacity){
        Error("Merge would exceed capacity");
    }

    H1->CurrentSize += H2->CurrentSize;
    for(i=0; j=1; j<=H1->CurrentSize; i++, j *=2)
    {
        T1 = H1->TheTrees[i]; 
        T2 = H2->TheTrees[i];
        switch(!!T1+ 2*!!T2 + 4*!!Carry ){
            case 0:  /*No trees*/
            case 1:  /*Only H1*/
                break;
            case 2:  /*Only H2*/
                H1->TheTrees[i] = T2;
                H2->TheTrees[i] = NULL;
                break;
            case 4:  /*Only Carry*/
                H1->TheTrees[i] = Carry; 
                Carry = NULL;
                break;
            case 3:  /*H1 and H2*/
                Carry = CombineTrees(T1, T2);
                H1->TheTrees[i] = H2->TheTrees[i] = NULL; 
                break;
            case 5:  /*H1 and Carry*/
                Carry = CombineTrees(T1, Carry);
                H1->TheTrees[i] = NULL;
                break;
            case 6:  /*H2 and Carry*/
                Carry = CombinesTrees(T2, Carry);
                H2->TheTrees[i] = NULL;
                break;
            case 7:  /*All three*/
                H1->TheTrees[i] = Carry;
                Carry = CombinesTree(T1, T2);
                H2->TheTrees[i] = NULL;
                break;
        }
    }
}

ElementType DeleteMin(BinQueue H)
{
    int i, j;
    int MinTree;  /*the tree with the minimun item*/
    BinQueue DeletedQueue;
    Position DeletedTree, OldRoot;
    ElementType MinItem;

    if(IsEmpty(H)){
        Error("Empty binomial queue");
        return -Infinity;
    }

    MinItem = Infinity;
    for(i=0; i<MaxTrees; i++){
        if(H->TheTrees[i] && H->TheTrees[i]->Element < MinItem){
            /*Update minimum*/
            MinItem = H->TheTrees[i]->Element;
            MinTree = i;
        }
    }
    
    DeletedTree = H->TheTrees[MinTree];
    OldRoot = DeletedTree;
    DeletedTree = DeletedTree->LeftChild;
    free(OldRoot);

    DeleteQueue = Initialize();
    DeleteQueue->CurrentSize = (1 << MinTree) - 1;
    for(j = MinTree-1; j>=0; j--){
        DeletedQueue->TheTrees[j] = DeletedTree;
        DeleteTree = DeletedTree->NextSibling;
        DeleteQueue->TheTrees[j]->NextSibling = NULL;
    }

    H->TheTrees[MinTree] = NULL;
    H->CurrentSize = DeletedQueue->CurrentSize + 1;
    Merge(H, DeleteQueue);
    return MinItem;
}