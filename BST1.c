#include<stdio.h>
#include<limits.h>
#include<conio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}node;

void insert(node** root,int val){
    if(*root == NULL){
        node* temp = (node*)malloc(sizeof(node));
        temp->data=val;
        temp->left=NULL;
        temp->right=NULL;
        *root = temp;
    }
    else if((*root)->data>val){
        insert(&((*root)->left),val);
    }
    else if((*root)->data<val){
        insert(&((*root)->right),val);
    }
}
void inorder(node *root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    printf("%d",root->data);
    inorder(root->right);
}
int search(node* root, int val){
    int v;
    if(root==NULL){
        return 0;
    }
    if(root->data == val){
        return 1;
    }
    else if(root->data>val){
        v = search(root->left,val);
    }
    else if(root->data<val){
        v = search(root->right,val);
    }
    return v;
}
int main(){
    int n;
    scanf("%d",&n);
    int v;
    node* root = NULL;
    for(int i=0;i<n;i++){
        scanf("%d",&v);
        insert(&root,v);
    }
    int k;
    scanf("%d",&k);
    int o;
    int s[100];
    for(int i=0;i<k;i++){
        scanf("%d",&s[i]);
    }
    for(int i=0;i<k;i++){
        o = search(root,s[i]);
        if(o==1){
            printf("y\n");
        }
        else{
            printf("n\n");
        }
    }
}