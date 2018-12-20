/*create sequence stack,implement basic functions,exp push,pop,empty,full,top */

#include<iostream>
#include<malloc.h>
using namespace std;
#define MAXSIZE 15

typedef struct stack
{
    int *data;
    int top;
}Stack,*arrayStack;
int realsize = MAXSIZE;
arrayStack Init(arrayStack s)
{
    s->data = (int*)malloc(sizeof(int)*MAXSIZE);
    s->top = -1;
    return s;
}
bool Empty(arrayStack s)
{
    if(s->top == -1)
        return true;
    else
        return false;
}
arrayStack Full(arrayStack s)
{
    if(s->top == realsize-1)
    {
        printf(" full stack,allocate more memory \n!");
        realsize = realsize*1.5;
        s->data =(int*)realloc(s->data,sizeof(int)*realsize);
        /*realloc 更改以前分配区的长度(增加或减少);
         当增加长度时，可能需将以前分配区的内容移到另一个足够大的区域，而新增区域内的初始值则不确定*/
    }
    else
        printf(" hava enough memory!\n");
    return s;
}
arrayStack Push(arrayStack s,int element)
{
    Full(s);
    s->top++;
    s->data[s->top] = element;
    return s;
}
arrayStack Pop(arrayStack s)
{
    if(!Empty(s))
        s->top--;
    else
        printf("empty stack");
    return s;
}
int Top(arrayStack s)
{
    if(!Empty(s))
        return s->data[s->top];
    else
    {
        printf(" empty stack");
        return -1;
    }
}
arrayStack Destroy(arrayStack s)
{
    s->top = -1;
    free(s->data);//释放堆上内存
    return s;
}
int main()
{
    Stack *s = new Stack;
    printf("--------create stack----------\n");
    s=Init(s);
    printf("----------init stack--------\n");
    for(int i = 0;i<MAXSIZE;i++){
        printf("push the %d element is %d\n",i+1,i);
        s=Push(s,i);
    }
    printf("-----element&&popstack-----\n");
    printf("%d\n",Top(s));
    s=Pop(s);
    printf("%d\n",Top(s));
    s=Pop(s);

    return 0;

}
