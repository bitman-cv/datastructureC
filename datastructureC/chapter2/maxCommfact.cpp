/*
    Q3求两个整数的最大公因数；
    欧几里得算法；
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>

int getArray(char * str, int nArray[])
{
    int i = 0;
    const char* delimiter = " ,";
    char *pEnd;
    char *ptoken = strtok(str, delimiter);
    while(ptoken){
        nArray[i++] = strtol(ptoken, &pEnd, 10);
        ptoken = strtok(NULL, delimiter);
    }
    return i;
}

int Gcd(int nNumM, int nNumN)
{
    int m = nNumM>nNumN ? nNumM:nNumN;
    int n = nNumM>nNumN ? nNumN:nNumM;
    int nRem = 0;
    while(n > 0){
        nRem = m % n;
        m = n;
        n = nRem;
    }
    return m;
}

int main()
{
    char str[1024];
    
    int nArray[1024];
    puts("enter two num:");
    while(fgets(str, 1024, stdin)){
        int nLength = getArray(str, nArray);
        if(nLength == 2){
            int nRem = Gcd(nArray[0], nArray[1]);
            printf("the max conmmon factor is:%d\n", nRem);
            
        }else{
            puts("error enter!");
        }
        puts("enter two num:");
        continue;
    }
}