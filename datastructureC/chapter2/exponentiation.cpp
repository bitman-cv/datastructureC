/*
    Q4求幂运算；
    利用分治递归的思想，将时间复杂度降为logN；

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

int exponentiation(int X, int N)
{
    if(N == 0){
        return 1;
    }else{
        if(N%2==0){
            return exponentiation(X*X, N/2);
        }else{
            return exponentiation(X*X, (N-1)/2)*X;
        }
    }  
}

int main()
{
    char str[1024];
    
    int nArray[1024];
    puts("enter two num:");
    while(fgets(str, 1024, stdin)){
        int nLength = getArray(str, nArray);
        if(nLength == 2){
            int nRem = exponentiation(nArray[0], nArray[1]);
            printf("num: %d 's %d expontiation is:%d\n",nArray[0], nArray[1], nRem);
        }else{
            puts("error enter!");
        }
        puts("enter two num:");
        continue;
    }
}