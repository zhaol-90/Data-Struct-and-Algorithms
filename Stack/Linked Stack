#include <iostream>
using namespace std;
/* head->NULL;
 * head->insert->NULL;
 * head->insert1->insert->NULL;
 *为了保持栈的后进先出的特点，并已知栈的头结点；
 * 插入新结点的方法是向前插入，在头结点后面插入；
*/
typedef struct Node
{
    int data;
    struct Node* next;
}Node,*PNode;

int count = 0;
Node *head;
void init()
{
    head = new Node;
    head->next = NULL;
}
bool empty()
{
    if(head->next == NULL) return 0;
    else return 1;
}
/*入栈*/
void push(int data)
{
    Node *insertPtr = new Node;
    if(insertPtr !=NULL){
        insertPtr->data =data;
        insertPtr->next = head->next;
        head->next = insertPtr;
        count++;
    }
}
int peek()//查看栈顶元素，不删除
{
    if(count !=0 && head->next != NULL)
    {
        return head->next->data;
    }
    else
        return -1;
}
void pop()
{
    Node *temp = head->next;
    printf("delete %d\n",temp->data);
    head->next = head->next->next;
    delete temp;
    count--;
}
void TraveseList()
{
    PNode p = head->next;
    while(p!=NULL)
    {
        printf("%d\n",p->data);
        p = p->next;
    }
    printf("\n");
}
int main()
{
    init();
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    TraveseList();
    pop();
    pop();
    TraveseList();
    return 0;
}
