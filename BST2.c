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
    printf("%d ",root->data);
    inorder(root->right);
}
void preorder(node *root){
    if(root==NULL){
        return;
    }
    printf("%d_",root->data);
    preorder(root->left);
    preorder(root->right);
}void postorder(node *root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d_",root->data);
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
    printf("Output\n");
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    return 0;
}