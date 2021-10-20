#include<stdio.h>
#include<limits.h>
#include<conio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* next;
}node;

void print(node* head){
    node* temp = head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
node* delete_at_begin(node* head){
    if(head==NULL){
        printf("Linked list is empty");
    }
    else if(head->next==NULL){
        free(head);
        printf("Now the list doesnt have any node.");
    }
    else{
        node* temp;
        temp=head;
        head = head->next;
        free(temp);
        temp=NULL;
        print(head);
    }
    return head;
}
node* delete_at_end(node* head){
    if(head==NULL){
        printf("Linked list is empty");
    }
    else if(head->next==NULL){
        free(head);
        printf("Now the list doesnt have any node.");
    }
    else{
        node* temp=head;
        node* prev;
        while(temp->next!=NULL){prev = temp;temp= temp->next;}
        free(temp);
        prev->next=NULL;
        print(head);
    }
    return head;
}
node* delete_at_k(node* head,int k){
    if(head==NULL){
        printf("Linked list is empty");
    }
    else if(head->next==NULL){
        if(k==1){
            free(head);
            printf("Now the list doesnt have any node.");
        }
        else{ 
            printf("Unable to reach k.");
        }
    }
    else{
        node* temp=head;
        node* prev;
        int i=1;
        while(temp->next!=NULL && i<k){prev = temp;temp=temp->next;i++;}
        if(i==k){
            if(i==1){
                delete_at_begin(head);
            }
            else{
                prev->next = temp->next;
                free(temp);
                temp=NULL;
                print(head);   
            }
        }
        else{
            printf("Unable to reach k.");
        }
    }
    return head;
}
node* create_linkedlist(){
    node* node1 = (node*)malloc(sizeof(node));
    node* node2 = (node*)malloc(sizeof(node)); 
    node* node3 = (node*)malloc(sizeof(node)); 
    node* node4 = (node*)malloc(sizeof(node)); 
    node* node5 = (node*)malloc(sizeof(node)); 
    node1->data=1;
    node1->next=node2;
    node2->data=2;
    node2->next=node3;
    node3->data=5;
    node3->next=node4;
    node4->data=7;
    node4->next=node5;
    node5->data=4;
    node5->next=NULL;
    return node1;
}
int main(){
    int k;
    scanf("%d",&k);//Enter k.
    node* node1;
    node1 = create_linkedlist();
    node1 = delete_at_begin(node1);
    node1 = create_linkedlist();
    node1 = delete_at_end(node1);
    node1 = create_linkedlist();
    node1 = delete_at_k(node1,k);
    return 0;
}