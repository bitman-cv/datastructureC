#include "cursor.h"

struct Node
{
    ElementType Element;
    Position Next;
};

struct Node CursorSpace[SpaceSize];

static Position CursorAlloc(void)
{
    Position P;
    P = CursorSpace[0].Next;
    CursorSpace[0].Next = CursorSpace[P].Next;
    return P;
}

static void CursorFree(Position P)
{
    CursorSpace[P].Next = CursorSpace[0].Next;
    CursorSpace[0].Next = P;
}

int IsEmpty(List L)
{
    return CursorSpace[L].Next == 0;
}

Position Find(ElementType X, List L)
{
    Position P;
    P = CursorSpace[L].Next;
    while(P && CursorSpace[P].Element != X)
        P = CursorSpace[P].Next;
    return P;
}

void Delete(ElementType X, List L)
{
    Position P, TmpCell;
    P = FindPrevious(X, L);
    if( !IsLast(P, L))
    {
        TmpCell = CursorSpace[P].Next;
        CursorSpace[P].Next = CursorSpace[TmpCell].Next;
        CursorFree(TmpCell); 
    }
}

void Insert(ElementType X, List L, Position P)
{
    Position TmpCell;
    TmpCell = CursorAlloc();
    if(TmpCell == 0)
        FatalError("Out of space!!!");

    CursorSpace[TmpCell].Element = X;
    CursorSpace[TmpCell].Next = CursorSpace[P].Next;
    CursorSpace[P].Next = TmpCell;
}