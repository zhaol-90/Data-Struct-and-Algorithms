#include <iostream>
#include <malloc.h>
using namespace std;

/*create a node struct*/
typedef struct ListNode
{
    int val;
    ListNode *next;
}Node,*PNode;

/*create a loop linked list*/
PNode CreateCircleList(int len,int index)
{
    int val;
    PNode PHead  =(PNode)malloc(sizeof(Node));
    PNode PTail =PHead;
    PTail->next = NULL;
    //    Node *tmp = new Node;
    PNode tmp;

    for(int i = 0;i<len;i++){
        PNode PNew = (PNode)malloc(sizeof(Node));
        if(i+1 == index){
            tmp = PNew;
        }
        printf("the val of the %d node :",i+1);
        scanf("%d",&val);

        PNew->val = val;
        PTail->next = PNew;
        PNew->next = NULL;
        PTail = PNew;
    }
    PTail->next = tmp;
    return PHead;
}
/*display created linked list*/
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
/*main topic*/
int existLoop(PNode List){
    PNode slow;
    PNode fast;
    fast = slow = List;
    int num = 0;
    int flag = 1;
    /*judge exist loop*/
    while(slow !=NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            flag = 0;
            printf("1111111\n");
            break;
        }
    }
    if(flag){
        printf("000000\n");
        return false;
    }
    else{
        fast = List;
        /*find the meeting node*/
        while(slow !=NULL && fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
            if(fast == slow){
                return num+1;
            }
            num++;
        }
        return true;
    }
}
int main()
{
    PNode List = CreateCircleList(7,3);
    //    TraverseList(List);
    printf("%d\n",existLoop(List));
    return 0;
}
/*reference https://www.cnblogs.com/dancingrain/p/3405197.html*/
