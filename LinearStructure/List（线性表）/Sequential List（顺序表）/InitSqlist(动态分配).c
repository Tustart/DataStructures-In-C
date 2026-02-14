#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int *data;    //动态数组指针
    int length;   //当前长度
    int capacity; //当前容量
}SqList;

int InitList(SqList *L,int initSize)
{
    L->data = (int *)malloc(initSize*sizeof(int));
    if(!L->data)
    {
        return 0; //内存分配失败
    }
    L->length = 0;
    L->capacity = initSize;
    return 1;
}

int main()
{
    SqList L;
    if(InitList(&L,10))
    {
        printf("顺序表初始化成功,容量:%d\n",L.capacity);
    }
    free(L.data); // 记得释放内存

    return 0;
}