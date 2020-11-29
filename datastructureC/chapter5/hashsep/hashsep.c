#include "fatal.h"
#include "hashsep.h"

struct ListNode
{
    ElementType Element;
    Position Next;
}

struct HashTbl
{
    int TableSize;
    List *TheLists;
}

HashTable InitializeTable(int TableSize)
{
    HashTable H;
    int i;
    if(TableSize < MinTableSize)
    {
        Error("Table size too small");
        return NULL;
    }

    /*Allocate table，动态分配数组内存*/
    H = malloc(sizeof(struct HashTbl));
    if(H == NULL){
        FatalError("Out of space!!!");
    }
    /*set primer num*/
    H->TableSize = NextPrime(TableSize);

    /*Allocatr array of lists*/
    H->TheLists = malloc(sizeof(List)* H->TableSize);
    if(H->TheLists == NULL){
        FatalError("Out of space!!!")
    }

    /*Allocate list heders*/
    for(i=0; i < H->TableSize; i++){
        H->TheLists[i] = malloc(sizeof(struct ListNode));
        if(H->TheLists[i] == NULL){
            FatalError("Out of space!!!";)
        }else{
            H->TheLists[i]->Next = NULL;
        }
    }

    return H;
}

Position Find(ElementType key, HashTable H)
{
    Position P;
    List L;

    L = H->TheLists[Hash(key, H->TableSize)];
    P = L->Next;
    while(P!=NULL && P->Element!=key){
        P = P->Next;
    }
    return P;
}

void Insert(ElementType key, HashTable H)
{
    Position Pos, NewCell;
    List L;

    Pos = Find(key, H);
    if(Pos == NULL){
        NewCell = malloc(sizeof(struct ListNode));
        if(NewCell == NULL){
            FatalError("Out of space!!!");
        }else{
            L = H->TheLists[Hash(key, H->TableSize)];
            NewCell->Next = L->Next;
            NewCell->Element = key;
            L->Next = NewCell;
        }
    }

}