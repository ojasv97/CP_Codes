#include<stdio.h>
#include<limits.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}node;
void inorder(node *root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
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

void delete_BST(node** root){
    if((*root)->left!=NULL){
        delete_BST(&((*root)->left));
    }
    if((*root)->right!=NULL){
        delete_BST(&((*root)->right));
    }
    printf("%d ",(*root)->data);
    free(*root);
    *root=NULL;
    return;
}
int main(){
    int i=0;
    node* root = NULL;
	int arr[100];
	char sep;
    printf("Enter the elements of the tree as space seperated integers.\n");
	while(scanf("%d%c",&arr[i],&sep)){
        i++;
        if(sep!=' ')
            break;
    }
    for(int j=0;j<i;j++){
        insert(&root,arr[j]);
    }
    printf("The inorder traversal is\n");
    inorder(root);
    printf("\n");
    printf("The sequence of deletion is\n");
    delete_BST(&root);
    printf("\nAfter deletion\n");
    if(root==NULL){
        printf("Empty\n");
    }
    else{
        inorder(root);
    }
    return 0;
}