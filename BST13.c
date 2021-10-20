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

void delete_leaves(node* root){
    if(root->left!=NULL && (root->left->left==NULL && root->left->right==NULL)){
        free(root->left);
        root->left=NULL;
    }
    if((root->right!=NULL) && (root->right->left==NULL && root->right->right==NULL)){
        free(root->right);
        root->right=NULL;
    }
    if(root->left!=NULL){
        delete_leaves(root->left);
    }
    if(root->right!=NULL){
        delete_leaves(root->right);
    }
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
    inorder(root);
    delete_leaves(root);
    printf("\n");
    inorder(root);
    return 0;
}