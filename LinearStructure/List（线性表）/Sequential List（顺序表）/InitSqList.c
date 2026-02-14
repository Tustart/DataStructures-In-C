#include <stdio.h>
#define MAXSIZE 100

typedef struct{
    int data[MAXSIZE];
    int length;
}Sqlist;

void InitList(Sqlist *L){
    L->length = 0;  //初始化表长为0
    //可选：将所有元素初始化为0
    for(int i =0;i<MAXSIZE;i++)
    {
        L->data[i] = 0;
    }
}
int main()
{
    Sqlist L;
    InitList(&L);
    printf("顺序表长度:%d\n",L.length);
    return 0;
}