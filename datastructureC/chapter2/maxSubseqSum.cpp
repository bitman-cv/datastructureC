/*
    Q1：寻找子序列和最大的子序列；
    算法1：三层for循环
    算法2：两层for循环
    算法3：分治递归思想：左半部最大子序列，右半部最大子序列，跨中间子序列
    算法4：仅需常量空间且以线性时间运行的算法
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>

int getArray(char *str, int nArray[])
{
    const char * delim = " ,";
    int i=0;
    char *end;
    if(str){
        char *token = strtok(str, " ");
        while(token){
                nArray[i++] = strtol(token, &end, 10);
                token = strtok(NULL, " ");
        }
    }
    return i;
}

int getMaxSubSum(int nArray[], int nLength, int &left, int &right)
{
    int maxSum = 0, thisSum = 0;
    left = right = 0;
    for(int i=0; i<nLength; i++)
    {
        thisSum += nArray[i];
        if( thisSum> maxSum){
            maxSum = thisSum;
            right = i;
        }
        if( thisSum < 0){
            thisSum = 0;
            left = i+1;
        }
    }
    return right-left+1;
}

void myprintf(int nArray[], int left, int right)
{
    for(; left<=right; left++)
    {
        printf("%d ", nArray[left]);
    }
    fputc('\n', stdout);
}

int main()
{
    char str[1024];
    puts("put array:");
    while(fgets(str, 1024, stdin))
    {
        puts("original str:");
        puts(str);
        int nArray[1024];
        int nLength = getArray(str, nArray);
        puts("original str:");
        myprintf(nArray, 0, nLength-1);
        if(nLength){
            int left = 0, right = 0;
            int nReLength = getMaxSubSum(nArray, nLength, left, right);
            printf("after Calculation, substring length:%d, substr:", nReLength);
            myprintf(nArray, left, right);
        }
    }
}