#include <stdio.h>
#include <stdlib.h>

#define ERROR 0
#define OK    1

typedef int Status;    //函数状态类型
typedef int ElemType;  //元素类型

typedef struct{
    ElemType *data;
    int length;
    int capacity;
}SqList;

//初始化线性表用于测试
Status InitList(SqList *L,int initSize)
{
    L->data = (ElemType *)malloc(initSize*sizeof(ElemType));
    if(!L->data) return ERROR;
    L->length = 0;
    L->capacity = initSize;
    return OK;
}

//插入元素（在表尾插入，用于测试）
Status ListInsert(SqList *L,ElemType e)
{
    if(L->length >= L->capacity) return ERROR;   //表满了，表长大于实际容量
    L->data[L->length++] = e;
    return OK;
}

//按位置取值: 获取第i个元素（1<=i<=length）
Status GetElem(SqList L,int i,ElemType *e)
{
    if(i<1||i>L.length) return ERROR;
    *e = L.data[i-1];
    return OK;
}

//按值查找:返回第一个值为e的元素的位置
int LocateElem(SqList L,ElemType e)
{
    for(int i = 0;i<L.length;i++)
    {
        if(L.data[i]== e)
        {
            return i+1;
        }
    }
    return 0;   //未找到返回0
}

//销毁顺序表(释放内存)
void DestroyList(SqList *L)
{
    if(L->data)
    {
        free(L->data);
        L->data = NULL;
    }
    L->length = 0;
    L->capacity = 0;
}

int main()
{
    SqList L;
    //初始化容量为10的顺序表
    if(!InitList(&L,10))
    {
        printf("初始化失败\n");
        return 1;
    }

    //插入一些测试数据
    for(int i = 1;i<=5;i++)
    {
        ListInsert(&L,i*10);
    }
    printf("顺序表现有元素:  ");
    for(int i = 0;i<L.length;i++)
    {
        printf("%d ",L.data[i]);
    }
    printf("\n");

    //1.按位置取值测试
    ElemType val;
    int pos = 3;
    if(GetElem(L,pos,&val))
    {
        printf("第%d个元素的值为:%d\n",pos,val);
    }
    else{
        printf("位置%d不合法!\n",pos);
    }

    //2.按值查找测试
    ElemType searchVal = 40;
    int resultPos = LocateElem(L,searchVal);
    if(resultPos!=0)
    {
        printf("值为%d的元素位于第%d个位置\n",searchVal,resultPos);
    }
    else{
        printf("未找到值为%d的元素\n",searchVal);
    }

    //边界测试:非法位置
    if(!GetElem(L,10,&val))
    {
        printf("尝试获取第10个元素: 位置不合法\n");
    }

    //4.查找不存在的值
    searchVal = 100;
    if(!LocateElem(L,searchVal))
    {
        printf("未找到值为%d的元素\n",searchVal);
    }

    //销毁顺序表
    DestroyList(&L);
    return 0;
}


