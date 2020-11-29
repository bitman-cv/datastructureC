/*
    Q2:有序序列中查找给定元素；
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>

int getArray(char *str, int nArray[])
{
    const char sdelimiter[] = " ,";
    char *pend;
    int i=0;
    char *ptoken = strtok(str, sdelimiter);
    while(ptoken){
        nArray[i++] = strtol(ptoken, &pend, 10);
        ptoken = strtok(NULL, sdelimiter);
    }
    return i;
}

bool getElement(int nArray[], int nLength, int nElement)
{
    int left = 0;
    int right = nLength-1;
    while(left <= right){
        int nmid = (left+right)/2;
        if(nElement < nArray[nmid]){
            right = nmid - 1;
        }
        if(nElement > nArray[nmid]){
            left = nmid + 1;
        }
        if(nElement == nArray[nmid]){
            return true;
        }
        if(left == right){
            return false;
        }
    }
}

int main()
{
    puts("enter a sorted array:");
    char str[1024];
    int nArray[1024];
    int nElement[10];
    while(fgets(str, 1024, stdin)){
        int nLength = getArray(str, nArray);
        if(nLength){
            while(fgets(str, 1024, stdin)){
                int nEleLength = getArray(str, nElement);
                if(nEleLength == 1){
                    if(getElement(nArray, nLength, nElement[0])){
                        printf("found the element:%d success!\n", nElement[0] );
                        break;
                    }else{
                       printf("found the element:%d failed!\n", nElement[0] ); 
                    }
                    continue;
                }else{
                    puts("error enlement, enter again:");
                    continue;
                }
            }
        }else{
            puts("error integer array, enter again:");
            continue;
        }
    }
}