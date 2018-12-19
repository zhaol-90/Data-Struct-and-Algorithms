#include <iostream>
#include <malloc.h>
using namespace std;

typedef struct ListNode
{
    int val;
    ListNode *next;
}Node,*PNode;

/*create a linked list with n node*/
PNode CreateList(int len)
{
    int val;
    PNode PHead =(PNode)malloc(sizeof(Node));
    PNode PTail = PHead;
    PTail->next = NULL;
    for(int i = 0;i<len;i++)
    {
        PNode PNew = (PNode)malloc(sizeof(Node));
        printf("the val of the %d node:",i+1);
        scanf("%d",&val);

        PNew->val = val;
        PTail->next = PNew;
        PNew->next = NULL;
        PTail = PNew;
    }
    return PHead;/*return the head of linked list*/
}
/*show linked list*/
void TraverseList(PNode List)
{
    PNode p = List->next;
    while(p != NULL)
    {
        printf("%d  ",p->val);
        p = p->next;
    }
    printf("\n");
}

/*reverse linked list in original linked list */
PNode reverse(PNode List)
{
    if(List == NULL || List->next == NULL)
        return List;
    PNode dummy =List;
    PNode prev = dummy->next;
    PNode pcur = prev->next;

    while(pcur != NULL)
    {
        prev->next = pcur->next;
        pcur->next = dummy->next;
        dummy->next = pcur;
        pcur = prev->next;
    }
    return dummy;
}

/*reverse linked list with new linked list*/
PNode reverse_new(PNode List)
{
    if(List == NULL || List->next == NULL) return List;
   
    /*Node *dummy =new Node;
    dummy->next = NULL;*/

    /* or */
    PNode dummy = (PNode)malloc(sizeof(Node));
    dummy->next = NULL;

    PNode pcur = List->next;
    while(pcur != NULL)
    {
        /*shared address，dont apply new address,I think*/
        PNode pNext = pcur->next;
        pcur->next = dummy->next;
        dummy->next = pcur;
        pcur = pNext;
    }
    return dummy;
}
int main()
{
    PNode List = CreateList(3);
    TraverseList(List);
    PNode reverse_List= reverse(List);
    TraverseList(reverse_List);

    PNode reverse_List_2 = reverse_new(reverse_List);
    TraverseList(reverse_List_2);
    return 0;

}
