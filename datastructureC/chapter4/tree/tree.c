

#include "tree.h"
#include "fatal.h"
#include <stdlib.h>
#include <string.h>

struct TreeNode
{
    ElementType Element;
    SearchTree Left;
    SearchTree Right;
}

SearchTree MakeEmpty(SearchTree T)
{
    if(T != NULL){
        MakeEmpty(T -> Left);
        MakeEmpty(T -> Right);
        free(T);
    }
    return NULL;
}

Position Find(ElementType X, SearchTree T)
{
    if(T == NULL){
        return NULL;
    }
    if(X < T -> Elment){
        return Find(X, T->Left);
    }else if(X > T->Element){
        return Find(X, T->Right);
    }else{
        return T;
    }
}

Position FindMin(SearchTree T)
{
    if(T == NULL){
        return NULL;
    }else if(T->Left == NULL){
        return T;
    }else{
        return FindMin(T->Left);
    }
}

Position FindMax(SearchTree T)
{
    if(T != NULL){
        while(T->Right != NULL){
            T = T -> Right;
        }
    }
}

SearchTree Insert(ElementType X, SearchTree T)
{
    if(T == NULL){
        T = malloc(sizeof(struct TreeNode));
        if(T == NULL){
            FatalError("Out of Space!!!");
        }else{
            T -> Element = X;
            T -> Left = T ->Right = NULL;
        }
    }else{
        if(X < T->Element){
            T ->Left = Insert(X, T->Left);
        }else if(X > T -> Element){
            T ->Left = Insert(X, T->Left); 
        }
    }
    return T;
}

/*
    删除分三种情况：
        1、删除叶子节点，直接删除；
        2、如果节点有一个子节点，则该节点的父节点调整指针指向该节点子节点后，该节点被删除；
        3、如果该节点有两个子节点，则找到该节点右子树中数据最小的节点的数据代替该节点的数据，然后递归的删除最小节点；
        4、懒惰删除：当一个节点被删除时，仍留在树中，增加被删除的记号。在有重复关键字或被删除的关键字重新插入时效率高；
*/

SearchTree Delete(ElementType X, SearchTree T)
{
    Position TmpCell;
    if(T == NULL){
        Error("Element not found");
    }else if(X < T->Element){
        T->Left = Delete(X, T->Left);
    }else if(X > T->Element){
        T->Right = Delete(X, T->Right);
    }else if(T->Left && T->Right){
        TmpCell = FindMin(T->Right);
        T->Element = TmpCell->Element;
        T->Right = Delete(T->Element, T->Right);
    }else{
        TmpCell = T;
        if(T->Left == NULL){
            T = T->Right;
        }else if(T->Right == NULL){
            T = T->Left;
        }
        free(TmpCell);
    }
    return T;
}