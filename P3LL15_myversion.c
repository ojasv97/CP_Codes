#include<stdio.h>
#include<limits.h>
#include<conio.h>
#include<stdlib.h>
typedef struct node{
    int val;
    struct node* next;
}n;
void print(n* start){
    n* temp=start;
    while(temp!=NULL)
    {
        printf("|%d| ->",temp->val);
        temp=temp->next;
    }
    printf("NULL\n");
}
void insert(n** start,int data)
{
    n* newnode=(n*)malloc(sizeof(n));
    newnode->val=data;
    newnode->next=NULL;
    if(*start==NULL)
    {
        *start=newnode;
        return;
    }
    n* temp=*start;

    while(temp->next!=NULL)
    temp=temp->next;

    temp->next=newnode;
}
void remove_(n** head){
    n* prev;
    n* temp1 = *head;
    n* temp2;
    int flag=0;
    while(temp1!=NULL){
        flag=0;
        temp2 = temp1->next;
        while(temp2!=NULL){
            if(temp2->val>temp1->val){
                flag=1;
                if(temp1==*head){
                    *head = temp1->next;
                    free(temp1);
                    temp1 = *head;
                    
                }
                else{
                    prev->next = temp1->next;
                    free(temp1);
                    temp1 = prev->next;
                }
                break;
            }
            else{
                temp2 = temp2->next;
            }
        }
        if(flag==0){
            prev = temp1;
            temp1 = temp1->next;
        }
    }
}
int main(){
    n* start=NULL;
    printf("Enter the number of elements\n");
    int n;
    scanf("%d",&n);
    int i=0;
    int temp;
    printf("Enter the elements as space seperated integers\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&temp);
        insert(&start,temp);
    }
    remove_(&start);
    print(start);
    return 0;
}