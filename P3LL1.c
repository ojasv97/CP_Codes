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
node* insert_at_begin(node* head,int data){
    if(head==NULL){
        node* temp;
        temp = (node*)malloc(sizeof(struct node));
        temp->data=data;
        temp->next=NULL;
        print(head);
        free(temp);
        temp=NULL;
    }
    else{
        node* temp;
        temp = (node*)malloc(sizeof(struct node));
        temp->data=data;
        temp->next=head;
        head = temp;
        print(head);
        head = temp->next;
        free(temp);
        temp=NULL;
    }
    return head;
}
node* insert_at_end(node* head,int data){
    if(head==NULL){
        node* temp;
        temp = (node*)malloc(sizeof(struct node));
        temp->data=data;
        temp->next=NULL;
        print(head);
        free(temp);
        temp=NULL;    
    }
    else{
        node* temp=head;
        while(temp->next!=NULL){temp=temp->next;}
        node* new;
        new = (node*)malloc(sizeof(struct node));
        new->data=data;
        new->next=NULL;
        temp->next = new;
        print(head);
        free(new);
        new=NULL;
        temp->next=NULL;
    }
    return head;
}
node* insert_at_k(node* head,int data,int k){
    if(head==NULL){
        if(k==1){
            node* temp;
            temp = (node*)malloc(sizeof(struct node));
            temp->data=data;
            temp->next=NULL;
            print(head);
            free(temp);
            temp=NULL;
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
            node* new;
            new = (node*)malloc(sizeof(struct node));
            new->data=data;
            if(i==1){
                new->next=temp;
                print(head);
                head=temp;
                free(new);
                new=NULL;
            }
            else{
                new->next=temp;
                prev->next = new;
                print(head);
                prev->next=temp;
                free(new);
                new=NULL;    
            }
        }
        else{
            printf("Unable to reach k.");
        }
    }
    return head;
}
int main(){
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
    int data,k;
    scanf("%d %d",&data,&k);
    node1 = insert_at_begin(node1,data);
    node1 = insert_at_end(node1,data);
    node1 = insert_at_k(node1,data,k);
    return 0;
}